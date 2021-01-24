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
	int nbav=0;
	int i=1;
	//bool tamere=false;
	//nbav=separer_chiffre_gauche(nombre);
	if(nombre==0){
		dire_chiffre(res,1,nbav);
		return res;
	}
	do{
		nb=separer_chiffre_gauche(nombre);
		if(nbav==nb){
		while(nbav==nb){
			i++;
			nb=separer_chiffre_gauche(nombre);
		}
			dire_chiffre(res,i,nbav);	
			i=1;
			nbav=nb;
	}while(nombre!=0);
	//if(tamere){
	//dire_chiffre(res,i,nbav);	
	//}
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
  int nombre(1);
  int fois(1);
  cin >> nombre >> fois;
  repeter_lire_et_dire(nombre, fois);
  cout << nombre << endl;
  return 0;
}
