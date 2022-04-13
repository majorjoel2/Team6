close all
clc
clear
clear('cam')

webcamlist;
cam = webcam(2);
cam.Resolution = '640x480';
preview(cam);
pause(5);
img = snapshot(cam);
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

%Find circles
[centers, radii, metric] = imfindcircles(img,[6 600],'ObjectPolarity','dark', 'Method', 'TwoStage', 'Sensitivity', 0.01);
