function res= fonctionsin()
	f= @(x) sin(x).*x.^2/2 
	vten=linspace(0,20,10)
	vtwent=linspace(0,20,20)
	vcent=linspace(0,20,100)
	%plot(vten, f(vten),'g')
	%plot(vtwent, f(vtwent),'b')
	plot(vcent, f(vcent),'r')
end
