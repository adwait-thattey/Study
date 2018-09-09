clc
clear

p = -5:0.1:6;

y = CA_Q7_Func(p);

subplot(3,2,1);
stem(p,y);
ylim([-1 10]);
xlim([-5 6]);
xlabel('x','FontSize',25);
ylabel('x[n]','FontSize',20);


y = CA_Q7_Func(p-1);

subplot(3,2,2);
stem(p,y);
ylim([-1 10]);
xlim([-5 6])
xlabel('x','FontSize',25);
ylabel('x[n - 1]','FontSize',20);



y = CA_Q7_Func(p+2);

subplot(3,2,3)
stem(p,y)
ylim([-1 10])
xlim([-5 6])
xlabel('x','FontSize',25);
ylabel('x[n + 2]','FontSize',20);


y = CA_Q7_Func(2-p);

subplot(3,2,4)
stem(p,y)
ylim([-1 10])
xlim([-5 6])
xlabel('x','FontSize',25);
ylabel('x[2 - n]','FontSize',20);

y = CA_Q7_Func(1 - 2*p);

subplot(3,2,5)
stem(p,y)
ylim([-1 10])
xlim([-5 6])
xlabel('x','FontSize',25);
ylabel('x[1 - 2n]','FontSize',20);

y = CA_Q7_Func(2*p + 3);

subplot(3,2,6)
stem(p,y)
ylim([-1 10])
xlim([-5 6])
xlabel('x','FontSize',25);
ylabel('x[2n + 3]','FontSize',20);



