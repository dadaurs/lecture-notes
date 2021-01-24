#include <iostream>
using namespace std;

int main()
{
  cout << "Donnez l'heure de début de la location (un entier) : ";
  int debut;
  cin >> debut;

  cout << "Donnez l'heure de fin de la location (un entier) : ";
  int fin;
  cin >> fin;

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/
  int tpsa1,tpsa2;
  int tot;
  if(debut>fin){
    cout << "Bizarre, le début de la location est après la fin ..." << endl;
    return 0;
  }
  if(debut>24 || debut <0 || fin >24 || fin<0){
    cout << "Les heures doivent être comprises entre 0 et 24 !" << endl;
    return 0;
  }
  if(debut==fin){
   cout << "Bizarre, vous n'avez pas loué votre vélo bien longtemps !" << endl;
    return 0;
  }
  if(( debut<7 && fin <7  )|| (debut >17 && fin>17)){
	  tot=fin-debut;
	  tpsa1=tot;
	  tpsa2=0;
	  
  }
  if(debut<7 && fin>7 && fin <17){
	  tpsa1=7-debut;
	  tpsa2=fin-7;
	  tot=(7-debut)+2*(fin-7);
  }
  if(debut>=7 && fin<=17 && fin>7){
	  tpsa1=0;
	  tpsa2=fin-debut;
	  tot= 2*tpsa2;
  }
  if(debut<7 && fin >17){
	  tpsa1=7-debut+fin-17;
	  tpsa2=10;
	  tot= (7-debut) + 20 + (fin-17);
  }
  if(debut>=7 && fin>17 && debut < 17){
	  tpsa2=17-debut;
	  tpsa1=fin-17;
	  tot=tpsa1+ 2*tpsa2;

  }
   cout << "Vous avez loué votre vélo pendant" <<  endl;
  if(tpsa1!=0){
      cout << tpsa1 << " heure(s) au tarif horaire de " << 1 << " franc(s)" << endl;
  }
  if(tpsa2!=0){
      cout << tpsa2 << " heure(s) au tarif horaire de " << 2 << " franc(s)" << endl;
  }

    cout << "Le montant total à payer est de " << tot
         << " franc(s)." << endl;

  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

  return 0;
}
