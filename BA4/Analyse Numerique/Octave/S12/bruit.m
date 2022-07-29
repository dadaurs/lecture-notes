function qq=bruit()
  sign1 = @(x) 1.3 .*sin(2* pi* 15.*x);
  sign2 = @(x) 1.7 .*sin(2* pi* 35.*x);
  sign3 = @(x) 2 .*sin(2* pi* 40.*x);
  f = @(x) sign1(x) + sign2(x)+ sign3(x);
  t=[0:0.01:2*pi];
  bruit= gallery('normaldata', size(t),4);
  signal= f(t) + bruit;
  ft=fft(signal);
  coeffsq= ft.^2
  plot(coeffsq)

