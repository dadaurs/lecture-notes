#include <iostream>
using namespace std;

int main(){
	int age;
	int curyear(2020);
	cout << "Quel est l'age?";
	cin >> age;
	int naissance = curyear - age;
	cout << "L'annee de naissance est :" << naissance << endl;
	return 0;
}
