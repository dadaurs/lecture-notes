#include <iostream>
using namespace std;
#define eps 0.01
class Point3D{
	public:
		void init(double a, double b, double c){
			x=a;
			y=b;
			z=c;
		}
		void affiche(){
			cout<<x<<y<<z<<endl;
		}
		double getx(){
			return x;
		}
		double gety(){
			return y;
		}
		double getz(){
			return z;
		}
		bool compare(Point3D p){
			if( abs(p.getx()-x)<eps and abs(p.gety()-y)<eps and abs(p.getz()-z)<eps)
				return true;
			return false;
		}

	protected:
		double x;
		double y;
		double z;
};
class Vecteur: public Point3D {
	public:
	Vecteur& Vecteur:operator+=(const Vecteur& v) {
		x+=v.getx();
		y+=v.gety();
		return this;	
	}
	Vecteur& Vecteur:operator-=(const Vecteur& v) {
		x-=v.getx();
		y-=v.gety();
		return this;
	}
	const Vecteur operator-() const {
		x=-x;
		y=-y
	}
	
	

};

const Vecteur operator+(Vecteur a, const Vecteur & b) {
	a+=b;
	return a;
	
}

const Vecteur operator-(Vecteur a, const Vecteur & b) {
	a-=b;
	return a;
	
}



int main(){
	Point3D point1;
Point3D point2;
Point3D point3;
point1.init(1.0, 2.0, -0.1);
point2.init(2.6, 3.5, 4.1);
point3 = point1;
cout << "Point 1 :";
point1.affiche();
cout << "Point 2 :";
point2.affiche();
cout << "Le point 1 est ";
if (point1.compare(point2)) {
cout << "identique au";
} else {
cout << "différent du";
}
cout << " point 2." << endl;
cout << "Le point 1 est ";
if (point1.compare(point3)) {
	cout << "identique au";
} else {
cout << "différent du";
}
cout << " point 3." << endl;

return 0;
}
