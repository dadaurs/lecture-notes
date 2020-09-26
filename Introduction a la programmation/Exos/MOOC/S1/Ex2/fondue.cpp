#include <iostream>
using namespace std;

int main(){
	const int BASE=4;
	double fromage = 800;
	double eau = 2;
	double ail=2;
	double pain=400;
	int nbconv;
	cout << "Combien de convives? ";
	cin >> nbconv;
	cout << "Pour faire une fondue fribourgeoise pour 3 personnes, il vous faut :" << endl;
	cout << "-" << ((double)nbconv/BASE)*fromage << "de fromage" << endl;
	cout << "-" << ((double)nbconv/BASE)*eau << "de eau" << endl;
	cout << "-" << ((double)nbconv/BASE)*ail << "de ail" << endl;
	cout << "-" << ((double)nbconv/BASE)*pain << "de pain" << endl;
	cout << "du poivre" << endl;
	return 0;
}
