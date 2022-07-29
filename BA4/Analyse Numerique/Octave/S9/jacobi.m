function qq=jacobi(n, epsi)
	[A,b]=matrix(n,epsi);
	D=diag(diag(A))
	E = tril(-A) - diag(diag(-A))
	A= triu(-A) - diag(diag(-A))
	B= inv(D)*( E+A)
	qq=max(abs(eig(B)))
