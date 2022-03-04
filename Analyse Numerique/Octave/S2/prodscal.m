function res = prodscal(x,y)
	x=x(:)
	y=y(:)
	if (size(x)!=size(y))
		res=0
	end
	res= x'*y
end
