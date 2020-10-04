#include <iostream>
using namespace std;


int main(){

	cout<<"Tables de Multiplication"<<endl;
	for(int i(2);i<=10;i++){
		cout << "Tables de "<< i<<endl;
		for(int j(1);j<=10;++j){
			cout << i << "*" << j << "=" << i*j << endl;
		}
	}
return 0;
}
