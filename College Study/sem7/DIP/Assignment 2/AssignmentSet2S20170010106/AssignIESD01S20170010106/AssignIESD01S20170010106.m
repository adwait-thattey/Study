clc;
clear;
for n = 1:2
   %Image selection
    printf('Please select an image:\n')
    image = uigetfile;
    image_old = imread(image);
    
    %Finding minimum and maximum intensity value

    max_val = max(max(image_old));
    min_val = min(min(image_old));
    
    %Applying Contrast stretching
    m = (255/(max_val - min_val));
    image_contr_str = m*(image_old -min_val);
    
    %Histogram Equalization Code
    l = 256;
    pix_num=zeros(l,1);
    for i=0:255
        pix_num(i+1)=sum(sum(image_old==i));
    end

    image_equalized = uint8(zeros(size(image_old)));
    p=pix_num/(size(image_old,1)*size(image_old,2));
    s=round((l-1)*cumsum(p));
    
    for m=1:size(s,1)
        image_equalized(image_old==m-1)=s(k);
    end
    
    
    %Result Plots
    figure(n)
    subplot(311);
    imshow(image_old);
    title("Original Image");
    subplot(312);
    imshow(image_contr_str);
    title("Contrast Stretched Image");
    subplot(313);
    imshow(image_equalized);
    title("Histogram Equalized Image");
    
    if(n==1)
        imwrite(image_equalized, 'eqal_1.tif')    ;
        imwrite(image_contr_str, 'stretch_1.tif');
    else  
        imwrite(image_equalized, 'eqal_2.tif'); 
        imwrite(image_contr_str, 'stretch_2.tif')  ;
    endif
    
end

