function [ Ih ] = gauss_legendre_simple_quadrature( fun, a, b, S )
% GAUSS_LEGENDRE_SIMPLE_QUADRATURE approxime l'integrale d'une fonction
% dans l'intervalle [a,b] grace a la formule de quadrature simple de
% Gauss-Legendre.
%  [ Ih ] = gauss_legendre_simple_quadrature( fun, a, b, S )
%  Inputs: fun = function handle, 
%          a,b = extremites de l'intervalle [a,b]
%          S = nombre de noeuds et poids de quadrature
%  Output: Ih = valeur approchee de l'integrale
%


return