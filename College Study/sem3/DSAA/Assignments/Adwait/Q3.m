clear
clc

t = -15:0.001:15;

y = q3Func(t);
subplot(2,2,1);
plot(t,y);
grid on;
title('u(t)');
xlabel('t');
ylabel('y');
ylim([-1,2]);
xticks(-15:5:15);


y = q3Func(t - 5) - q3Func(t - 10);
subplot(2,2,2);
plot(t,y);
grid on;
title('u(t-5) - u(t-10)');
xlabel('t');
ylabel('y');
ylim([-1,2]);
xticks(-15:5:15);


y = q3Func(2 - t) - q3Func(6 - t);
subplot(2,2,3);
plot(t,y);
grid on;
title('u(2 - t) - u(6 - t)');
xlabel('t');
ylabel('y');
ylim([-1,2]);
xticks(-14:2:14);

y = q3Func(7 - t);
subplot(2,2,4);
plot(t,y);
grid on;
title('u(7 - t)');
xlabel('t');
ylabel('y');
ylim([-1,2]);
xticks(-14:3.5:14);