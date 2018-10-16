function y = CA_Q7_Func(t)
y = zeros(size(t));
y(t==0) = 1;
y(t==1) = 2;
y(t==2) = 3;
y(t==3) = 8;
y(t==4) = 9;
return;