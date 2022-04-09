function p=interpolationlegendre(f,n,a,b,epsmax,taux)
	evaluations=linspace(a,b,taux);
	x=GaussLegendre(n,a,b);
	y=f(x);
	pert= -epsmax./2+ epsmax.*rand(1,n);
	z=y+pert;
	p=polyfit(x,y,n)
	ppert=polyfit(x,z,n)
	plot(evaluations,f(evaluations))
	hold on
	plot(evaluations, polyval(p,evaluations))
	%plot(evaluations,polyval(ppert,evaluations))
	% plotting error of the legendre approximation
	plot(evaluations, 10*abs(polyval(p,evaluations)-f(evaluations)))
	hold off

