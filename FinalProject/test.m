close all
clc
clear
clear('cam')

webcamlist;
cam = webcam('USB2.0 PC CAMERA');
cam.Resolution = '640x480';
preview(cam);
pause(5);
img = snapshot(cam);
%img = imread('output1.png'); %delete
%imshow(img) %delete
%img = imresize(img,[480 640]); %delete

imgBase = img;

numOfBlackPx = 0;
cSum = 0;
rSum = 0;

for c = 1 : 480
    for r = 1 : 640
        if img(c, r, 1) > 245
            img(c, r, 1) = 0;
            img(c, r, 2) = 0;
            img(c, r, 3) = 0;
            numOfBlackPx = numOfBlackPx + 1;
            cSum = cSum + c;
            rSum = rSum + r;
        else
            img(c, r, 1) = 255;
            img(c, r, 2) = 255;
            img(c, r, 3) = 255;
        end
    end
end

cSum = cSum / numOfBlackPx;
rSum = rSum / numOfBlackPx;

figure
imshow(imgBase)

figure
imshow(img)

viscircles([rSum, cSum], 10,'EdgeColor','b');

turretAngle = 0;
if rSum < 200
    turretAngle = 40;
end
if rSum > 350
    turretAngle = -35;
end

set_param("motor_model_updated_F21", "SimulationCommand", "start")

fig=uifigure('Name','Click to Point', 'Position', [0 0 640 480]);
pnl = uipanel(fig, 'BackgroundColor', 'white', 'Position',[0 0 640 480]);

firebtn = uibutton(pnl,'push','Position',[280 300 100 100],'Text','Fire','FontSize',20,'ButtonPushedFcn', @(btn,event) pointToAngle(btn, turretAngle));
exitbtn = uibutton(pnl, 'Position', [590 430 50 50], 'BackgroundColor', 'white', 'Text', 'Exit', 'ButtonPushedFcn', @(btn,event) exitBtnFn(btn, 0));

function exitBtnFn(btn, angleIn)
    set_param("motor_model_updated_F21/pinState","Value","0");
    set_param("motor_model_updated_F21/desiredPosition", "Value", string(angleIn));
    pause(1);
end

function pointToAngle(btn, angleIn)
    %  fprintf("change simulink angle to %f\n", angleIn);
    if angleIn ~= 0
        set_param("motor_model_updated_F21/desiredPosition", "Value", string(angleIn));
        pause(0.5);
    end
    set_param("motor_model_updated_F21/pinState","Value","1");
end


