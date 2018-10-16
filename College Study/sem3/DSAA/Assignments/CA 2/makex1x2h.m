function [x1, x2, h] = makex1x2h(n)
    
    %{
        x1 = {1, 2, 3, 8, 9}
        x2 = {1, 0, 1, 0}
        h = {1, 2, 3, 2, 1}
    %}
    x1 = zeros(size(n));
    x2 = zeros(size(n));
    h = zeros(size(n));

    x1(n==0) = 1;
    x1(n==1) = 2;
    x1(n==2) = 3;
    x1(n==3) = 8;
    x1(n==4) = 9;

    x2(n==0) = 1;
    x2(n==1) = 0;
    x2(n==2) = 1;
    x2(n==3) = 0;

    h(n==0) = 1;
    h(n==1) = 2;
    h(n==2) = 3;
    h(n==3) = 2;
    h(n==4) = 1;

return