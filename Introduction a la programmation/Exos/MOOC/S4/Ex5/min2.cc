#include <iostream>
using namespace std;
double min2(double a, double b){
	if(a>=b)
		return b;
	return a;
}
double min3(double a, double b, double c){
	return min2(a, min2(b,c));
}


int main(){
	cout << min2(2,4)<< endl;
	cout << min3(2,4,9)<< endl;

return 0;
}
