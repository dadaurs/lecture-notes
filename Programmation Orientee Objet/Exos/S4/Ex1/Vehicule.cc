#include <iostream>
#include <vector>
using namespace std;
const int an=2021;
class Vehicule {
	protected:
		string marque;
		int date;
		double prix_achat;
		double prix_actuel;
	public:
		Vehicule(string m, int d, double pa):marque(m),date(d),prix_achat(pa) {}
		void affiche(ostream & os) const {
			os<<marque<< " "<<date<<" "<<prix_achat<<" "<<prix_actuel;
		}
		void calculePrix() {
			int nba= an-date;
			prix_actuel=prix_achat;
			for(int i=0;i<nba;++i) {
				prix_actuel -= ( 1.0/100 )*prix_achat;

				
			}
			

			
		}
		
		
};
class Voiture: public Vehicule {
	private:
		unsigned int cylindree;
		unsigned int nb_portes;
		double puissance;
		unsigned int kil;
	public:
		Voiture(string m, int d, double pa,unsigned int c, unsigned int n, double p, unsigned int k)
			:Vehicule(m,d,pa),
			cylindree(c),
			nb_portes(n),
			puissance(p),
			kil(k)
	{}
			
	void affiche(ostream & os) {
		Vehicule::affiche(os);
		os<<cylindree<<" "<<nb_portes<< " "<< puissance<< " "<< kil<<endl;
	}
	void calculePrix() {
			int nba= an-date;
			prix_actuel=prix_achat;
			for(int i=0;i<nba;++i) {
				prix_actuel -= ( 2.0/100 )*prix_actuel;

				
			}
			int tranche=( kil-( kil%10000 ) )/10000;
			for(int i=0;i<tranche;++i) {
				prix_actuel -= ( 5.0/100 )*prix_actuel;
			}
			if(marque=="Renault" || marque=="Fiat" ) {
				prix_actuel -= ( 1.0/10 )*prix_actuel;
			}
			if(marque=="Ferrari" || marque=="Porsche" ) {
				prix_actuel += ( 2.0/10 )*prix_actuel;
			}
			if(prix_actuel<0) {
				prix_actuel=0;
			}
			
			
			
		
	}
	

};
class Avion : public Vehicule {
	private:
		string t;
		unsigned int nb_heure;
	public:
		Avion(string m, int d, double pa,string ty, unsigned int n)
			:Vehicule(m,d,pa),
			t(ty),
			nb_heure(n)
	{}
		void affiche(ostream & os) {
			Vehicule::affiche(os);
			os<<t<<" "<<nb_heure<<endl;
		}

		void calculePrix() {
			prix_actuel=prix_achat;
			if(t=="react") {
				for(int i(0);i<(int)( nb_heure/1000 );++i){
				prix_actuel-=(1.0/10) *prix_actuel;
				}
			} else {
				for(int i(0);i<(int)( nb_heure/100 );++i){
				prix_actuel-=(1.0/10) *prix_actuel;
				}
			}
			if(prix_actuel<0) {
				prix_actuel=0;
			}
			
			
			
		}
		
		
	
};






int main()
{
vector<Voiture> garage;
vector<Avion> hangar;
garage.push_back(Voiture("Peugeot", 1998, 147325.79, 2.5, 5, 180.0,
12000));
garage.push_back(Voiture("Porsche", 1985, 250000.00, 6.5, 2, 280.0,
81320));
garage.push_back(Voiture("Fiat", 2001, 7327.30, 1.6, 3, 65.0,
3000));
hangar.push_back(Avion("Cessna", 1972, 1230673.90, "Hel",
250));
hangar.push_back(Avion("Nain Connu", 1992, 4321098.00, "react",
1300));
for (auto voiture : garage) {
voiture.calculePrix();
voiture.affiche(cout);
}
for (auto avion : hangar) {
avion.calculePrix();
avion.affiche(cout);
}
return 0;
}
