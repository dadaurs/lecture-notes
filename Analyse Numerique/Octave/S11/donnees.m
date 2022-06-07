function [E,p,pval,x,y,f]=donnees(n, plotyn)
  load donnes2.mat;
  v=linspace(0,10,100);
  p=polyfit(x2,y2,n);
  pval=polyval(p,v);
  f= @(x) sin(x)+x;
  fval=f(v);
 if(plotyn == 0)
    plot(v,pval);
    hold on;
    plot(x2,y2);
    plot(v,fval);
end
 E= max(abs(fval-pval))


