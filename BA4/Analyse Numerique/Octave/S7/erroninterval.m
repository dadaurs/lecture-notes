function val=erroninterval(a,b,f,H, N)
	valeurs=linspace(a,b,N);
	tout=abs(f(valeurs)-H(valeurs));
	val=max(tout);
