#include <iostream>
using namespace std;

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/
class Patient{
	public:
		void init(double p, double t){
			if(p>0 && t>0){
				_poids=p;
				_taille=t;
			}else{
				_poids=0;
				_taille=0;
			}

		}
		void afficher(){
			cout <<"Patient : "<< _poids <<" kg pour "<<_taille<<" m"<<endl;
		}
		double poids(){
			return _poids;
		}
		double taille(){
			return _taille;
		}
		double imc(){
			if(_taille==0){
				return 0;
			}
			return _poids/( _taille*_taille );
		}
	private:
		double _poids;
		double _taille;
};

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  Patient quidam;
  double poids, taille;
  do {
    cout << "Entrez un poids (kg) et une taille (m) : ";
    cin >> poids >> taille;
    quidam.init(poids, taille);
    quidam.afficher();
    cout << "IMC : " << quidam.imc() << endl;
  } while (poids * taille != 0.0);
  return 0;
}
