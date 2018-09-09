clear
clc
im1 = imread('brijesh.jpeg');

imshow(im1)

im_red = im1(:,:,1);
im_green = im1(:,:,2);
im_blue = im1(:,:,3);

subplot(2,2,1)
imshow(im1)

subplot(2,2,2)
imshow(im_red)

subplot(2,2,3)
imshow(im_green)

subplot(2,2,4)
imshow(im_blue)

min(min(im_blue))
max(max(im_red))
mean2(im_red)


whos im1
