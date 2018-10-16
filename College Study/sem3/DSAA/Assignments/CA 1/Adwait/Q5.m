clc
clear

omega0 = pi;
t0 = pi/2;

t = -2*pi:0.01:2*pi;

y = sin(omega0*(t - t0));
subplot(2,1,1);
plot(t,y);
grid on;
title('sin(Ω0(t − t0 )) {Ω0 = pi, t0 = pi/2 } ');
xlabel('x');
ylabel('t');
ylim([-1.5,1.5]);
xticks(-3*pi:pi/2:3*pi);

y = sin(omega0*(t + t0));
subplot(2,1,2);
plot(t,y);
grid on;
title('sin(Ω0(t + t0 )) {Ω0 = pi, t0 = pi/2 } ');
xlabel('x');
ylabel('t');
ylim([-1.5,1.5]);
xticks(-3*pi:pi/2:3*pi);