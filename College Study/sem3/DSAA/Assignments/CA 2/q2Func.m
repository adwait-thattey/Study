function [x,h] = q2Func(n)
    x = zeros(size(n));
    h = zeros(size(n));

    %{
        x = {2, 3, 1, 2, 3} -> on 1
        h = {1, 2, 3, 2, 1} -> on 3
    %}

    x(n==-2) = 2;
    x(n==-1) = 3;
    x(n==0) = 1;
    x(n==1) = 2;
    x(n==2) = 3;
    
    h(n==-2) = 1;
    h(n==-1) = 2;
    h(n==0) = 3;
    h(n==1) = 2;
    h(n==2) = 1;
return