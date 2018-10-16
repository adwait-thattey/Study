clc
clear

t = -10:0.01:10;

y = q6Func(t);
subplot(3,2,[1:2]);
plot(t,y);
grid on;
title('x(t)');
xlabel('t');
ylabel('x');
ylim([-2,2]);
xticks(-10:1:10);

y = q6Func(t-1);
subplot(3,2,3);
plot(t,y);
grid on;
title('x(t-1)');
xlabel('t');
ylabel('x');
ylim([-2,2]);
xticks(-10:1:10);

y = q6Func(t+1);
subplot(3,2,4);
plot(t,y);
grid on;
title('x(t+1)');
xlabel('t');
ylabel('x');
ylim([-2,2]);
xticks(-10:1:10);

y = q6Func(2*t - 3);
subplot(3,2,5);
plot(t,y);
grid on;
title('x(2t - 3)');
xlabel('t');
ylabel('x');
ylim([-2,2]);
xticks(-10:1:10);

y = q6Func(1 - 2*t);
subplot(3,2,6);
plot(t,y);
grid on;
title('x(1 - 2t)');
xlabel('t');
ylabel('x');
ylim([-2,2]);
xticks(-10:1:10);