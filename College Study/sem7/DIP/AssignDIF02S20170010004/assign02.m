img_info = imfinfo("lena512.bmp");
disp("Info:");
disp(img_info);
img = imread("lena512.bmp");
comp_img = imcomplement(img);
imwrite(comp_img,"comp_lena.bmp");
subplot(1,2,1), imshow(img);
subplot(1,2,2), imshow(comp_img);