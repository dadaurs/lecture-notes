#include <iostream>
#include <string>
using namespace std;

class Souris
{
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/
	private:
		double poids;
		string couleur;
		unsigned int age;
		unsigned int esperance_vie;
		bool clonee=false;
	public:
		Souris(double p, string coul,unsigned int a=0,unsigned int esp=36) {
			cout<<"Une nouvelle souris !"<<endl;
			poids=p;
			couleur=coul;
			age=a;
			esperance_vie=esp;

			
		}
		Souris(const Souris& s)
			:poids(s.poids),couleur(s.couleur), age(s.age), esperance_vie((4.0/5)*s.esperance_vie){
				cout<<"Clonage d'une souris !"<<endl;
				clonee=true;

		}
		~Souris(){
			cout<<"Fin d'une souris..."<<endl;
		}
		void afficher() {
			cout<<"Une souris "<< couleur;
			if(clonee)
				cout<<", clonee,";
			cout<<" de "<< age<<" mois et pesant "<< poids << " grammes"<<endl;
		}
		void vieillir(){
		age++;
		}
		void evolue() {
			while(age<esperance_vie) {
				vieillir();
				if(age>(1/2)*esperance_vie && clonee)
					couleur="verte";
			}
			
		}
		
			
		


  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

}; // fin de la classe Souris

int main()
{
  Souris s1(50.0, "blanche", 2);
  Souris s2(45.0, "grise");
  Souris s3(s2);
  // ... un tableau peut-être...
  s1.afficher();
  s2.afficher();
  s3.afficher();
  s1.evolue();
  s2.evolue();
  s3.evolue();
  s1.afficher();
  s2.afficher();
  s3.afficher();
  return 0;
}
