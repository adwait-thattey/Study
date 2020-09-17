clear;
clc;

image = imread('Sample_2_1.tif');


[r,c] = size(image);
new = zeros(r + 2, c + 2);
for m = 2 : r + 1
    for n = 2 : c + 1
        new(m,n) = image(m - 1, n - 1);
    end
end


noiseless_image = zeros(r, c);
for x = 1 : r
    for y = 1 : c
        for i = 1 : 3
            for j = 1 : 3
                w = y -1;
                q = x - 1;     
                array((i - 1) * 3 + j) = new(i + q, j + w);
            end
        end
        noiseless_image(x, y) = median(sort(array(:)));
    end
end

figure(1);
subplot(211);
imshow(image)
title("Original Image");
subplot(212);
imshow(uint8(noiseless_image))
title("Noiseless Image");

name = strcat('noiseless_image.tif');
disp(name)
imwrite(uint8(noiseless_image), name)