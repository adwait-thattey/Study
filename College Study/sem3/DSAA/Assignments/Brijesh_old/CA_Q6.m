clc;
clear;

p = -08:0.001:08;

y = CA_Q6_Func(p);
subplot(3,2,[1,2]);
plot(p,y,'Linewidth',3);
grid on;
ylim([-1 1]);
xlabel('x');
ylabel('y');

y = CA_Q6_Func(p - 1);
subplot(3,2,3);
plot(p,y,'Linewidth',3);
grid on;
ylim([-1 1]);
xlabel('x');
ylabel('y');

y = CA_Q6_Func(p + 1);
subplot(3,2,4);
plot(p,y,'Linewidth',3);
grid on;
ylim([-1 1]);
xlabel('x');
ylabel('y');

y = CA_Q6_Func(2*p - 3);
subplot(3,2,5);
plot(p,y,'Linewidth',3);
grid on;
ylim([-1 1]);
xlabel('x');
ylabel('y');

y = CA_Q6_Func(1 - 2*p);
subplot(3,2,6);
plot(p,y,'Linewidth',3);
grid on;
ylim([-1 1]);
xlabel('x');
ylabel('y');
