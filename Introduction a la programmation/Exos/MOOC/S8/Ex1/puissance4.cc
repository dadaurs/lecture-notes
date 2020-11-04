#include <iostream>
#include <vector>
#include <array>
using namespace std;

enum Couleur { vide,rouge, jaune};

typedef  array<array<Couleur,7>,6> Grille;

void initialise(Grille &g){
	for(auto &i: g){
		for(auto &j: i){
			j = vide;
		}
	}
}
void affiche(const Grille& g){
	for(auto i:g){
	cout << " |";
		for(auto j:i){
			if (j == vide){
				cout << ' ';
			} else if (j == rouge){
				cout << 'O';
			}else{
				cout << 'X';
			}
		cout << '|';
		}
		cout<< endl;
	}
	cout << '=';
	for(size_t i(1);i <=g[0].size();++i){
		cout << '=' << i;
	}
	cout << "==";
	cout << endl << endl;
}
bool joue(Grille &g, size_t i, Couleur c){
	// on parcourt la colonne
	if(i>g[0].size())
		return false;
	size_t ligne(g.size()-1);
	while ((ligne<g.size()) && g[ligne][i]!=vide){
		--ligne;
	}
	if(ligne<g.size()){
	g[ligne][i]=c;
	return true;
	}
	return false;

}
void demander_et_jouer(Couleur joueur, Grille &g){
	if(joueur==jaune){
	cout<< " Joueur X: Entre un numero de collonne"<<endl;
	}else if(joueur==rouge){
	cout<< " Joueur O: Entre un numero de collonne"<<endl;
	}
	size_t colonne;
	bool valide;
	do{
	cin>> colonne;
	--colonne;
	valide=joue(g,colonne,joueur);
	if(not valide)
		cout<<"Ce coup n'est pas valide"<<endl;
	}while(not valide);

}
unsigned int compte(const Grille & g, size_t l, size_t c,int  dl, int dc){
	unsigned int compteur=0;
	size_t li(l);
	size_t col(c);
	while(li< g.size() and  col < g[li].size() and g[li][col] == g[dl][dc]){
		++compteur;
		li= li + dl;
		col = col+dc;
	}
	return compteur;



}
bool est_ce_gagne(Couleur joueur,const Grille &g){
	for(size_t l(0);l< g.size();++l){
		for(size_t c(0);c< g[l].size();++c){
			Couleur ccase(g[l][c]);
			if(ccase== joueur){
				if(compte(g,l,c,-1,1)>= 4 or
				compte(g,l,c,0,1)>= 4 or
				compte(g,l,c,1,1)>= 4 or
				compte(g,l,c,1,0)>= 4){
					return true;
				}

			}

		}

	}
return false;
}
bool plein(const Grille& g){
	for(auto kase: g[0]){
		if(kase==vide)
			return false;
	}
	return true;
}


int main(){
	Grille grille;
	initialise(grille);
	affiche(grille);
	Couleur joueur(jaune);
	bool gagne;
	do{
		demander_et_jouer(joueur, grille);
		affiche(grille);
		gagne= est_ce_gagne(joueur,grille);
		joueur= joueur ==jaune? rouge: jaune;

	}while(not gagne and not plein(grille));
	if(gagne){
	if(joueur== jaune)
		cout<< "Le joueur O a gagne"<<endl;
	else
		cout<< "Le joueur X a gagne"<<endl;
	}else{
		cout<< "Match Nul" <<endl;
	}


return 0;
}
