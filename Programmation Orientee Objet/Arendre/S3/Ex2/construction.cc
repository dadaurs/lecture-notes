#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Pour simplifier
typedef string Forme   ;
typedef string Couleur ;

class Brique
{
private:
  Forme   forme   ;
  Couleur couleur ;

public:
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/
  Brique(Forme f, Couleur c):forme(f),couleur(c){}
  Brique()=delete;
  ostream& afficher(ostream& sortie) const {
  	if(couleur!="") {
  		sortie<< "(" << forme << ", " << couleur << ")";
  	}else {
  		sortie <<forme ;
  	}
	return sortie;
  	
  	
  }
  

};
ostream& operator<< (ostream& os, Brique b) {
	return b.afficher(os);
}

class Construction
{
  friend class Grader;
	private:
		vector<vector<vector<Brique>>> contenu;
	public:
		Construction(Brique b):contenu({{{b}}}) {}
		Construction(const Construction & b):contenu(b.contenu){}
		ostream& afficher(ostream& sortie) const {
			for(int i(contenu.size()-1);i>=0;--i) {
				sortie<<"Couche "<< i<< " :"<<endl;
				for(size_t j(0);j<contenu[i].size();++j) {
					for (size_t k(0);k<contenu[i][j].size();k++) {
						sortie<<contenu[i][j][k];
						
					}
					sortie<<endl;
					
				}
				
			}

			return sortie;
		}
		Brique get_el(unsigned int i, unsigned int j, unsigned int k ) const {
			return contenu[i][j][k];
		}
		unsigned int getHauteur() const {
			return contenu.size();
		}
		
		
		void operator^=(const Construction &c) {
			vector<vector<vector<Brique>>> C = c.getCont();
			for(auto a:C) {
				contenu.push_back(a);
			}
			
			
		}
		vector<vector<vector<Brique>>> getCont() const {
			return contenu;
		}
		
		
        void operator-=( const Construction& b) {
	if(contenu.size()>b.getHauteur())
		return;

	for(auto & i:contenu) {
		for(auto j: b.getCont()) {
			for(auto k: j) {
				i.push_back(k);
			}
			
			
		}
		

			
		}
		
	}
        void operator+=( const Construction& b) {
	if(contenu.size()>b.getHauteur())
		return;
	vector<vector<vector<Brique>>> B(b.getCont());

	for(size_t c(0);c<contenu.size();c++) {
		for(size_t l(0);l<contenu[c].size()&&l<B[c].size();l++) {
			for(size_t el(0);el<B[c][l].size();el++) {
				contenu[c][l].push_back(B[c][l][el]);
			}
			
		}
		
	}
	

		
	}
	
		
		

};
ostream& operator<< (ostream& os, Construction b) {
	return b.afficher(os);
}
const Construction operator^(Construction a, const Construction& b) {
	a^=b;
	return a;
}
const Construction operator-(Construction a, const Construction& b) {
	a-=b;
	return a;
}
const Construction operator+(Construction a, const Construction& b) {
	a+=b;
	return a;
}




const Construction operator*(unsigned int n, Construction const& a)
{
	Construction b(a);
	for(size_t i(0); i<n-1; ++i) {
		b+=a;
	}
	return b;
	
}

const Construction operator/(unsigned int n, Construction const& a)
{
	Construction b(a);
	for(size_t i(0); i<n-1; ++i) {
		b^=a;
	}
	return b;
}

const Construction operator%(unsigned int n, Construction const& a)
{
	Construction b(a);
	for(size_t i(0); i<n-1; ++i) {
		b-=a;
	}
	return b;
}


/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  // Modèles de briques
  Brique toitD("obliqueD", "rouge");
  Brique toitG("obliqueG", "rouge");
  Brique toitM(" pleine ", "rouge");
  Brique mur  (" pleine ", "blanc");
  Brique vide ("                 ", "");
  Construction c1(mur);
Construction c2(mur);
int n=3;

c2 ^= c1;
c1 += c2;
c1 -= c2;
c1-= n%c1;
c1 ^= n/c2;
cout<<c1;


  return 0;
}

