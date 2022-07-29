function sth=chebychev(f,n,nbnoeuds)
	lin=0:1:n
	x= cos( ( (2.*lin +1).*pi )/(2*n)) 
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


	
