#include <iostream>
#include <vector>
using namespace std;

/*******************************************
 * Complétez le programme à partir d'ici.
 *******************************************/
typedef vector<vector<int>> Carte;
struct Position{
	int i;
	int j;
};
bool binaire(Carte const& carte){
	for(auto i: carte){
		for(auto j: i){
			if (not ( j==0 || j==0 )){
				return false;
			}
		}
	}
	return true;
}
void affiche(Carte const& carte){
	for(auto i: carte){
		for(auto j: i){
			cout<< j;
			}
		cout<<endl;
		}
cout<<"----"<<endl;
}
size_t trouver_premier1(vector<int>& tab){
	int i=0;
	while(tab[i]==0){
		i++;
	}
	return i;
}
size_t trouver_dernier1(vector<int>& tab){
	int i=tab.size();
	while(tab[i]==0){
		i--;
	}
	return i;
}
void effacer_etang(vector<int>& tab){
	size_t deb=trouver_premier1(tab);
	size_t fin=trouver_dernier1(tab);
	for(size_t i(deb); i<fin;i++){
		tab[i]=1;

		}

}
bool verifie_et_modifie(Carte& carte){
	if(binaire(carte)){
		cout<< "Votre carte du terrain ne contient pas que des 0 et des 1."<<endl;
		return false;
	}
	for(size_t i=0;i<carte.size();++i){
				effacer_etang(carte[i]);
			}

	return true;
}
int check_autour(Carte carte, size_t i, size_t j){
	int ret=0;
	if(j>0 && i>0 && i<carte.size()-1 && j < carte[i].size()-1 ){
		if(carte[i][j-1]==0){++ret;}
		if(carte[i-1][j]==0){++ret;}
		if(carte[i+1][j]==0){++ret;}
		if(carte[i][j+1]==0){++ret;}
	}else if(i==0 && j==0){
		if(carte[i+1][j]==0){++ret;}
		if(carte[i][j+1]==0){++ret;}
	}else if(j==0){
		if(carte[i-1][j]==0){++ret;}
		if(carte[i+1][j]==0){++ret;}
		if(carte[i][j+1]==0){++ret;}
	}else if(i==0){
		if(carte[i][j-1]==0){++ret;}
		if(carte[i+1][j]==0){++ret;}
		if(carte[i][j+1]==0){++ret;}
	}else if(j==carte[i].size()-1&& i==carte.size()-1){
		if(carte[i][j-1]==0){++ret;}
		if(carte[i-1][j]==0){++ret;}
	}else if(i==carte.size()-1){
		if(carte[i][j-1]==0){++ret;}
		if(carte[i-1][j]==0){++ret;}
		if(carte[i][j+1]==0){++ret;}
	}else if(j==carte[i].size()-1){
		if(carte[i][j-1]==0){++ret;}
		if(carte[i-1][j]==0){++ret;}
		if(carte[i+1][j]==0){++ret;}
	}else{
		return 0;
	}
	return ret;

}	
double longueur_cloture(Carte const& carte, double echelle= 2.5){
	double longueur=0;
	for(size_t i(0);i<carte.size();++i){
		for(size_t j(i);j<carte[i].size();++j){
			if(carte[i][j]==1){
			longueur+=echelle *check_autour(carte,i,j);
			}
		}
	}
	return longueur;
}
void ajoute_unique(vector<int>& ensemble, int valeur)
{
}
bool convexite_lignes(Carte& carte, vector<int> const& labels_bords)
{
return true;
}
bool convexite_lignes(Carte& carte)
{
return true;
}

          //cout << "Votre carte du terrain n'est pas convexe par lignes :" << endl;
          //cout << "bord extérieur entrant trouvé en position [";
          //cout << "][";
          //cout << "]" << endl;


/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  Carte carte = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
  };

  cout << "Carte au départ :" << endl;
  affiche(carte);
  if (verifie_et_modifie(carte)) {
    cout << "Carte après modification :" << endl;
    affiche(carte);
    cout << "Il vous faut " << longueur_cloture(carte)
         << " mètres de clôture pour votre terrain."
         << endl;
  }

  return 0;
}
