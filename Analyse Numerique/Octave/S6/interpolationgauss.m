function sth=interpolationgauss(f,n,a,b,epsmax,taux)
	evaluations=linspace(a,b,taux)
	x=linspace(a,b,n+1);
	y=f(x);
	pert= -epsmax./2+ epsmax.*rand(1,n+1);
	z=y+pert
	p=polyfit(x,y,n)
	ppert=polyfit(x,z,n)
	plot(evaluations,f(evaluations))
	hold on
	plot(evaluations, polyval(p,evaluations))
	plot(evaluations,polyval(ppert,evaluations))
	hold off

