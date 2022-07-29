function res = prod(x,y)
	x=x(:)
	y=y(:)
	if (size(x)!=size(y))
		res=0
	end
	C= x*y'
	res=C([1],:)
end


