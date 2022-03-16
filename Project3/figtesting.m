close all
clc
clear

newColors = [[0.720004117132417	0.690895990942309	0.237815861252638];
[0.216938279269491	0.436701329608360	0.274985772673185];
[0.671719789237281	0.196190722985229	0.190247905329533];
[0.712632738488654	0.725102445472571	0.674280678563560];
[0.702135762441460	0.728011939684010	0.719129226493747];
[0.708664408171646	0.734390719638641	0.702617801047121];
[0.672813054581656	0.698047872570662	0.683426394840497];
[0.285314977054652	0.520202336253650	0.663037129745515];
[0.715101934813661	0.730104315456867	0.702878414058780];
[0.704602902168825	0.726894471316378	0.679284339730587]];

radii = [23.2264709228640
23.9061671035440
24.7313762847724
24.5892970796435
23.6434190400016
23.4498908200965
24.4285421044004
23.9656355534947
25.2992323374167
23.3701298148327];

centers = [[324.700817737334	399.210362180211];
[197.100346653858	190.120102550630];
[320.762838030171	113.819682235844];
[247.971667375860	136.088647380188];
[400.437082957896	378.258169692033];
[219.680836217175	353.714674126200];
[468.540153078079	257.065351635386];
[447.999394654650	327.116843899734];
[422.861648885452	150.661944058197];
[181.419330187987	260.991226421856]];

degAngles = [-90.1119948393447	152.561682609945	91.6927005628938	122.597364246646	-58.2090461566772	-137.290415463241	-0.219638539337435	-29.8518093794519	47.2405657028665	-178.214099946129];

fig = uifigure('Name', 'Click to Point', 'Position', [0 0 640 480]);
pnl = uipanel(fig, 'BackgroundColor', [1 1 1], 'Position', [0 0 640 480]);

for i = 1 : 10
    btn(i) = uibutton(pnl, 'Position', [centers(i,1)-radii(i) 480-(centers(i,2)-radii(i)) radii(i)*2 radii(i)*2], 'BackgroundColor', newColors(i,:), 'Text', '', 'ButtonPushedFcn', @(btn,event) pointToAngle(btn, degAngles(i)));
end

exitbtn = uibutton(pnl, 'Position', [590 430 50 50], 'BackgroundColor', 'white', 'Text', 'Exit', 'ButtonPushedFcn', @(btn,event) pointToAngle(btn, 0));

function pointToAngle(btn, angleIn)
    fprintf("change simulink angle to %f\n", angleIn);
end