% Tracer un ellipse

%close all
%clear

% definition de la matrice A
A=[3 2; 2 6];
b=[2; -8];
c=[2 -2]';

[V,D]=eig(A);
lambda1=D(1,1);
lambda2=D(2,2);
v=V(:,1);

theta=linspace(0,2*pi,500);
R=linspace(0.001,10.001,10);
r=-atan2(v(2),v(1));

figure;grid;hold on;

for i=1:10

    x=(R(i)/sqrt(lambda1)).*sin(theta);
    y=(R(i)/sqrt(lambda2)).*cos(theta);

    xr=x.*cos(r)+y.*sin(r);
    yr=y.*cos(r)-x.*sin(r);

    xrt=xr+c(1);
    yrt=yr+c(2);

    plot(xrt,yrt,'-black'); axis equal;
    
end

axis manual;
