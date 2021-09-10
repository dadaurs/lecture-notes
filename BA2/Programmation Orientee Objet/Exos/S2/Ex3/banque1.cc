#include <iostream>
#include <string>
using namespace std;

// Cette fonction affiche les données d'un client
void afficherClient(string nom, string ville,
                    double solde1, double solde2) {
  cout << "Client " << nom << " de " << ville << endl;
  cout << "   Compte courant : " << solde1 << " francs" << endl;
  cout << "   Compte épargne : " << solde2 << " francs" << endl;
}

// Cette fonction ajoute les intérêts au solde d'un compte
double bouclerCompte(double solde, double taux) {
  double interets(taux * solde);
  double nouveauSolde(solde + interets);
  return nouveauSolde;
}

int main()
{
  // Données pour tous les comptes privés (taux d'intérêt) :
  double taux1(0.01);
  // Données pour tous les comptes d'épargne (taux d'intérêt) :
  double taux2(0.02);
  // Données pour le premier client (nom et ville) :
  string nom1("Pedro");
  string ville1("Genève");
  // Données pour le compte privé du premier client (solde) :
  double solde1PremierClient(1000.0);
  // Données pour le compte d'épargne du premier client (solde) :
  double solde2PremierClient(2000.0);
  // Données pour le deuxième client (nom et ville) :
  string nom2("Alexandra");
  string ville2("Lausanne");
  // Données pour le compte privé du deuxième client (solde) :
  double solde1DeuxiemeClient(3000.0);
  // Données pour le compte d'épargne du deuxième client (solde) :
  double solde2DeuxiemeClient(4000.0);

  cout << "Données avant le bouclement des comptes :" << endl;
  // Afficher les données du premier client :
  afficherClient(nom1, ville1, solde1PremierClient, solde2PremierClient);
  // Afficher les données du deuxième client:
  afficherClient(nom2, ville2, solde1DeuxiemeClient, solde2DeuxiemeClient);

  // Bouclement du compte privé du premier client:
  solde1PremierClient = bouclerCompte(solde1PremierClient, taux1);
  // Bouclement du compte d'épargne du premier client:
  solde2PremierClient = bouclerCompte(solde2PremierClient, taux2);
  // Bouclement du compte privé du deuxième client:
  solde1DeuxiemeClient = bouclerCompte(solde1DeuxiemeClient, taux1);
  // Bouclement du compte d'épargne du deuxième client:
  solde2DeuxiemeClient = bouclerCompte(solde2DeuxiemeClient, taux2);

  cout << "Données apres le bouclement des comptes :" << endl;
  // Afficher les données du premier client:
  afficherClient(nom1, ville1, solde1PremierClient, solde2PremierClient);
  // Afficher les données du deuxième client:
  afficherClient(nom2, ville2, solde1DeuxiemeClient, solde2DeuxiemeClient);

  return 0;
}
