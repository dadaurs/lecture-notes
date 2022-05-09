function [x , iter ]= itermeth (A ,b , x0 , nmax , tol , P )
% ITERMETH General iterative method
% X = ITERMETH (A ,B , X0 , NMAX , TOL , P ) attempts to solve the
% system of linear equations A * X = B for X . The N - by - N
% coefficient matrix A must be non - singular and the
% right hand side column vector B must have length
% N . If P = 'J' the Jacobi method is used , if P = 'G' the
% Gauss - Seidel method is selected . Otherwise , P is a
% N - by - N matrix that plays the role of a preconditione r
% for the gradient method , which is a dynamic
% Richardson method . Iterations
% stop when the ratio between the norm of the kth172
% residual and the norm of the initial residual is less
% than TOL , then ITER is the number of performed
% iterations . NMAX specifies the maximum
% number of iterations . If P is not defined , the
% unprecondit io n ed gradient method is performed .
[n , n ]= size ( A );
if nargin == 6
if ischar ( P )==1
if P == 'J'
L = diag ( diag ( A )); U = eye ( n ); beta =1; alpha =1;
elseif P == 'G'
L = tril ( A ); U = eye ( n ); beta =1; alpha =1;
end
else
[L , U ]= lu ( P ); beta = 0;
end
else
L = eye ( n ); U = L ; beta = 0;
end
iter =0; x = x0 ; r =b - A * x0 ; r0 = norm ( r ); err = r0 ;
while err > tol & iter < nmax
z = L \ r ; z = U \ z ; iter = iter + 1;
if beta == 0
alpha = z' * r /( z' * A * z );
end
x = x + alpha * z ;
r = b - A * x;
err = norm ( r ) / r0 ;
end

