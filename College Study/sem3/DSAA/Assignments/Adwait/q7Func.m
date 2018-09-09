function y = q7Func(n)
    y = zeros(size(n));
    y(n==0) = 1;
    y(n==1) = 2;
    y(n==2) = 3;
    y(n==3) = 8;
    y(n==4) = 9;
    return;