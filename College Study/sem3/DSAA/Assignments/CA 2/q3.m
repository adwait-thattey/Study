clc;
clear;

n = -10:1:10;
[x , h] = q3Func(n,0,1,0,-1);
[x1, h1] = q3Func(n,2,-1,0,1);

y1 = convolution(x, h);
y2 = convolution(x1, h1);

y1_inbuilt = conv(x, h);
y2_inbuilt = conv(x1, h1);

isequal(y1, y1_inbuilt) && isequal(y2, y2_inbuilt)

subplot(4,1,1)
stem(n,x)
title("x")
xticks(-10:2:10)
yticks(-15:5:15)

subplot(4,1,2)
stem(n,h)
title("h")
xticks(-10:2:10)
yticks(-5:1:5)

subplot(4,1,3)
stem(y1)
title("y1")

subplot(4,1,4)
stem(y2)
title("y2")
