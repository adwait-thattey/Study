clear;
clc;

printf("Please select an image:\n")
file = uigetfile;
image = imread(file);

%Zero Padding 
[r,c] = size(image);
new = zeros(r + 2, c + 2);
for m = 2 : r + 1
    for n = 2 : c + 1
        new(m,n) = image(m - 1, n - 1);
    end
end

%Applying median filter

image_noiseless = zeros(r, c);
for x = 1 : r
    for y = 1 : c
        for i = 1 : 3
            for j = 1 : 3
                w = y -1;
                q = x - 1;     
                array((i - 1) * 3 + j) = new(i + q, j + w);
            end
        end
        image_noiseless(x, y) = median(sort(array(:)));
    end
end

% Plot Result

figure(1);
subplot(211);
imshow(image)
title("Original Image");
subplot(212);
imshow(uint8(image_noiseless))
title("Noise Filtered Image");

%Writing Output Image
name = strcat('noiseless_', file);
printf("Your processed image is saved as ")
disp(name)
imwrite(uint8(image_noiseless), name)