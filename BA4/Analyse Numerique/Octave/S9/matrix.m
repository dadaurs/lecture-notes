function [M,b]=matrix(n, epsi)
	A=zeros(n,n);
	for i=0:1:n-2
		un=ones(n-i,1);
		diago=epsi^(i) *diag(un);
		diago=[zeros(n-i,i) diago];
		diago=[diago ; zeros(i,n)];
		A = A+diago;
	end
	M=A+ A' - eye(n);
	b = M * ones(n,1);

