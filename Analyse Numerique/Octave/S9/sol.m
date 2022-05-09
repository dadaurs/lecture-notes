function iter=sol(n, epsi,tol)
	[A,b]= matrix(n,epsi);
	xzero=zeros(n,1)
	[x,iter]= itermeth(A,b,xzero, 1000, tol, 'G')

	
