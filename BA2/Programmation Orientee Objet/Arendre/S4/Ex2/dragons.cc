#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int distance(int x, int y)
{
  return abs(x - y);
}

class Creature
{
  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/
	protected:
		string nom_;
		int niveau_;
		int points_de_vie_;
		int force_;
		int position_;
	public:
		Creature(string n, int nv, int pts, int f, int pos=0 ):nom_(n),niveau_(nv),points_de_vie_(pts), force_(f), position_(pos) {}
		bool vivant() {
			return points_de_vie_>0;
		}
		int points_attaque() {
			if(vivant()){
			return niveau_ * force_;
			}
			return 0;
		}
		int position() {
			return position_;
		}
		
		void deplacer(int a) {
			if(vivant())
				position_+=a;
		}
		void adieux() {
			cout << nom_ <<" n'est plus!"<<endl;
		}
		void faiblir(int p) {
			points_de_vie_ = points_de_vie_-p;
			if(!vivant()) {
				points_de_vie_=0;
				adieux();
				
			}
			
			
		}
		void afficher() {
			cout<< nom_ << ", niveau: " << niveau_ << ", points de vie: "<< points_de_vie_
         << ", force: "
	 << force_
         << ", points d'attaque: "
	 << points_attaque()
         << ", position: "
	 << position_
	 <<endl;

		}
		
		
		
		
		
		

         //<< ", niveau: "
         //<< ", points de vie: "

};
class Dragon:public Creature {
	private:
	int portee_flamme_;
	public:
	Dragon(string n, int nv, int pts, int f, int p, int pos=0):
		Creature(n,nv,pts,f,pos),
		portee_flamme_(p)
	{}
	void voler(int p) {
		if(vivant())
			position_=p;
	}
	void souffle_sur(Creature& b) {
		if(vivant() && b.vivant() && distance( b.position(),position_ ) < portee_flamme_) {
			b.faiblir( points_attaque());
			faiblir(distance(b.position() , position_));
		}else {
			return;
		}
		
		if(vivant()&& !b.vivant()) {
			niveau_++;
		}
		 
		
	}
	
	
	
};
class Hydre: public Creature {
	private:
		int longueur_cou_;
		int dose_poison_;
	public:
		Hydre(string n, int nv, int pts, int f, int l, int d, int pos=0)
			: Creature(n,nv,pts,f, pos),
			longueur_cou_(l),
			dose_poison_(d)
	{}
		void empoisonne(Creature& b) {
			if(vivant() && b.vivant() && distance(position_,b.position())<longueur_cou_) {
				b.faiblir(points_attaque()+dose_poison_);


			}else {
				return;
			}
			
			if(vivant() && !b.vivant()) {
				niveau_++;
			}
			
			
		}
		
	
};
void combat(Dragon & d, Hydre & h) {
	h.empoisonne(d);
	d.souffle_sur(h);
}



/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/
int main()
{
  Dragon dragon("Dragon rouge"   , 2, 10, 3, 20         );
  Hydre  hydre ("Hydre maléfique", 2, 10, 1, 10, 1,  42 );

  dragon.afficher();
  cout << "se prépare au combat avec :" << endl;
  hydre.afficher();

  cout << endl;
  cout << "1er combat :" << endl;
  cout << "    les créatures ne sont pas à portée, donc ne peuvent pas s'attaquer."
       << endl;
  combat(dragon, hydre);

  cout << "Après le combat :" << endl;
  dragon.afficher();
  hydre.afficher();

  cout << endl;
  cout << "Le dragon vole à proximité de l'hydre :" << endl;
  dragon.voler(hydre.position() - 1);
  dragon.afficher();

  cout << endl;
  cout << "L'hydre recule d'un pas :" << endl;
  hydre.deplacer(1);
  hydre.afficher();

  cout << endl;
  cout << "2e combat :" << endl;
  cout << "\
  + l'hydre inflige au dragon une attaque de 3 points\n\
      [ niveau (2) * force (1) + poison (1) = 3 ] ;\n\
  + le dragon inflige à l'hydre une attaque de 6 points\n\
      [ niveau (2) * force (3) = 6 ] ;\n\
  + pendant son attaque, le dragon perd 2 points de vie supplémentaires\n\
       [ correspondant à la distance entre le dragon et l'hydre : 43 - 41 = 2 ].\
" << endl;
  combat(dragon, hydre);

  cout << "Après le combat :" << endl;
  dragon.afficher();
  hydre.afficher();

  cout << endl;
  cout << "Le dragon avance d'un pas :" << endl;
  dragon.deplacer(1);
  dragon.afficher();

  cout << endl;
  cout << "3e combat :" << endl;
  cout << "\
  + l'hydre inflige au dragon une attaque de 3 points\n\
      [ niveau (2) * force (1) + poison (1) = 3 ] ;\n\
  + le dragon inflige à l'hydre une attaque de 6 points\n\
      [ niveau (2) * force (3) = 6 ] ;\n\
  + pendant son attaque, le dragon perd 1 point de vie supplémentaire\n\
       [ correspondant à la distance entre le dragon et l'hydre : 43 - 42 = 1 ] ;\n\
  + l'hydre est vaincue et le dragon monte au niveau 3.\
" << endl;
  combat(dragon, hydre);

  cout << "Après le combat :" << endl;
  dragon.afficher();
  hydre.afficher();

  cout << endl;
  cout << "4e Combat :" << endl;
  cout << "    quand une créature est vaincue, rien ne se passe." << endl;
  combat(dragon, hydre);

  cout << "Après le combat :" << endl;
  dragon.afficher();
  hydre.afficher();

  return 0;
}
