function [ Ih ] = gaussLegendre( fun, a, b, n )
% GAUSSLEGENDREE approxime l'integrale d'une fonction
% dans l'intervalle [a,b] grace a la formule de quadrature simple de
% Gauss-Legendre.
%  [ Ih ] = gauss_legendre_simple_quadrature( fun, a, b, n )
%  Inputs: fun = function handle, 
%          a,b = extremites de l'intervalle [a,b]
%          n + 1 = nombre de noeuds et poids de quadrature
%  Output: Ih = valeur approchee de l'integrale
%

% Noeuds et poids de reference
switch n
    
    case 0
        y_ref = 0;
        alpha_ref = 2;
    
    case 1
        y_ref = [ -1/sqrt(3), 1/sqrt(3) ]; 
        alpha_ref = [ 1, 1 ];        
        
    case 2
        y_ref = [ -sqrt(15)/5, 0, sqrt(15)/5 ]; 
        alpha_ref = [ 5/9, 8/9, 5/9 ];                
    
    otherwise
        error('n doit etre 0, 1, or 2');
        
end

% Noeuds et poids transformes sur l'intervalle [a,b]
y_rescaled = ( a + b ) / 2 + ( b - a ) / 2 * y_ref;
alpha_rescaled = ( b - a ) / 2 * alpha_ref;

% Integrale
Ih = sum( alpha_rescaled .* fun( y_rescaled ) ); 

return