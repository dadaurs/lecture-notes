#include <iostream>
#include <cmath>
		

using namespace std;



int main(){
	int nb;
	cout << "Nombre" << endl;
	cin >> nb;
	if (nb > 2 && nb%2==0){
		cout << nb << " n'est pas premier car il est divisible par 2" << endl;
		return 0;
	} else if (nb ==2){
		cout << " 2 est premier" << endl;
		return 0;
	}
	int rac = sqrt(nb) + 1;
	for (int i=2; i <= rac; ++i){
		if(nb%i==0){
			cout << nb << "n'est pas premier car il est divisible par" << i << endl;
			return 0;
		}
	}
	cout << "Je crois fortement que ce nombre est premier" << endl;



return 0;
}
