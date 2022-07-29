function [graditer, gradconjiter]=resol()
    A= [ [3 2] ; [2 6] ];
    b= [ 2 ; -8];
    x0=zeros(2,1);
    P=eye(2);
    [grad,relres,graditer,flag,res]=    gradient(A,b,x0,P,10^5,10^-3);
    [gradconj,flag,relres,gradconjiter]=    pcg(A,b,10^-3, 10^5, P);
    my_gradient(A,b,x0,P,10^5,10^-3);
    %my_conjgrad(A,b,10^-3, 10^5, P);



    
    
end

