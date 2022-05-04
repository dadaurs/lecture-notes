function qq=matrix()
	deux=diag([ 2 2 2 2 2 2 2 2 2 2]);
	unhaut=diag([ -1 -1 -1 -1 -1 -1 -1 -1 -1],1);
	unbas=diag([ -1 -1 -1 -1 -1 -1 -1 -1 -1],-1);
	M= deux + unhaut + unbas;
	fprintf "Determinant:\n"
	s= det(M)
	fprintf "norme 1:\n"
	s1= norm(M,1)
	fprintf "norme 2:\n"
	s2= norm(M,2)
	fprintf "norme inf:\n"
	sinf= norm(M,Inf)
	%calculs des vecteurs propres:
	lambdas=eig(M);
	fprintf "rho = "
	rho= max(abs(lambdas))
	fprintf "   et norme 2:  " 
	s2
	[V, lambda] = eig(M);

	fprintf " V^-1 MV\n   "
	inv(V) * M * V
	fprintf "structure des matrices \n "
	spy(V)

