function temp=temperature(n)
	L= [-55 -45 -35 -25 -15 -5 5 15 25 35 45 55 65]
	T= [ 3.7 3.7 3.52 3.27 3.2 3.15 3.15 3.25 3.47 3.52 3.75 3.67 3.52]
	p=polyfit(L,T,13)
	noeudeval=linspace( min(L), max(L),n)
	valp=polyval(p,noeudeval)
	plot(noeudeval,valp)
