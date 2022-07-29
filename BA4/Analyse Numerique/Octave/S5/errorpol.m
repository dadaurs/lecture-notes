function err=errorpol(f,a,b,n)
		pol=intpol(f,a,b,n)
		xval=linspace(a,b,n)
		diff= abs( f(xval)- polyval(pol,xval))
		err=max(diff)
return

