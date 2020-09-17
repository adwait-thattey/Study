clear variables;
close all;




image = imread('Sample_3.tif');
img_inp_pad = padarray(image,[1,1]);
[r,c] = size(img_inp_pad);
subplot(8,1,1), imshow(image);
title('Sample\_3');


lap_2nd_der = zeros(size(image),'uint8');
for i=2:r-1
  for j=2:c-1
    lap_2nd_der(i-1,j-1)=img_inp_pad(i+1,j)+img_inp_pad(i-1,j)+img_inp_pad(i,j+1)+img_inp_pad(i,j-1)-(4*img_inp_pad(i,j));
  end
end
imwrite(lap_2nd_der,'part2_Laplace_2nd_Derivative.tif');
subplot(8,1,2), imshow(lap_2nd_der);
title('Laplacian 2nd Der');



add_lap = image - lap_2nd_der;
imwrite(add_lap,'part3_add_laplacian.tif');
subplot(8,1,3), imshow(add_lap);
title('Laplacian Added');


M_y = [-1,0,1;-2,0,2;-1,0,1];
M_x = [-1,-2,-1;0,0,0;1,2,1];
H = conv2(im2double(image),M_x,'same');
V = conv2(im2double(image),M_y,'same');
img_sbl = sqrt(H.*H + V.*V);
imwrite(img_sbl,'part4_sobel.tif');
subplot(8,1,4), imshow(img_sbl);
title('Sobel');


image_smooth = zeros(size(img_sbl));
[r,c] = size(img_sbl);
for i=3:r-2
  for j=3:c-2
    image_smooth(i,j) = sum(sum(img_sbl(i-2:i+2,j-2:j+2)))/25;
  end
end
imwrite(image_smooth,'part5_sooth_sobel.tif');
subplot(8,1,5), imshow(image_smooth);
title('Smoothened Sobel');

% 6. Mask image of 3 and 5
image_mask = im2double(add_lap) .* image_smooth;
imwrite(image_mask,'part6_masked.tif');
subplot(8,1,6), imshow(image_mask);
title('Masked Image');


img_shrp_sum = im2double(image) + image_mask;
imwrite(img_shrp_sum,'part7_mask_add.tif');
subplot(8,1,7), imshow(img_shrp_sum);
title('after adding the mask');


gamma=0.5;
c=1;
img_final = c.*(img_shrp_sum.^gamma);
imwrite(img_final,'part7_gamma_trans.tif');
subplot(8,1,8), imshow(img_final);
title('gamma(0.5) transformation');

