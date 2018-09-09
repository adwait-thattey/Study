function y = CA_Q6_Func(t)

y=t;
y(t<0)=0;
y(t >= 1 & t < 3)=2 -  y(t >= 1 & t < 3);
y(t >= 3 & t < 5)=y(t >= 3 & t < 5)-4;
y(t >= 5)=1;
return;

