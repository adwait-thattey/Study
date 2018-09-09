om0 = 2;
t0 = 2.5;
t = -3*pi:pi/1000:3*pi;


subplot(2,1,1);
plot(t,sin(om0*(t-t0)));

subplot(2,1,2);
plot(t,sin(om0*(t+t0)));
