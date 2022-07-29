function I = intapprochee(f,a,b,n,M)
	I=0;
	H= 1/M;
	x=linspace(a,b,M);
	one=ones(1,M)
	for i = linspace(a,b,M)
		I += gaussLegendre(f,i ,i+ H ,n)
	end
