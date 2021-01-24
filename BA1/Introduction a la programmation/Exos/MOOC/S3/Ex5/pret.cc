#include <iostream>
using namespace std;



int main(){
	double s0;
	cout << "Somme totale" << endl;
	cin >> s0;
	if (s0 <=0)
		return 0;
	double r;
	cout << "r" << endl;
	cin >> r;
	if (r<=0)
		return 0;
	double ir;
	cout << "ir" << endl;
	cin >> ir;
	//if (r <=0 || r >=1)
		//return 0;


	double s=s0;
	double inter=0;
	do {
	inter += s*ir;
	s0=s0-r-s*ir;
	s=s0;
	}while(s0>0);
	cout << inter << endl;

return 0;
}
