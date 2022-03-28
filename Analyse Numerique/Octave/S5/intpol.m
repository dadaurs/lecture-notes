function pol=intpol(f,a,b,n)
	xval=linspace(a,b,n)
	yval=f(xval)
	pol=polyfit(xval,yval,n)
return


