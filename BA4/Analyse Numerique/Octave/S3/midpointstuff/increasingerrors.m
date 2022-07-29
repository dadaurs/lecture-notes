function errors = increasingerrors(a,b,f,i,trueval,method)
	%method=1 is midpoint,method=2 is trapeze, method=3 is simpson
	trueval= (1- exp(-2).*(sin(2)+cos(2)))/2
	valM=1:1:5;
	if method==1
		errors=abs(trueval-midPoint(a,b,10.^i,f))
	elseif method==2
		errors=abs(trueval-trap(a,b,10.^i,f))
	elseif method==3
		errors=abs(trueval-simp(a,b,10.^i,f))
	end




