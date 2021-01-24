#include <iostream>
using namespace std;
int demander_nombre(int inf, int max);
int main(){
	int tcho =demander_nombre(8,3);
	cout << tcho;

return 0;
}
int demander_nombre(int inf, int max){
	bool onsenfout=true;
	if ( max <= inf){
		onsenfout=false;
	}

	int nb;
	do {
	cout << "NB?" << endl;
	cin >> nb;
	} while ( nb <= inf || (nb > max && onsenfout));
	return nb;
}
