function erreur= polynomesexactitude(d,S)
	f= @(x) x.^d
	I= gauss_legendre_simple_quadrature(f,0,1,S)
	erreur= 1/(d+1) - I
return
