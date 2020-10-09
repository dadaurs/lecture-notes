#include <iostream>
#include <iomanip> // pour setprecision()
using namespace std;

int main()
{
  // Réduire le format d'affichage
  cout << setprecision(4);

  // Paramètres
  double taux_croissance_lapins(0.3);
  double taux_attaque(0.01);
  double taux_croissance_renards(0.008);
  double taux_mortalite(0.1);
  int duree(50);

  double renards_i(0.0);
  double lapins_i(0.0);

  /*****************************************************
   * Compléter le code à  partir d'ici
   *****************************************************/

  // ===== PARTIE 1 =====
  // Saisie des populations initiales

  do{
  cout << "Combien de renards au départ (>= 2) ? ";
  cin >> renards_i;
  } while ( renards_i < 2 );


  do{
  cout << "Combien de lapins au départ  (>= 5) ? ";
  cin >> lapins_i;
  } while ( lapins_i < 5 );

  // ===== PARTIE 2 =====
  // PremiÃ¨re simulation
  cout <<  endl << "***** Le taux d'attaque vaut "<< taux_attaque * 100 << "%" <<  endl;
  double plapins = lapins_i;
  double prenards = renards_i;
  double lapins = plapins;

  double renards = prenards;
  for(int i = 1; i<=duree;++i){
	lapins *= (1.0 + taux_croissance_lapins - taux_attaque * prenards);
	renards *= (1.0 + taux_attaque * plapins * taux_croissance_renards - taux_mortalite);
	cout << "Après" << i << " mois, il y a " << lapins << " et " << renards << " renards" << endl;
	prenards = renards;
	plapins = lapins;

  }

  // ===== PARTIE 3 =====
  // Variation du taux d'attaque
  cout << endl;

  double taux_debut;
  double taux_fin;
  do{
  cout << "taux d'attaque au départ en % (entre 0.5 et 6) ? ";
  cin >> taux_debut;
  } while(taux_debut<0.5 || taux_debut > 6);

  do {
  cout << "taux d'attaque à  la fin  en % (entre "<< taux_debut ;
  cout << " et 6) ? ";
  cin >> taux_fin;
  } while (taux_fin < taux_debut || taux_fin > 6);

  //cout << "mais la population est remontée ! Ouf !" << endl;
  //cout << "et les renards ont disparu :-(" << endl;
  //cout << "mais la population est remontée ! Ouf !" << endl;

  double perc;
  for ( int taux= taux_debut; taux <= taux_fin; taux+=1){
  cout <<  endl << "***** Le taux d'attaque vaut "<< perc << "%" <<  endl;
  bool extinction_renards=false;
  bool extinction_lapins=false;
  bool pop_renards_ouf=false;
  bool pop_lapins_ouf=false;
  bool renards_pouf=false;
  bool lapins_pouf=false;
  bool pouf=false;
  perc= taux/100;
  plapins = lapins_i;
  prenards = renards_i;

  for(int i = 1; i<=duree;++i){
	lapins *= (1.0 + taux_croissance_lapins -  perc * prenards );
	renards *= (1.0 + perc * plapins * taux_croissance_renards - taux_mortalite);
	if(extinction_lapins && lapins > 5 && !pop_lapins_ouf){
		pop_lapins_ouf = true;
	}
	if(extinction_renards && renards > 5 && !pop_renards_ouf){
		pop_renards_ouf = true;
	}
	if(lapins < 5){
		extinction_lapins=true;
	}
	if (renards < 5){
		extinction_renards=true;
	}
	if( renards < 2){
		renards_pouf=true;
		renards=0;
		pouf=true;
	}
	if( lapins < 2){
		lapins_pouf=true;
		lapins=0;
		pouf=true;
	}
	

	prenards = renards;
	plapins = lapins;


  }
  if(!extinction_renards && !extinction_lapins && !pouf){
  cout << "Après" << duree << " mois, il y a " << lapins << " lapins et " << renards << " renards." << endl;
  cout << "Les lapins et les renards ont des populations stables." << endl;
  }
  if( extinction_renards ){
  cout << "Après" << duree << " mois, il y a " << lapins << " lapins et " << renards << " renards." << endl;
  cout << "Les renards ont été en voie d'extinction" << endl;
	  if( pop_renards_ouf ){
	  cout << "mais la population est remontée ! Ouf !" << endl;
	  }else if(renards_pouf){
  		cout << "et les renards ont disparu :-(" << endl;
	  }
  }
  if (extinction_lapins){
  cout << "Les lapins ont été en voie d'extinction" << endl;
  	if(pop_lapins_ouf){
	 cout << "mais la population est remontée ! Ouf !" << endl;
	} else if (lapins_pouf){
  	cout << "et les lapins ont disparu :-(" << endl;
	}
  }
  }

  /*******************************************
   * Ne rien modifier aprÃ¨s cette ligne.
   *******************************************/

  return 0;
}
