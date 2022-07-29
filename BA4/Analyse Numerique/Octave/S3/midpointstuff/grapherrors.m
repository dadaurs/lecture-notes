function table = grapherrors(a,b,f,trueval,method)
	table= []
	for i=1:5
		table=[table,increasingerrors(a,b,f,i,trueval,method)]
	end
	loglog(1:1:5,table)

