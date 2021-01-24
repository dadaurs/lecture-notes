#include <iostream>
using namespace std;


int main(){

	double valeur1(1),valeur2(2),valeur3(3);
	double* choix;
	int nb;
	cout<<"Quelle valeur"<<endl;
	cin>>nb;
	if(nb==1)
		choix = &valeur1;
	else if(nb==2)
		choix = &valeur2;
	else
		choix = &valeur3;

	cout << "Vous avez choisi" << *choix <<endl;

return 0;
}
