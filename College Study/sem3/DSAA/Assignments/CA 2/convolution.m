function y = Convolution(x,h)
    A = max( size(x) );
    B = max( size(h) );
    len = A + B - 1;
    y = zeros( [1,len] );
    Xe = zeros( [1,len] );
    He = zeros( [1,len] );
    Xe(1:A) = x;
    He(1:B) = h;
    
    for i=1:max( size(y) )
        for j=1:i
            y(i) = y(i) + Xe(j) .* He((i + 1) - j);
        end
    end
return
    