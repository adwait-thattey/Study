clear
clc

[y,fs] = audioread('addy.wav');

plot(y);
title('Adwaits Voice.wav')

sq = y.*y;
En = sum(sq)