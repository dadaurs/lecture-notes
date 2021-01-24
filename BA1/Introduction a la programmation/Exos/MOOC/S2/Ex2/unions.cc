#include <iostream>
using namespace std;


int main(){
double n;
cout << "Nombre:" ;
cin >> n;
if ( (n==2 ||(n>2 && n<3)) || (( n>0 && n <1 )|| n==1) || ( (n>-10 && n < -2) || n ==-10 || n==-2) ){
	cout << "appartient a I"<< endl;
}else {
	cout << "n'appartient pas a  I"<< endl;
}
return 0;
}
