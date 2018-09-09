clear
clc

pic = imread('addy.jpeg');
red_pic = pic(:,:,1);
green_pic = pic(:,:,2);
blue_pic = pic(:,:,3);

subplot(2,2,1);
imshow(pic);
title('original')

subplot(2,2,2);
imshow(red_pic);
title('red')

subplot(2,2,3);
imshow(green_pic);
title('green')

subplot(2,2,4);
imshow(blue_pic);
title('blue')

min(min(red_pic))
min(min(green_pic))
min(min(blue_pic))

max(max(red_pic))
max(max(green_pic))
max(max(blue_pic))

mean2(red_pic)
mean2(green_pic)
mean2(blue_pic)

whos pic