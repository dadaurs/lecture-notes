#include <iostream>
using namespace std;

class Complexe {
	private:
		double x;
		double y;
	public:
	Complexe(double a=0, double b=0) :x(a),y(b) { }
	
		double getx() {
			return x;
		}
		double gety() {
			return y;
		}
	bool operator==(Complexe a) {
		if(x==a.getx() && y==a.gety())
			return true;
		return false;
	}
		
		
		
		

};
ostream& operator<<(ostream& os, Complexe c) {
	os<< c.getx()<<"+ i*"<<c.gety();
	return os;
}
Complexe & operator+(Complexe a, const Complexe & b) {
	Complexe c(a.getx()+b.getx(),a.gety()+b.gety());
	return &c;
	
}
Complexe & operator-(Complexe a, const Complexe & b) {
	Complexe c(-b.getx(),-b.gety());
	return a+c;
	
}

Complexe & operator+(double a, const Complexe & b) {
	Complexe c(a+b.getx(),b.gety());
	return &c;
	
}
Complexe & operator+(const Complexe & b,double a) {
	return a+b;
	
}
Complexe & operator-(double a,const Complexe & b) {
	Complexe c(a-b.getx(),b.gety());
	return &c;
}



int main(){
Complexe defaut;
Complexe zero(0.0,0.0);
Complexe un(1.0,0.0);
Complexe i(0.0,1.0);
cout << zero << "==?" << defaut;
if( zero==defaut) cout<< "oui" <<endl;
else cout << "non" <<endl;

return 0;
}
