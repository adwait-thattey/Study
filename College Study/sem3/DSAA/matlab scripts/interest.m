% computing simple interest
x = 100000; % principal amt
in  = 10; %interest rate per year
cur_mon = input('enter current onth');
interes = x*in/100/12*cur_mon;
total = x + interes;
disp('yourcur_balance:');
disp(total);
disp(x)