function E = erreurs(f, a,b,n, z,w)
	E=[]
	valprecis=1/3 .* sin(pi/3).^3
	for i=z:1:w
		e= abs( valprecis - intapprochee(f,a,b,n,2.^i))
		E= [E,e]
	end

