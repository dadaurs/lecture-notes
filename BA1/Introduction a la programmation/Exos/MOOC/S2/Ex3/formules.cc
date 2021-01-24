#include <iostream>
#include <cmath>
using namespace std;


int main(){
double x;
cout<< "nombre reel?"<<endl;
cin >> x;

if (x==0){
cout << "Expression 1: indefinie"<< endl;
}else {
	cout << x/(1-exp(x))<<endl;
}

if (x<=0 || x == 1){
cout << "Expression 2: indefinie"<< endl;
}else {
	cout << x * log(x) * exp(2/(x-1))<<endl;
}

if ((x*x-8*x)<0 || x ==2){
cout << "Expression 3: indefinie"<< endl;
}else {
	cout << (-x - sqrt(x*x -8*x)/(2-x)) << endl;
}

bool test=true;
if (x!=0){
	if(( x*x-1/x ) <=0){
	cout << "Expression 4: indefinie"<< endl;
	test=false;
	}
	if (test){
		if(( x*x-1/x ) <=1){
			if(sin(x)-x/20<0){
				cout << sqrt((sin(x) -x/20)*log(x*x-1/x))<< endl;
			}else{
				cout << "Expression 4: indefinie"<< endl;
			}
		}else{
			if(sin(x)-x/20>0){
				cout << sqrt((sin(x) -x/20)*log(x*x-1/x))<< endl;
			}else{
				cout << "Expression 4: indefinie"<< endl;
			}
		}
		
	}
}else {
	cout << "Expression 4: indefinie"<< endl;
}
return 0;
}
