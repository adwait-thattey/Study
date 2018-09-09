clc
clear

t = -4:0.001:4;

y = CA_Q8_Func(t,0,1);
z = CA_Q8_Func(t,2,1);
w = CA_Q8_Func(t,-2,1);


plot(t,y);
hold on;
plot(t,z);
hold on;
plot(t,w);
hold off;
