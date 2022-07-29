function [x,relres,iter,flag,res]=gradient(A,b,x,P,nmax,tol)
%GRADIENT Gradient method
%  [X,RELRES,ITER,FLAG,RES]=GRADIENT(A,B,X0,P,NMAX,TOL) attempts to solve the
%  system A*X=B with the gradient method. TOL specifies the tolerance
%  of the method. NMAX specifies the maximum number of iterations.
%  X0 specifies the initial guess. P is a preconditioner. RELRES is the
%  relative residual. If FLAG is 1 RELRES > TOL. ITER is the iteration number
%  at which X is computed. RES is a vector containing the residuals at each
%  iteration.
[n,m]=size(A);
res=[ ];
if n ~= m, error('Only squared systems'); end
flag = 0; iter = 0; bnrm2 = norm( b );
if bnrm2==0, bnrm2 = 1; end
r=b-A*x;  relres=norm(r)/bnrm2;
if relres<tol, return, end
for iter=1:nmax
    z=P\r;  
    rho=r'*z;
    q=A*z;
    alpha=rho/(z'*q);
    x=x+alpha*z;
    r=r-alpha*q;
    relres=norm(r)/bnrm2;
    res=[res; relres];
    if relres<=tol, break, end
end
if relres>tol, flag = 1; end
return
