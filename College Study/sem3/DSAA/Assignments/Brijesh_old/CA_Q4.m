clc
clear

n = -10:0.001:10;


y = ((sign(n-3) + 1)/2).*(n-3);
subplot(2,2,1);
plot(n,y,'Linewidth',3);
ylim([-5 15]);
ylabel('Amplitude');
xlabel('Time');
title('Ramp Signal r(t - 3)');



y = ((sign(7-n) + 1)/2).*(7-n);
subplot(2,2,2);
plot(n,y,'Linewidth',3);
ylim([-5 15]);
ylabel('Amplitude');
xlabel('Time');
title('Ramp Signal r(7 - t)');


y = ((sign(1-3.*n) + 1)/2).*(1-3.*n);
subplot(2,2,3);
plot(n,y,'Linewidth',3);
ylim([-5 15]);
ylabel('Amplitude');
xlabel('Time');
title('Ramp Signal r(1 - 3t)')




