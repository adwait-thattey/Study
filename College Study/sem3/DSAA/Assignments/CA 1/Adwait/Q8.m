clear
clc

t = -3:0.01:3;

y1 = q8Func(t,0,1);
y2 = q8Func(t,2,1);
y3 = q8Func(t,-2,1);


plot(t,y1);
grid on;
xticks(-3:0.5:3)
hold on;
plot(t,y2);
hold on;
plot(t,y3);
hold off;