#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Flacon
{
private:
  string nom;
  double volume;
  double pH;

public:
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/
  Flacon(string n,double v, double p):nom(n),volume(v),pH(p){}
  Flacon()=delete;
  ostream& etiquette(ostream& sortie) const {
	  sortie << nom <<" : "<< volume <<" ml, pH "<< pH;
	  return sortie;
  }
  string getNom() {
  	return nom;
  }
  double getVol() {
  	return volume;
  }
  double getpH() {
  	return pH;
  }
  
  

};
ostream& operator<<(ostream& os, Flacon f) {
	return f.etiquette(os);
}
Flacon operator+(Flacon f, Flacon m) {
	string n= f.getNom() + " + " + m.getNom();
	double vol=f.getVol() + m.getVol();
	double p= - log10( (( 1/vol ) * (f.getVol()*pow(10.0,-f.getpH())+m.getVol()*pow(10.0,-m.getpH()) )));
	Flacon F(n,vol,p);
	return F;
}



/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void afficher_melange(Flacon const& f1, Flacon const& f2)
{
  cout << "Si je mélange " << endl;
  cout << "\t\"" << f1 << "\"" << endl;
  cout << "avec" << endl;
  cout << "\t\"" << f2 << "\"" << endl;
  cout << "j'obtiens :" << endl;
  cout << "\t\"" << (f1 + f2) << "\"" << endl;
}

int main()
{
  Flacon flacon1("Eau", 600.0, 7.0);
  Flacon flacon2("Acide chlorhydrique", 500.0, 2.0);
  Flacon flacon3("Acide perchlorique",  800.0, 1.5);

  afficher_melange(flacon1, flacon2);
  afficher_melange(flacon2, flacon3);

  return 0;

}
