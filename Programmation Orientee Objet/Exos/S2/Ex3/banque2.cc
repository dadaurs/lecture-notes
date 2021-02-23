#include <iostream>
using namespace std;


	void boucler_et_afficher(vector<Client> v){
		cout<<"Donees avant le bouclement des comptes:"<<endl;
		for(auto i:v){
		i.afficherClient();
		i.boucler();
		}
		cout<<"Donees apres le bouclement des comptes:"<<endl;
		for(auto i:v){
		i.afficherClient();
		}

	}
class Client {
	public:
	void bouclerCompte1() {
	  double interets(taux1 * solde1);
	  double nouveauSolde(solde1 + interets);
	  solde1=nouveauSolde;
	}
	void bouclerCompte2() {
	  double interets(taux2 * solde2);
	  double nouveauSolde(solde2 + interets);
	  solde2=nouveauSolde;
	}
	void boucler() {
		bouclerCompte1();
		bouclerCompte2();
	}
	
	

	void afficherClient() {
	if(masc)
	  cout << "Client " << nom << " de " << ville << endl;
	else
	  cout << "Cliente " << nom << " de " << ville << endl;


	  cout << "   Compte courant : " << solde1 << " francs" << endl;
	  cout << "   Compte épargne : " << solde2 << " francs" << endl;
	}

	private:
	  string nom;
	  string ville;
	  double solde1;
	  double solde2;
	  double taux1;
	  double taux2;
	  bool masc;
}
	
};



int main(){

return 0;
}
