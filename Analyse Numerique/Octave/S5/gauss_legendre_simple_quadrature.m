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
if (S>3)
	Ih= gauss_legendre_simple_quadrature(fun,a,b,3)
	return
elseif (S==3)
	c= ( (a+b)/2) .* ones(3,1) + ( (b-a)/2 ).*[ -sqrt(15)/5; 0; sqrt(15)/5]
	bb= ( (b-a)/2 ).* [5/9 8/9 5/9]
elseif (S==2)
	c= ( (a+b)/2) .* ones(1,2) + ( (b-a)/2 ).*[ - 1/sqrt(3); 1/sqrt(3)]
	bb= ( (b-a)/2 ).* [1 1]
elseif (S==1)
	c= ( (a+b)/2) .* ones(1,1) + ( (b-a)/2 ).*[ 0]
	bb= ( (b-a)/2 ) .* [ 2]
end
valf= fun(c)
Ih = bb * valf

