function qq=factlu(n)
	id=eye(n);
	bigone=ones(n,1);
	onematrix=[ bigone, zeros(n,n-1)];
	S= onematrix + onematrix' -id;
	[L,U,P,Q] = lu(sparse(S));
	Atilde= P*S*Q;
	[Ltilde, Utilde, Ptilde] = lu(Atilde);
	spy(Ltilde)


