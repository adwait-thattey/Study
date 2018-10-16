clc
clear
t = -15:0.01:15;

y = q4Func(t);
subplot(2,2,1);
plot(t,y);
grid on;
title('r(t)');
xlabel('t');
ylabel('y');
ylim([-1,20]);
xticks(-20:2:20);


y = q4Func(t - 3);
subplot(2,2,2);
plot(t,y);
grid on;
title('r(t - 3)');
xlabel('t');
ylabel('y');
ylim([-1,20]);
xticks(-20:2:20);

y = q4Func(7 - t);
subplot(2,2,3);
plot(t,y);
grid on;
title('r(7 - t)');
xlabel('t');
ylabel('y');
ylim([-1,20]);
xticks(-20:2:20);

y = q4Func(1 - 3*t);
subplot(2,2,4);
plot(t,y);
grid on;
title('r(1 - 3t)');
xlabel('t');
ylabel('y');
ylim([-1,20]);
xticks(-20:2:20);