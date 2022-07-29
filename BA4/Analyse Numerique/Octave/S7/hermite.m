function val=hermite(F,f, a,b,n)
	noeudeval=linspace(a,b-(b-a)/n,n-1)
	tout=[]
	for i=1:n-1
		pt=noeudeval(i)
		m1m= (f(pt)- f(pt+1/n))*n;
		H= @(x) F(pt) + (x-pt).*m1m + n.^2 .*(x-pt)(x-pt-1/n) *((f(pt+1/n) -m1m)(x-pt) + (f(pt) - m1m)(x-pt-1/n));
		tout=[tout,erroninterval(pt,pt+1/n,F, H, 100)];
	end
	val= max(abs(tout))
