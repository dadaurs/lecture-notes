function terme = fibonacci(seuil)
if (seuil<=1)
	terme=[0 1]
end
terme=[0 1]
while (terme(end)+terme(end-1)<seuil)
	terme=[terme  terme(end)+terme(end-1)]
end




