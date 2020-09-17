clc;
clear;

input_image_1 = imread('Sample_1_1.tif');
input_image_2 = imread('Sample_1_2.tif');

func(input_image_1,'Sample1',1)
func(input_image_2,'Sample2',2)

function mm = func(input_image, name, fig)
    max_val = max(max(input_image));
    min_val = min(min(input_image));
    
    m = (255/(max_val - min_val));
    conmtrast_stretched = m*(input_image -min_val);
    
 
    l = 256;
    pix_num=zeros(l,1);
    for i=0:255
        pix_num(i+1)=sum(sum(input_image==i));
    end

    equalized_image = uint8(zeros(size(input_image)));
    p=pix_num/(size(input_image,1)*size(input_image,2));
    s=round((l-1)*cumsum(p));
    
    for m=1:size(s,1)
        equalized_image(input_image==m-1)=s(m);
    end
    
    
    %Result Plots
    figure(fig)
    subplot(311);
    imshow(input_image);
    title("Original");
    subplot(312);
    imshow(conmtrast_stretched);
    title("Contrast Stretched Image");
    subplot(313);
    imshow(equalized_image);
    title("Histogram Equalized Image");
    

    imwrite(equalized_image, append(name,'_eqal.tif'));
    imwrite(conmtrast_stretched, append(name,'_stretch.tif'));

    
    mm=1;
end



    
  

