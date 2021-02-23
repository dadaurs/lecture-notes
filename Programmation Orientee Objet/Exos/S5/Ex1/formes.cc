#include <iostream>
using namespace std;
#define PI 3.1415

class Forme {
	public:
		virtual void description() {
			cout << "Wesh"<<endl;
		}
		virtual double aire()=0;
		
};
class Cercle: public Forme{
	private:
		double rayon;
	public:
		Cercle(double r): rayon(r) {}
		void description() {
			cout <<"Chui un cercle"<<endl;
		}
		double aire() {
			return PI* rayon *rayon;
		}
		
		
};
class Triangle:public Forme {
	private:
		double base;
		double hauteur;
	public:
		Triangle(double b, double h): base(b), hauteur(h) {}
		double aire() {
			return 0.5 * base * hauteur;
		}
		
		
	
};

void affichageDesc(Forme& f) {
	f.description();
	cout<< f.aire() <<endl;

}




int main() {
Cercle c(5);
Triangle t(10, 2);
affichageDesc(t);
affichageDesc(c);
return 0;
}
