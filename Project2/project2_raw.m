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
[centers, radii, metric] = imfindcircles(img,[15 30]);

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
    angles(i) = atan2(circCenter(2)-centers(i,2),circCenter(1)-centers(i,1));
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

%scale the colors so at least one value is 255
finalColors = (circTrip ./ max(max(circTrip))) .* 255;
%preallocate
finalSums = zeros(length(finalColors(:,1)),1);
for i = 1 : length(finalColors(:,1))
    %sum colors
    finalSums(i) = sum(finalColors(i,:));
end

%preallocate
finalColorString = strings(length(finalColors(:,1)), 1);
for i = 1 : length(finalColors(:,1))
    %determine color
    if finalSums(i) > 700
        finalColorString(i) = 'w';
    elseif finalSums(i) > 500
        finalColorString(i) = 'y';
    elseif finalSums(i) > 400
        finalColorString(i) = 'b';
    elseif finalSums(i) > 300
        finalColorString(i) = 'r';
    else
        finalColorString(i) = 'g';
    end
end

%print out angle and color
for i = 1 : length(finalColors(:,1))
    fprintf("Angle: %f Color: %s\n", degAngles(i), finalColorString(i));
end
