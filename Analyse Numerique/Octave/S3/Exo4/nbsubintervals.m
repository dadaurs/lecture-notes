function integer = nbsubintervals(a,b,f,tol,trueval)
	M=1
	h= (b-a)/M
	Q=midPoint(a,b,M,f)
	intmp=midPoint(a,b,M,f)
	touteslescritiques=[]
	vraierreur=[]
	crit=tol+1
	count=0
	while crit>tol
		M=2.*M
		intmp=midPoint(a,b,M,f)
		Q= [Q intmp]
		h=[h (b-a)/M]
		crit=abs( Q(end-1)-Q(end) )
		touteslescritiques=[ touteslescritiques crit ]
		count+=1
		vraierreur= [ vraierreur abs(intmp-trueval)]
	end
	integer=M
	loglog(1:1:count,touteslescritiques)
	hold on
	loglog(1:1:count,vraierreur)
	hold off
