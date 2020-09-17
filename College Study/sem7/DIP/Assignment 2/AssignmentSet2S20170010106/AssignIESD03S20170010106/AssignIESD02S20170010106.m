clear variables;
close all;

figure(1);

% 1. file
file = uigetfile('*.tif');
img_inp = imread(file);
img_inp_pad = padarray(img_inp,[1,1]);
[r,c] = size(img_inp_pad);
subplot(2,4,1), imshow(img_inp);
title('file');


% 2. lapacian second derivative
img_lp = zeros(size(img_inp),'uint8');
for i=2:r-1
  for j=2:c-1
    img_lp(i-1,j-1)=img_inp_pad(i+1,j)+img_inp_pad(i-1,j)+img_inp_pad(i,j+1)+img_inp_pad(i,j-1)-(4*img_inp_pad(i,j));
  end
end
imwrite(img_lp,'Output_1.tif');
subplot(2,5,2), imshow(img_lp);
title('Laplacian');


% 3. adding the laplacian
img_shrp = img_inp - img_lp; % since c = -1
imwrite(img_shrp,'Output_2.tif');
subplot(2,5,3), imshow(img_shrp);
title('after adding Laplacian');

% 4. sobel operator
M_y = [-1,0,1;-2,0,2;-1,0,1];
M_x = [-1,-2,-1;0,0,0;1,2,1];
H = conv2(im2double(img_inp),M_x,'same');
V = conv2(im2double(img_inp),M_y,'same');
img_sbl = sqrt(H.*H + V.*V);
imwrite(img_sbl,'Output_3.tif');
subplot(2,5,4), imshow(img_sbl);
title('Sobel');


% 5. 5x5 averaging mask
image_smooth = zeros(size(img_sbl));
[r,c] = size(img_sbl);
for i=3:r-2
  for j=3:c-2
    image_smooth(i,j) = sum(sum(img_sbl(i-2:i+2,j-2:j+2)))/25;
  end
end
imwrite(image_smooth,'Output_4.tif');
subplot(2,5,5), imshow(image_smooth);
title('Smoothened Sobel');

% 6. Mask image of 3 and 5
image_mask = im2double(img_shrp) .* image_smooth;
imwrite(image_mask,'Output_5.tif');
subplot(2,5,6), imshow(image_mask);
title('Masked Image');

% 7. adding mask to original image
img_shrp_sum = im2double(img_inp) + image_mask;
imwrite(img_shrp_sum,'Output_6.tif');
subplot(2,5,7), imshow(img_shrp_sum);
title('after adding the mask');

% 8. gamma transformation
gamma=0.5;
c=1;
img_final = c.*(img_shrp_sum.^gamma);
imwrite(img_final,'Output_7.tif');
subplot(2,5,8), imshow(img_final);
title('gamma(0.5) transformation');