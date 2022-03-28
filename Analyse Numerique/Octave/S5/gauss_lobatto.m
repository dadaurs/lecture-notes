function intgl = gauss_lobatto( a, b, f )
% GAUSS_LOBATTO5 Gauss-Lobatto formula with 5 nodes
%   INTGL = GAUSS_LOBATTO5( A, B, F ) computes the integral of
%   the function F in the interval [A B].

% Noeuds et poids de reference - completer ci-dessous


% Noeuds et poids transformes sur l'intervalle [a,b] -- completer ci-dessous


% Calcul de l'integrale -- completer ci-dessous
noeuds= [ -1; -1/7 * sqrt(21); 0; 1/7 * sqrt(21); 1]
poids= [ 1/10; 49/90; 32/45; 49/90; 1/10]
valf= f(noeuds)
intgl = poids' * valf


end
