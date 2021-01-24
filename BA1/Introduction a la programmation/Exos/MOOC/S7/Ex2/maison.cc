#include <iostream>
#include <string>
using namespace std;

struct Maison {
	string addresse;
};
struct Personne {
	string nom;
	Maison* maison;
};
void affiche(Personne p){
	cout << p.nom << "habite" << p.maison->addresse <<endl;
}
void demenage(Personne &p, Maison n){
	*p.maison = n;

}

int main(){
	Maison maison1;
	Maison maison2;
	maison1.addresse = "av a";
	maison2.addresse = "av b";
	Personne a;
	a.maison = &maison1;
	a.nom = "a";
	Personne b;
	b.maison = &maison2;
	b.nom = "b";
	affiche(a);
	affiche(b);
	demenage(a, maison2);
	//a.maison = &maison2;
	affiche(a);


return 0;
}
