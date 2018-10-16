clc
clear

p = -20:0.001:20;

y = CA_Q3_Func(p - 5) - CA_Q3_Func(p - 10);
subplot(2,2,1);
plot(p,y);
ylim([-2 2]);
xlabel('x');
ylabel('y');
xticks(-20:2:20);
grid on;

y = CA_Q3_Func(2 - p) - CA_Q3_Func(6 - p);
subplot(2,2,2);
plot(p,y);
ylim([-2 2]);
xlabel('x');
ylabel('y');
xticks(-20:2:20);
grid on;

y = CA_Q3_Func(7 - p);
subplot(2,2,3);
plot(p,y);
ylim([-2 2]);
xlabel('x');
ylabel('y');
xticks(-20:2:20);
grid on;



