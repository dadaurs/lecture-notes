#include <iostream>
#include <ctime>

// pour les nombres alÃ©atoires
#include <random>
#include <cstring> // strlen

using namespace std;

// ======================================================================
// Couleur au hasard
std::uniform_int_distribution<int> distribution;
std::default_random_engine generateur(time(NULL)); /* NOT using std::random_device since not
                                                    * all compilers seems to support it :-( */

char tirer_couleur()
{
  static const char* const couleurs = ".RGBCYM";
  static const int nb = strlen(couleurs) - 1;

  return couleurs[distribution(generateur,
                               std::uniform_int_distribution<int>::param_type {0, nb})];
}

// ======================================================================
char poser_question()
{
  char lu(' ');
  cout << "Entrez une couleur : ";
  cin >> lu;
  return lu;
}

// ---- prototype -------------------------------------------------------
bool couleur_valide(char c);

// ======================================================================
char lire_couleur()
{
  char lu(poser_question());
  while (not couleur_valide(lu)) {
    cout << "'" << lu << "' n'est pas une couleur valide." << endl;
    cout << "Les couleurs possibles sont : ., R, G, B, C, Y ou M." << endl;
    lu = poser_question();
  }
  return lu;
}

// ======================================================================
void afficher_couleurs(char c1, char c2, char c3, char c4)
{
  cout << ' ' << c1 << ' ' << c2 << ' ' << c3 << ' ' << c4;
}

// ======================================================================
void afficher(int nb, char c)
{
  while (nb-- > 0) {
    cout << c;
  }
}

// ---- prototype -------------------------------------------------------
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char r1, char r2, char r3, char r4);

// ======================================================================
void afficher_coup(char c1, char c2, char c3, char c4,
                   char r1, char r2, char r3, char r4)
{
  afficher_couleurs(c1, c2, c3, c4);
  cout << " : ";
  afficher_reponses(c1, c2, c3, c4,
                    r1, r2, r3, r4);
  cout << endl;
}

// ======================================================================
void message_gagne(int nb_coups)
{
  cout << "Bravo ! Vous avez trouvÃ© en " << nb_coups << " coups." << endl;
}

// ======================================================================
void message_perdu(char c1, char c2, char c3, char c4)
{
  cout << "Perdu :-(" << endl;
  cout << "La bonne combinaison était : ";
  afficher_couleurs(c1, c2, c3, c4);
  cout << endl;
}

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

// ======================================================================
bool couleur_valide(char c)
{
	if(c=='.' || c == 'R' || c=='G' || c=='B'|| c=='C'|| c=='Y' || c== 'M')
		return true;
	return false;
}

// ======================================================================
bool verifier(char a, char &b, int &score)
{
	if(a==b){
		b='x';
		score++;
		return true;
	}
	return false;
}

// ======================================================================
void apparier(char test,char &cand1,char &cand2, char &cand3, int &num)
{
	if(verifier(test,cand1,num)){
		++num;
	}else{
	if(verifier(test,cand2,num)){
		++num;
	}else{
	if(verifier(test,cand3,num))
		++num;
	}
	}

}

// ======================================================================
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char r1, char r2, char r3, char r4)
{
	int bonnecol=0;
	if(c1==r1)
		++bonnecol;
	if(c2==r2)
		++bonnecol;
	if(c3==r3)
		++bonnecol;
	if(c4==r4)
		++bonnecol;
	afficher(bonnecol, '#');
	int malplace=0;
	apparier(c1,r4,r2,r3,malplace);
	apparier(c2,r4,r1,r3,malplace);
	apparier(c3,r4,r1,r2,malplace);
	apparier(c4,r3,r1,r2,malplace);
	afficher(malplace,'+');
	afficher(4-malplace,'-');



}

// ======================================================================
bool gagne(char c1, char c2, char c3, char c4,
           char r1, char r2, char r3, char r4)
{
	if(c1==r1 && c2==r2 && c3==r3 && c4==r4)
		return true;
	return false;
}

// ======================================================================
void jouer(int nbmax=8)
{
	char r1=tirer_couleur();
	char r2=tirer_couleur();
	char r3=tirer_couleur();
	char r4=tirer_couleur();
	char c1,c2,c3,c4;
	int nbcoups=0;
	int nmax=8;
	while(!gagne(c1,c2,c3,c4,r1,r2,r3,r4) && nbcoups <=nmax){
			c1=lire_couleur();
			c2=lire_couleur();
			c3=lire_couleur();
			c4=lire_couleur();
			afficher_coup(c1,c2,c3,c4,r1,r2,r3,r4);
			nbcoups++;
	}
	if(gagne(c1,c2,c3,c4,r1,r2,r3,r4)){
		message_gagne(nbcoups);
	}else
		message_perdu(c1,c2,c3,c4);

}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  jouer();
  return 0;
}
