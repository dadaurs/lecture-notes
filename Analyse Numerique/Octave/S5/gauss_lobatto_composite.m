function intgl = gauss_lobatto5_composite( a, b, M, f )
% GAUSS_LOBATTO5_COMPOSITE Composite Gauss-Lobatto formula with 5 nodes
%   INTGL = GAUSS_LOBATTO5_COMPOSITE( A, B, M, F ) computes the integral of
%   the function F in the interval [A B] with M subintervals.
intervalles=linspace(a,b,M)
intgl=0
for i = linspace(1,M-1,M-1)
	intgl+=gauss_lobatto(intervalles(i), intervalles(i+1), f)
end



end
