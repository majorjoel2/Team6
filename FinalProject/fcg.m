close all
clc
clear
clear('cam')

set_param("fireTest", "SimulationCommand", "start")

fig=uifigure('Name','Click to Point', 'Position', [0 0 640 480]);
pnl = uipanel(fig, 'BackgroundColor', 'white', 'Position',[0 0 640 480]);

firebtn = uibutton(pnl,'push','Position',[280 300 100 100],'Text','Fire','FontSize',20,'ButtonPushedFcn', @(btn,event) pointToAngle(btn, 0));
exitbtn = uibutton(pnl, 'Position', [590 430 50 50], 'BackgroundColor', 'white', 'Text', 'Exit', 'ButtonPushedFcn', @(btn,event) exitBtnFn(btn, 0));

function exitBtnFn(btn, angleIn)
    set_param("fireTest", "SimulationCommand", "stop")
end

function pointToAngle(btn, angleIn)
    set_param("fireTest/pinState","Value","1");
    pause(1);
    set_param("fireTest/pinState","Value","0");
end