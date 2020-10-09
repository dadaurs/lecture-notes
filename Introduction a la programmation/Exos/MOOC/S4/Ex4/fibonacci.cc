#include <iostream>
using namespace std;

int fib(int n);

int main(){

	int nb;
	do{
		cout << "Entrez un nombre"<<endl;
		cin >> nb;
		cout << fib(nb)<<endl;
	}while (nb<0);
return 0;
}
int fib(int n){
	if(n==1){
		return 1;
	}
	if(n==0){
		return 0;
	}
	return fib(n-1)+fib(n-2);

}
