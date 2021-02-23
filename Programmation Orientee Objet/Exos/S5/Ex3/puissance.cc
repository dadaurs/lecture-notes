#include <iostream>
#include <vector>
using namespace std;
enum Couleur { rouge, jaune, vide};

class Joueur {
	private:
	Couleur c;
	string nom;
	public:
	void jouer(Jeu&)=0;
};
class Jeu {
	private:
		vector<vector<Couleur>> table;
	public:
		Jeu(int taille=8):table(taille,vector<Couleur>(taille)) {}
		bool jouer(int nbcol, Couleur c) {
			if(nbcol > table.size()-1) 
				return false;
			if(table[nbcol].back() != vide ) 
				return false;
			for(auto & i: table[nbcol]) {
				if(i==vide) {
					i==c;
					return true;
				}
				
			}
			return false;
			


		}
		bool gagne_vert(Couleur c) {
			int compt=0;
			for(auto i: table) {
				for(size_t j(0); j<i.size()-1;++i) {
					if(i[j]==i[j+1]) {
						compt++;
					}else {
						compt=0;
					}
					if(compt>=4) {
						return true;
					}
				}
				
			}
			return false;
			
		}
		bool gagne_horiz(Couleur c) {
			int compt=0;
			for(size_t i(0);i<table.size();++i) {
				for(size_t j(0);j<table.size();++j) {
					if(table[j][i]==table[j+1][i]) {
						compt++;
					}else {
						compt=0;
					}
					if(compt>=4) {
						return true;
					}
				}
				
			}
			return false;
			
		}
		
		
		
		Couleur gagnant() {
			if(gagne_horiz(rouge) || gagne_vert(rouge) ) {
				return rouge;
			} else if(gagne_horiz(jaune) || gagne_vert(jaune) ) {
				return jaune;
			}
			return vide;
			
			
		}
		
};
class Humain: public Joueur {
	public:
		void jouer(Jeu& j) {
			while
		}
		
}




int main(){

return 0;
}
