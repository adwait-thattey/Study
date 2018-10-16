function y = CA_Q8_Func(t,shift,scale)

zoomed = shift/scale;
z = t + zoomed;
z = z * scale;
t = z;

y = t;
y(t > -1 & t < 0) = 1 + y(t > -1 & t < 0);
y(t > 0 & t < 1) = 1 - y(t > -1 & t < 0);
y(t <= -1 | t >= 1) = 0;
return;