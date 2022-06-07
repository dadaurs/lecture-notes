function qq=hilbe(n,maxit,tol)
  A=hilb(n);
  b = A* ones(n,1);
  x0=zeros(n,1);
  P= eye(n);
  % does not converge for P=Id_5
  % converges for P=tril(A)
  % but very slowly
  %  %[qq,relres,iter,flag,res]=gradient(A,b, x0, P,maxit,tol);
  %speedy boiiiiii:

  pcg(A,b, tol, maxit, P)




  
