#include <iostream>
#include <string>
using namespace std;

class Timbre
{
private:
  static constexpr unsigned int ANNEE_COURANTE = 2016;

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/
protected:
  string nom;
  unsigned int annee;
  string pays;
  double valeur_faciale;
  static const int PRIX_BASE_TRES_RARE=600;
  static const int PRIX_BASE_RARE=400;
  static const int PRIX_BASE_PEU_RARE=50;

public:
  Timbre(string n, unsigned int a, string p="Suisse", double v=1.0):nom(n),annee(a), pays(p), valeur_faciale(v) {}

  double vente(){
  	if(ANNEE_COURANTE-annee<5) {
  		return valeur_faciale;
  	}else {
  		return valeur_faciale*2.5*(ANNEE_COURANTE-annee);
  	}
  }
  unsigned int age() {
  	return ANNEE_COURANTE-annee;
  }

  ostream & afficher(ostream & os) {
  	os<<"de nom "<< nom << " datant de " << annee << " (provenance "<< pays <<") ayant pour valeur faciale " << valeur_faciale << " francs";
	return os;
  }
  ostream & affichert(ostream & os) {
  	os<<"Timbre ";
	afficher(os);
	return os;
  }
  
  
  
};
class Rare: public Timbre {
	private:
		unsigned int nb_ex;
	public:
  	Rare(string n, unsigned int a, string p="Suisse", double v=1.0, int nb=100):Timbre(n,a,p,v), nb_ex(nb) {}
		unsigned int nb_exemplaires() {
			return nb_ex;
		}
		
		double vente() {
			double pb;
			if(nb_ex<100) {
				pb=PRIX_BASE_TRES_RARE;
			}else if (nb_ex<1000) {
				pb=PRIX_BASE_RARE;
			}else {
				pb=PRIX_BASE_PEU_RARE;
			}
			return pb* age() / 10.0;
		}
		
  ostream & afficher(ostream & os) {
  	os<<"Timbre rare ("<< nb_ex << " ex.) ";
	Timbre::afficher(os);
	return os;
  }

	
};
class Commemoratif: public Timbre {
	public:
  	Commemoratif(string n, unsigned int a, string p="Suisse", double v=1.0):Timbre(n,a,p,v) {}
	int vente() {
		return 2* Timbre::vente();
	}
  ostream & afficher(ostream & os) {
  	os<<"Timbre commémoratif ";
	Timbre::afficher(os);
	return os;
  }
	
	
};
ostream & operator<<(ostream & os, Timbre t) {
	return t.affichert(os);
}
ostream & operator<<(ostream & os, Rare t) {
	return t.afficher(os);
}
ostream & operator<<(ostream & os, Commemoratif t) {
	return t.afficher(os);
}




/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/
int main()
{
  /* Ordre des arguments :
  *  nom, année d'émission, pays, valeur faciale, nombre d'exemplaires
  */
  Rare t1( "Guarana-4574", 1960, "Mexique", 0.2, 98 );
  Rare t2( "Yoddle-201"  , 1916, "Suisse" , 0.8,  3 );

  /* Ordre des arguments :
  *  nom, année d'émission, pays, valeur faciale, nombre d'exemplaires
  */
  Commemoratif t3( "700eme-501"  , 2002, "Suisse", 1.5 );
  Timbre       t4( "Setchuan-302", 2004, "Chine" , 0.2 );

  /* Nous n'avons pas encore le polymorphisme :-(
   * (=> pas moyen de faire sans copie ici :-( )  */
  cout << t1 << endl;
  cout << "Prix vente : " << t1.vente() << " francs" << endl;
  cout << t2 << endl;
  cout << "Prix vente : " << t2.vente() << " francs" << endl;
  cout << t3 << endl;
  cout << "Prix vente : " << t3.vente() << " francs" << endl;
  cout << t4 << endl;
  cout << "Prix vente : " << t4.vente() << " francs" << endl;

  return 0;
}
