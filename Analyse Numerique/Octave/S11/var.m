function sigma=var(m)
  [E,p,pval,x,y,f]=donnees(m,1)

  diffvect= y- polyval(p,x)
  sigma = 1/(columns(x)-m) * norm(diffvect)


  
