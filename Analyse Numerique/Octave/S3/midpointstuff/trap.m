function inttrap = trap( a, b, M, f )
% TRAP Composite trapezoidal quadrature formula
%   INTTRAP = TRAP( A, B, M, F ) computes the integral of the function F
%   in the interval [A B] using M subintervals.

% Taille h des sous-intervalles:
h = (b - a) / M;

% Noeuds de la formule d'integration:
x = linspace(a, b, M + 1);

% Integrale
inttrap = h/2 * ( f(a) + f(b) ) + h * sum( f(x(2:M)) );

return
