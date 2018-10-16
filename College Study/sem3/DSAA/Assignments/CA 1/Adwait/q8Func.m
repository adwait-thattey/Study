function y = q8Func(t,shifter,scaler)

    zoomed = shifter/scaler;
    z = t + zoomed;
    z = z * scaler;
    t = z;
    
    y = t;
    y(t > -1 & t < 0) = 1 + y(t > -1 & t < 0);
    y(t > 0 & t < 1) = 1 - y(t > -1 & t < 0);
    y(t <= -1 | t >= 1) = 0;
    return;