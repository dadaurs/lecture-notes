#include <iostream>
#include <vector>
#include <string>
using namespace std;



class Article {
	public:
		Article(string n, double p, bool s=false) {
			nom=n;
			prix=p;
			en_solde=s;
			solde=0;
		}
		
			
		double get_prix(){
			return prix- prix*solde;
		}
		string get_nom() {
			return nom;
		}
		bool get_action() {
			return en_solde;
		}
		
		

	private:
		bool en_solde;
		double solde;
		double prix;
		string nom;
};

class Achat {
	public:
		Achat(Article const& art, int quanti):ach(art){
			quant=quanti;
			prix=quant*ach.get_prix();

		}
		double get_prix() {
			return prix;
		}
		void afficher() {
			string nom=ach.get_nom();
			cout<<nom<<":"<<prix<<"x"<<quant<<"="<< quant * prix << "Frs";
			if(ach.get_action())
				cout<<"(en action)";
			cout<<endl;
		}
		
		

	private:
		Article ach;
		int quant;
		double prix;
		
};
class Caddie {
	public:
	vector<Achat> get_tout(){
		return tout;
	}
	void remplir(Article art, int num=1) {
		Achat a(art,num);
		tout.push_back(a);
	}
	

	private:
		vector<Achat> tout;
};

class Caisse  {
	public:
	void scanner(Caddie c){
		double subtot=0;
		for(auto i: c.get_tout()) {
		i.afficher();
		tot+=i.get_prix();
		subtot+=i.get_prix();
		}
		cout<<"Total a payer:"<< subtot <<"F."<<endl;
		
	}
	void afficher() {
		cout<<"La caisse"<< num<<"a encaisse"<<tot<<"Frs aujourd'hui."<<endl;
	}
	Caisse() {
		tot=0;
		num=1;
	}
	
	
	private:
		int num;
		double tot;
};
// ======================================================================
int main()
{
  // Les articles vendus dans le supermarché
  Article choufleur ("Chou-fleur extra"      ,  3.50 );
  Article roman     ("Les malheurs de Sophie", 16.50, true );
  Article camembert ("Cremeux 100%MG"        ,  5.80 );
  Article cdrom     ("C++ en trois jours"    , 48.50 );
  Article boisson   ("Petit-lait"            ,  2.50, true);
  Article petitspois("Pois surgeles"         ,  4.35 );
  Article poisson   ("Sardines"              ,  6.50 );
  Article biscuits  ("Cookies de grand-mere" ,  3.20 );
  Article poires    ("Poires Williams"       ,  4.80 );
  Article cafe      ("100% Arabica"          ,  6.90, true);
  Article pain      ("Pain d'epautre"        ,  6.90 );

  // Les caddies du supermarché, disons 3 ici
  vector<Caddie> caddies(3);

  // Les caisses du supermarché, disons 2
  vector<Caisse> caisses(2);

  // Les clients font leurs achats :
  // le second argument de la méthode remplir correspond à une quantité

  // remplissage du 1er caddie
  caddies[0].remplir(choufleur, 2);
  caddies[0].remplir(cdrom       );
  caddies[0].remplir(biscuits , 4);
  caddies[0].remplir(boisson  , 6);
  caddies[0].remplir(poisson  , 2);

  // remplissage du 2eme caddie
  caddies[1].remplir(roman        );
  caddies[1].remplir(camembert    );
  caddies[1].remplir(petitspois, 2);
  caddies[1].remplir(poires    , 2);

  // remplissage du 3eme caddie
  caddies[2].remplir(cafe     , 2);
  caddies[2].remplir(pain        );
  caddies[2].remplir(camembert, 2);

  // Les clients passent à la caisse :
  caisses[0].scanner(caddies[0]);
  cout << "=========================================" << endl;
  caisses[0].scanner(caddies[1]);
  cout << "=========================================" << endl;
  caisses[1].scanner(caddies[2]);
  cout << "=========================================" << endl;

  // Affichage du résultat des caisses
  cout << "Résultats du jour :" << endl;
  for (size_t i(0); i < caisses.size(); ++i) {
    cout << "Caisse " << i+1 << " : " ;
    caisses[i].afficher();
    cout << endl;
  }

  return 0;
}
