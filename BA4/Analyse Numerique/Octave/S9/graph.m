function qq=graph(n)
	evalspace=linspace(0,1,0.1);
	ja = @(x) jacobi(n,x)
	g = @(x) gaussseidel(n,x)
	plot(evalspace, ja)
	hold on
	plot(evalspace, g)
	hold off
