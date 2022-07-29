function sth=vandermonde(f,n,nbnoeuds)
	x=linspace(-1,1,n+1)
	V=vander(x)
	[L,U,P] = lu(V)
	b=f(x')
	y=L\(P*b)
	a=U\y
	noeudeval=linspace(-1,1,nbnoeuds)
	p=polyval(a,noeudeval)
	plot(noeudeval,p)
	hold on
	plot(noeudeval, f(noeudeval))
	hold off


	
