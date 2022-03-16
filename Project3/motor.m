%Clear everything
close all
clc
clear
clear('cam')

%start cam and take a picture
webcamlist;
cam = webcam(2);
cam.Resolution = '640x480';
preview(cam);
pause(5);
img = snapshot(cam);
imshow(img)

%Find circles
[centers, radii, metric] = imfindcircles(img,[15 40]);

%add blue circles around the found circles
viscircles(centers, radii,'EdgeColor','b');

%find center of the circles
%circCenter = mean(centers)
circCenterX = (max(centers(:,1))+min(centers(:,1)))/2;
circCenterY = (max(centers(:,2))+min(centers(:,2)))/2;
circCenter = [circCenterX, circCenterY];

%draw a red circle at the center
viscircles(circCenter, 10, 'EdgeColor', 'r');

%preassign memory for variables (helps runtime speed)
angles = zeros(1,length(centers(:,1)));
circColors = zeros(1,length(centers(:,1)),3);

%Make a mesh grid for image
[x, y] = meshgrid(1:size(img,2), 1:size(img,1));

for i = 1:length(centers(:,1))
    %draw lines to all of the circles
    line([circCenter(1) centers(i,1)], [circCenter(2) centers(i,2)], 'Color', 'b');
    %calculate angle in radians of each of the circles
    angles(i) = atan2(circCenter(2)-centers(i,2),centers(i,1)-circCenter(1));
    %create circle mask to only look at inside 50% of circle
    mask = (x-centers(i,1)).^2 + (y-centers(i,2)).^2 < floor(radii(i)*0.5).^2;
    %get average r, g, and b of circle inside
    circColors(1,i,:) = sum(sum(double(img) .* mask)) / sum(mask(:));
    if abs(rad2deg(angles(i))) < 10
        %mark 0 degree
        line([circCenter(1) centers(i,1)], [circCenter(2) centers(i,2)], 'Color', 'r');
    end
end

%convert the angle from radians to degrees
degAngles = rad2deg(angles);

%preallocate for new color array
circTrip = zeros(length(circColors(1,:,1)),3);
for i = 1 : length(circColors(1,:,1))
    %make rgb trips
    circTrip(i,:) = [circColors(1,i,1), circColors(1,i,2), circColors(1,i,3)];
end
%make half radius
newRad = radii ./ 2;
%make rgb trips to matlab form
newColors = circTrip ./ 255;

for i = 1 : length(circColors(1,:,1))
    %print circles to picture
    viscircles(centers(i,:), newRad(i),'Color', newColors(i,:));
end

set_param("motor_model_updated_F21", "SimulationCommand", "start")

fig = uifigure('Name', 'Click to Point', 'Position', [0 0 640 480]);
pnl = uipanel(fig, 'BackgroundColor', [1 1 1], 'Position', [0 0 640 480]);

for i = 1 : length(circColors(1,:,1))
    btn(i) = uibutton(pnl, 'Position', [centers(i,1)-radii(i) 480-(centers(i,2)-radii(i)) radii(i)*2 radii(i)*2], 'BackgroundColor', newColors(i,:), 'Text', '', 'ButtonPushedFcn', @(btn,event) pointToAngle(btn, degAngles(i)));
end

exitbtn = uibutton(pnl, 'Position', [590 430 50 50], 'BackgroundColor', 'white', 'Text', 'Exit', 'ButtonPushedFcn', @(btn,event) pointToAngle(btn, 0));

function pointToAngle(btn, angleIn)
    fprintf("change simulink angle to %f\n", angleIn);
    set_param("motor_model_updated_F21/desiredPosition", "Value", string(-angleIn))
end


