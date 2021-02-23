#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*******************************************
 * Completez le programme a partir d'ici.
 *******************************************/
// Chaines de caractères à utiliser pour les affichages:
/*

été jeté

d'un

n'est

L'oeuvre

bibliothèque

détruit

*/
class Auteur {
	public:
		Auteur(string n, bool p=false) {
			nom=n;
			p=false;

		}
		
		string getNom() const {
			return nom;
		}
		bool getPrix() const {
			return prime;
		}
		Auteur(Auteur const&) = delete;
		
		
	private:
		string nom;
		bool prime;
};
class Oeuvre {
	private:
		string titre;
		string langue;
		const Auteur & aut;
	public:
		Oeuvre(string t, Auteur & a, string l) :titre(t),langue(l),aut(a) {
		}
		Oeuvre(Oeuvre const &)=delete;

		string getTitre() const{
			return titre;
		}
		const Auteur & getAuteur() const{
			return aut;
		}
		string getLangue() const {
			return langue;
	              }
		void affiche() const {
			cout<<titre<<", "<<aut.getNom()<<", en "<<langue;
		}
		~Oeuvre() {
			cout<<"L'oeuvre \""<<titre<<", "<<aut.getNom()<<", en "<< langue<<"\" n'est plus disponible."<<endl;
		}

		//bool cmp(Oeuvre o) const {
			//const Auteur * a= &o.getAuteur();
			//if(o.getLangue()==langue && o.getTitre()==titre && *a->getNom()==*aut.getNom() && *a->getPrix== *aut.getPrix())
				//return true;
			//return false;
		//}
		
		
		
		
		
};
class Exemplaire {
	private:
	Oeuvre * oe;
	bool s;
	public:
		Exemplaire(Oeuvre & ov):oe(&ov){
			cout<<"Nouvel exemplaire de : ";
			ov.affiche();
		        cout<<endl;

		}
		Exemplaire(const Exemplaire& ov) {
		oe = ov.getOeuvre();
		cout<<"Copie d'un exemplaire de : ";
		oe->affiche();
		cout<<endl;

		}
		 Oeuvre * getOeuvre() const{
			return oe;
		}
		 
		void affiche() {
			cout<<"Exemplaire de : ";
			oe->affiche();
			cout<<endl;
		}
		
		~Exemplaire() {
			cout<<"Un exemplaire de \"";
			oe->affiche();
			cout<<"\" a été jeté !"<<endl;
		}
		
};
class Bibliotheque {
	private:
		vector<Exemplaire *> tout;
		string nom;
	public:
		Bibliotheque(string n) {
		nom=n;
		cout<<"La bibliothèque "<< nom << " est ouverte !"<<endl;
		}
		string getNom() {
			return nom;
		}
		void stocker(Oeuvre & ex, int nb=1) {
			for(int i=0;i<nb;++i) {
			Exemplaire * a= new Exemplaire(ex);
				tout.push_back(a);
			}
			
			
		}
		void lister_exemplaires(string langue="") {
			if(langue=="") {
				for(auto i: tout){
					i->affiche();
				}
				return;
			}
			
			for(auto i:tout) {
				Oeuvre * o=i->getOeuvre();
				if(langue==o->getLangue())
					i->affiche();
			}
			
			
		}
		int compter_exemplaires(Oeuvre & o) const {
			int res=0;
		for(auto i: tout){
			Oeuvre * oe = i->getOeuvre();
			if(o.getTitre()== oe->getTitre() && o.getLangue()== oe->getLangue()){
				res++;
			}
		}
				return res;
		}
		void afficher_auteurs(bool b=false) {
			if(b) {
			for(auto i: tout) {
				Oeuvre * o=i->getOeuvre();
				if(( o->getAuteur() ).getPrix()) {
					cout<<( o->getAuteur() ).getNom()<<endl;
					
				}
			}
				
			}else {
				for(auto i: tout) {
					Oeuvre * o=i->getOeuvre();
					cout<<( o->getAuteur() ).getNom()<<endl;
						
				}
			}
				
			}
			
			
	~Bibliotheque() {
		cout<<"La bibliothèque "<< nom << " ferme ses portes,"<<endl<<" et détruit ses exemplaires :"<<endl;
		for(auto i:tout) {
		delete i;
		}
		tout.clear();
		

	}
	
		
		
		
		
		

};





/*******************************************
 * Ne rien modifier apres cette ligne.
 *******************************************/

int main()
{
  Auteur a1("Victor Hugo"),
         a2("Alexandre Dumas"),
         a3("Raymond Queneau", true);

  Oeuvre o1("Les Misérables"           , a1, "français" ),
         o2("L'Homme qui rit"          , a1, "français" ),
         o3("Le Comte de Monte-Cristo" , a2, "français" ),
         o4("Zazie dans le métro"      , a3, "français" ),
         o5("The Count of Monte-Cristo", a2, "anglais" );

  Bibliotheque biblio("municipale");
  biblio.stocker(o1, 2);
  biblio.stocker(o2);
  biblio.stocker(o3, 3);
  biblio.stocker(o4);
  biblio.stocker(o5);

  cout << "La bibliothèque " << biblio.getNom()
       << " offre les exemplaires suivants :" << endl;
  biblio.lister_exemplaires();

  const string langue("anglais");
  cout << " Les exemplaires en "<< langue << " sont :" << endl;
  biblio.lister_exemplaires(langue);

  cout << " Les auteurs à succès sont :" << endl;
  biblio.afficher_auteurs(true);

  cout << " Il y a " << biblio.compter_exemplaires(o3) << " exemplaires de "
       << o3.getTitre() << endl;

  return 0;
}
