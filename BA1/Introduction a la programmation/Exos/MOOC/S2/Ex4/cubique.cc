#include <iostream>
#include <cmath>
using namespace std;


int main(){
bool unesol=false,deuxsol=false,troisols=false;
double z3,z1,z2;
double a2,a1,a0;
double S,T;
cout<<"coeff"<<endl;
cin >> a2 >> a1 >> a0;
double Q= (3*a1 - a2*a2)/9;
double R= (9*a2*a1 - 27*a0 - 2*a2*a2*a2)/54;
double D = pow(Q,3) + pow(R,2);

if (D<0){
troisols=true;
double theta= acos(R/sqrt(-(pow(Q,3))));
z1=2*sqrt(-Q)*cos(theta/3) - a2/3;
z2=2*sqrt(-Q)*cos(( theta+ 2* M_PI )/3) - a2/3;
z3=2*sqrt(-Q)*cos(( theta+ 4* M_PI )/3) - a2/3;
}else {
	if( R+ sqrt(D) <0){
		S=-pow(R +sqrt(D), 1.0/3.0);
		if(R -sqrt(D)<0){
			T=-pow(R -sqrt(D), 1.0/3.0);
		}else{
			T=pow(R -sqrt(D), 1.0/3.0);
		}
	}else{
	S=pow(R +sqrt(D), 1.0/3.0);
		if(R -sqrt(D)<0){
			T=-pow(R -sqrt(D), 1.0/3.0);
		}else{
			T=pow(R -sqrt(D), 1.0/3.0);
		}
	}
	if (D==0 && S+T !=0){
		deuxsol=true;
		z1=S+T -a2/3;
		z2=-(S+T)/2 -a2/3;
	}else{
		unesol=true;
		z1=S+T -a2/3;
	}

}
if(troisols)
	cout<<z1<<endl<<z2<<endl<<z3<<endl;
if(deuxsol)
	cout<<z1<<endl<<z2<<endl;
if(unesol)
	cout<<z1<<endl<<z2<<endl;

return 0;
}
