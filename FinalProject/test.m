close all
clc
clear
clear('cam')

webcamlist;
cam = webcam(1);
cam.Resolution = '640x480';
preview(cam);
pause(5);
%img = imread('output1.png'); %delete
%imshow(img) %delete
%img = imresize(img,[480 640]); %delete

imshow(img)
imgBase = img;

for c = 1 : 480
    for r = 1 : 640
        if img(c, r, 1) > 245
            img(c, r, 1) = 0;
            img(c, r, 2) = 0;
            img(c, r, 3) = 0;
        else
            img(c, r, 1) = 255;
            img(c, r, 2) = 255;
            img(c, r, 3) = 255;
        end
    end
end

figure
imshow(imgBase)

figure
imshow(img)

% img=im2bw(img);
% img=~img;
% img=bwareaopen(img,1000);
%Find circles
% [centers, radii, metric] = imfindcircles(img,[6 600],'ObjectPolarity','bright', 'Method', 'TwoStage', 'Sensitivity', 0.92);
[centers, radii, metric] = imfindcircles(img,[6 600],'ObjectPolarity','dark', 'Method', 'TwoStage', 'Sensitivity', 0.93);

circCenterX = (max(centers(:,1))+min(centers(:,1)))/2;
circCenterY = (max(centers(:,2))+min(centers(:,2)))/2;
circCenter = [circCenterX, circCenterY];

angles = zeros(1,length(centers(:,1)));
circColors = zeros(1,length(centers(:,1)),3);

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

%convert the angle from radians to degrees
degAngles = rad2deg(angles);

fig=uifigure('Name','Click to Point', 'Position', [0 0 640 480]);
pnl = uipanel(fig, 'BackgroundColor', 'white', 'Position',[0 0 640 480]);

firebtn = uibutton(pnl,'push','Position',[280 300 100 100],'Text','Fire','FontSize',20,'ButtonPushedFcn', @(btn,event) pointToAngle(btn, degAngles(i)));


function pointToAngle(firebtn, angleIn)
  %  fprintf("change simulink angle to %f\n", angleIn);
    set_param("motor_model_updated_F21/desiredPosition", "Value", string(-angleIn));
    set_param("fireTest/pinState","Value","1");

end


