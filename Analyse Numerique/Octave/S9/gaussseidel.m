function qq=gaussseidel(n, epsi)
	[A,b]=matrix(n,epsi);
	D=diag(diag(A))
	E = tril(-A) - diag(diag(-A))
	F= triu(-A) - diag(diag(-A))
	B= inv(D- E)*(F)
	qq=max(abs(eig(B)))
