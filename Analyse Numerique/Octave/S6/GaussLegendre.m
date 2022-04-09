function [x] = GaussLegendre(n,a,b)
% X = GAUSSLEGENDRE(N,A,B) retourne les N points de quadrature de 
% Gauss-Legendre dans l'intervalle [A,B].
%
% Ecrit par Mathieu Fabre - 11/03/2017

% Initial guess
y = cos(pi*((1:n)-1./4)/(n+1/2));

% Initialisation de la boucle while
y0 = 2;
while(max(abs(y-y0)) > eps)
    P0 = 1;
    P1 = y;
    for k = 2:n
        % Relation de recurrence
        P = ((2*k-1)*y.*P1-(k-1)*P0)/k;
        P0 = P1;
        P1 = P;
    end
    % Update des variables
    y0 = y;
    y = y0-P1.*(y0.^2-1)./(n*y0.*P1-n*P0);
end
% Interpolation de [-1,1] vers [a,b]
x = (y*(b-a)+(a+b))/2;



    
    


