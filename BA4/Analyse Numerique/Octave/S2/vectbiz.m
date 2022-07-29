function res = vectbiz(x,y)
	x=x(:)
	y=y(:)
	if (size(x)!=size(y))
		res=0
	end
	x=x(end:-1:1)
	C=x*y'
	res=C([1],:)
end
