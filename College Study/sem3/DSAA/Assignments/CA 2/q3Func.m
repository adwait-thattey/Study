function [x1,h] = q3Func(n,shift1,scale1,shift2,scale2)
    x1 = zeros(size(n));
    h = zeros(size(n));

    n1 = ( n + ( shift1/scale1 )) * scale1;
    n2 = ( n + ( shift2/scale2 )) * scale2;

    x1(n1==0) = 1;
    x1(n1==1) = -2;
    x1(n1==2) = 3;
    x1(n1==3) = -8;
    x1(n1==4) = 9;  
    h(n2==0) = 1;
    h(n2==1) = 2;
    h(n2==2) = 3;
    h(n2==3) = 2;
    h(n2==4) = 1;
return