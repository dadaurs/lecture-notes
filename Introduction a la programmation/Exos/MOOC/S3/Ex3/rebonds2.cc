#include <iostream>
using namespace std;
#include <cmath>


int main(){
	constexpr double g = 9.81;
	double h0;
	double eps;
	double h_fin;
	cout<< "Valeur de H0"<<endl;
	cin >> h0;
	if(h0<=0)
		return 1;

	cout << "Valeur de eps"<< endl;
	cin >> eps;
	if ( eps < 0 || eps >1)
		return 1;
	cout << "Hauteur de fin"<<endl;
	cin >> h_fin;



	double h;
	double v = sqrt(2*h0*g);
	double v1;
	int nbr(0);
	do {
	nbr++;
	v1= eps*v;
	h= v1*v1/(2*g);
	v = sqrt(2*h*g);
	} while (h >= h_fin);
	cout << nbr << endl;


		
return 0;
}

