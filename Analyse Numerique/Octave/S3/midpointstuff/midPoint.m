function intmp = midPoint( a, b, M, f )
% MIDPOINT Composite midpoint quadrature formula
%   INTMP = MIDPOINT( A, B, M, F ) computes the integral of the function F
%   in the interval [A B] using M subintervals.

% Taille h des sous-intervalles:
h = (b - a) / M;      
 
% Noeuds de la formule d'integration:
x = linspace(a+h/2, b-h/2, M);

% Integrale approchee = 
%   h* (somme des valeurs de f aux noeuds x):
intmp = h * sum( f(x) );

return
