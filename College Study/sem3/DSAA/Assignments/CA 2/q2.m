clear;
clc;

n = -10:1:10;
[x,h] = q2Func(n);

y = convolution(x, h);
y_inbuilt = conv(x, h);

isequal(y, y_inbuilt)

subplot(3,1,1)
stem(n,x)
title("x")
xticks(-10:2:10)
yticks(0:1:5)

subplot(3,1,2)
stem(n,h)
title("h")
xticks(-10:2:10)
yticks(0:1:5)

subplot(3,1,3)
stem(y)
title("y")
