#include <iostream>
using namespace std;

double factorielle(int k);
double somme_partielle(double x, int N);
int demander_nombre();
double pow(double x, int i);

int main(){
cout.precision(12);
//double nb;
//int N=demander_nombre();
//do{
	//cout <<"Valeur :"<<endl;
	//cin>>nb;
	//cout << somme_partielle(nb,N)<<endl;
	
//}while(nb!=0.0);
for (int i=0;i<100;i++){
cout << somme_partielle(i,50) <<endl;
}
return 0;
}
double factorielle(int k){
	if (k==0){return 1;}
	return k * factorielle(k-1);
}
double somme_partielle(double x, int N){
	double res=0;
	for(int i=0;i<=N;i++){
	res+= (1/(factorielle(2*i)) )*pow(x,2*i)*pow(-1,i);
	}
	return res;
}
int demander_nombre(){
	int nb;
	cout << "NB?" << endl;
	cin >> nb;
	return nb;
}
double pow(double x, int i){
	double res=1;
	for (int j=0; j<i; ++j){
	res *=x;
	}
	return res;
}
