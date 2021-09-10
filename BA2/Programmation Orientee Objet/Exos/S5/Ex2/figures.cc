#include <iostream>
#include <memory>
#include <vector>

using namespace std;
class Figure {
	public:
		virtual void affiche() const=0;
		virtual Figure* copie() const=0;
	
};

class Cercle: public Figure {
	private:
		double r;
	public:
		Cercle(double R=1):r(R) {}
		Cercle(const Cercle& c):r(c.r){}

		//~Cercle() {
			//delete this;
		//}
		Figure* copie() const {
			return new Cercle(*this);
		}
		void affiche() const {
			cout<<"Cercle"<<r<<endl;
		}
		
		
			
};
class Carre: public Figure {
	private:
		double c;
	public:
		Carre(double C=1): c(C) {}
		Carre(const Carre& C): c(C.c) {}
		//~Carre(){
			//delete this;
		//}
		Figure* copie() const {
			return new Carre(*this);
		}
		void affiche () const {
			cout<<"carre"<<c<<endl;
		}

};
class Triangle: public Figure {
	private:
		double b;
		double h;
	public:
		Triangle(double B=1, double H=1): b(B), h(H) {}
		Triangle(const Triangle& t): b(t.b), h(t.h) {}
		//~Triangle () {
			//delete this;
		//}
		Figure*  copie() const {
			return new Triangle(*this);
		}
		
		
		void affiche()  const {
			cout<<"Triangle"<<b<<h<<endl;
		}
	
};
class Dessin {
	private:
		vector<Figure*> el;
	public:
		~Dessin() {
			cout<<"Je detruis tout"<<endl;
			//for(auto &i: el) {
				//delete i;
			//}
			el.clear();
		}
	void ajouteFigure(Figure const& fig) {
		el.push_back(fig.copie());
	}
	
	void affiche() {
		for(auto const & i: el) {
			i->affiche();
		}
		
	}
	
		
};







int main() {
Dessin dessin;
dessin.ajouteFigure(Triangle(3,4));
dessin.ajouteFigure(Carre(2));
dessin.ajouteFigure(Triangle(6,1));
dessin.ajouteFigure(Cercle(12));
cout << endl << "Affichage du dessin : " << endl;
dessin.affiche();
}
