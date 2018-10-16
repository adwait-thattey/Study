clc
clear

t = -10:1:10;

[x1,x2,h] = makex1x2h(t);

%{ results with custom func %}

y1 = convolution(convolution(x1,x2), h);

y1c = conv(conv(x1,x2), h); 

y2 = convolution(convolution(x1,h), x2);

subplot(5,1,1)
stem(t,x1)
title("x1")
xticks(-10:2:10)
yticks(0:2:10)

subplot(5,1,2)
stem(t,x2)
title("x2")
xticks(-10:2:10)
yticks(0:2:10)

subplot(5,1,3)
stem(t,h)
title("h")
xticks(-10:2:10)
yticks(0:2:10)

subplot(5,1,4)
stem(y1)
title("y2")


subplot(5,1,5)
stem(y2)
title("y2")
