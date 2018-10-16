clear
clc

n = -6:1:6;

y = q7Func(n);
subplot(2,3,1);
stem(n,y)
grid on;
title('x[n]');
xlabel('n');
ylabel('x');
ylim([-1,10]);
xticks(-6:2:6);
yticks(-1:1:10);

y = q7Func(n - 1);
subplot(2,3,2);
stem(n,y)
grid on;
title('x[n - 1]');
xlabel('n');
ylabel('x');
ylim([-1,10]);
xticks(-6:2:6);
yticks(-1:1:10);

y = q7Func(n + 2);
subplot(2,3,3);
stem(n,y)
grid on;
title('x[n + 2]');
xlabel('n');
ylabel('x');
ylim([-1,10]);
xticks(-6:2:6);
yticks(-1:1:10);

y = q7Func(2 - n);
subplot(2,3,4);
stem(n,y)
grid on;
title('x[2 - n]');
xlabel('n');
ylabel('x');
ylim([-1,10]);
xticks(-6:2:6);
yticks(-1:1:10);


n = -6:0.5:6;

y = q7Func(1 - 2*n);
subplot(2,3,5);
stem(n,y)
grid on;
title('x[1 - 2n]');
xlabel('n');
ylabel('x');
ylim([-1,10]);
xticks(-6:1:6);
yticks(-1:1:10);

y = q7Func(2*n + 3);
subplot(2,3,6);
stem(n,y)
grid on;
title('x[2n + 3]');
xlabel('n');
ylabel('x');
ylim([-1,10]);
xticks(-6:1:6);
yticks(-1:1:10);

