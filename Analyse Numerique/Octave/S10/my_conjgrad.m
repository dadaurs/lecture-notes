function [x, niter, error, flag] = my_conjgrad(A, b, x0, maxit, tol, P)
%
% [x, niter, error, flag] = conjgrad(A, b, x0, maxit, tol, P)
%
% Conjugate gradient method for the solution of P^{-1} A x = P^{-1} b.
%
% >> INPUT <<
%
%  A        (square) matrix
%  b        right-hand side
%  x0       starting solution
%  maxit    maximum number of iterations
%  tol      tolerance required
%  P        preconditioning matrix
%  
% >> OUTPUT <<
%
%  x         computed solution
%  niter     number of iteration to reach the prescribed tolerance
%  error     norm of the error
%  flag      if flag==1 the method has reached the maximum number
%            of iterations but error>tol

flag = 0; niter = 0; bnrm2 = norm( b );
xv=x0;

x=[xv(1)];
y=[xv(2)];
plot(x,y,'r*');
xv
pause

r = b - A*xv; error = norm( r ) / bnrm2;
if ( error < tol ) return, end
for niter = 1:maxit 
    z  = P \ r; rho = (r'*z);
    if niter > 1
       beta = rho / rho1;   p = z + beta*p;
    else
       p = z;
    end
    q = A*p;              alpha = rho / (p'*q );
    xn = xv + alpha * p;    r = r - alpha*q;
    error = norm( r ) / bnrm2;
    
    x=[xv(1) xn(1)];
    y=[xv(2) xn(2)];
    plot(x,y,'ro-');
    fprintf('iteration %i\n',niter);
    xn
    pause
    %    
    xv=xn;
    
    if ( error <= tol ), break, end
    rho1 = rho;
end
if ( error > tol ) flag = 1; end
if niter==maxit,
   disp(' gradient reached the maximum iteration number without converging')
end
return