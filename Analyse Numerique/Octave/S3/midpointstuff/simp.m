function intsimp = simp( a, b, M, f )
% simp Composite Simpson formula
%  INTSIMP = SIMP( A, B, M, F ) computes the integral of the function F
%   in the interval [A B] using M subintervals.

% Taille h des sous-intervalles:
h = (b - a) / M;

% Noeuds de la formule d'integration:
x = linspace(a, b, M + 1);

x_bar=(x(1:end-1)+x(2:end))/2;

% Integrale
intsimp = h/6 * sum( f(x(1:M))+ 4*f(x_bar(1:end)) + f(x(2:M+1)));

return
