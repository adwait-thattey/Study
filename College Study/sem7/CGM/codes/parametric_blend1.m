clear all;
close all;

t = 0:.1:1;

P0 = [1;1;0]; P1 = [0;0;1];

PL = (1-t).*P0 + t.*P1;
PL = PL';
PNL = (1-t).^2.*P0 + t.^2.*P1;
PNL = PNL';
PNNL = (1-t.^2).*P0 + t.^2.*P1;
PNNL = PNNL';


figure(1);
grid on; hold on;
plot3(PL(:,1),PL(:,2),PL(:,3),'.r');
plot3(PNL(:,1),PNL(:,2),PNL(:,3),'.g');
plot3(PNNL(:,1),PNNL(:,2),PNNL(:,3),'.b');
hold off;

