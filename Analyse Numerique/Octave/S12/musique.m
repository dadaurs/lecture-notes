function maxdiff=musique(seuil)
  y=audioread('foryoublue.wav');
  %plot(y)
  yft=fft(y);
  for i=linspace(1,length(yft),1);
    if abs(yft(i)) < seuil;
      yft(i)=0;
    end
   end
  ycomp=ifft(yft);
  xaxis=linspace(10000,15000,1);
  maxdiff=max(abs(y- ycomp))

