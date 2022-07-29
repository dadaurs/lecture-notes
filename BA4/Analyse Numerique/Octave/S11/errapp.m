function errapp()
  v=1:1:15
  errvect=[]
  for i=v
    errvect = [ errvect donnees(i,1) ]
  end
  loglog(v,errvect)

