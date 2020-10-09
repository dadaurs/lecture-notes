#include <iostream>
using namespace std;

int separer_chiffre_gauche(int& nombre)
{
  int dix(1);
  int temp(nombre);
  while (temp >= 10) {
    dix  *= 10;
    temp /= 10;
  }
  nombre %= dix;
  return temp;
}

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

void ajouter_chiffre_droit(int& nombre, int chiffre)
{
	if(chiffre!=0){
	nombre= 10*nombre + chiffre;
	}
}

void dire_chiffre(int& nombre, int repetitions_chiffre, int chiffre)
{
	ajouter_chiffre_droit(nombre,repetitions_chiffre);
	ajouter_chiffre_droit(nombre,chiffre);
}

int lire_et_dire(int nombre)
{
	int res=0;
	int nb;
	int nbav;
	int i=1;
	nbav=separer_chiffre_gauche(nombre);
	while(nombre!=0){
		nb=separer_chiffre_gauche(nombre);
		if(nb!=nbav){
			dire_chiffre(res,i,nb);	
			i=1;
		}else{
			i++;
		}
		nbav=nb;
	}
	return res;
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void repeter_lire_et_dire(int& nombre, int fois)
{
  while (fois-- > 0) {
    nombre = lire_et_dire(nombre);
  }
}

int main()
{
  int nombre(1234);
  int fois(1);
  int res=separer_chiffre_gauche(nombre);
  cout<< nombre << endl<< res<<endl;
  //cin >> nombre >> fois;
  //repeter_lire_et_dire(nombre, fois);
  //cout << nombre << endl;
  return 0;
}
