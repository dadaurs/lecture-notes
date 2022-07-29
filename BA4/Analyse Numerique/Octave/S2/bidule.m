function truc = bidule()
	C = zeros(12)
	A=reshape(1::144,size(C))
	A=A'
	D=zeros(6)
	for i=1:12
		for j=1:12
			if(rem(i+j,2)==0)
				C(i,j)=A(i,j)
			end
		end
	end
