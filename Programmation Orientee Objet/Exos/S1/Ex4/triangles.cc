#include <iostream>
#include <cmath>
using namespace std;
#define eps 0.01
struct Point{
	double x;
	double y;
	double z;
};
class Triangle{
	public:
		void init(Point a, Point b, Point c){
			init1(a.x,a.y,a.z);
			init2(b.x,b.y,b.z);
			init3(c.x,c.y,c.z);
		}
		bool est_isocele(){
			double l1=(pow(p1.x-p2.x,2) +pow(p1.y-p2.y,2) + pow(p1.z-p2.z,2));
			double l2=(pow(p1.x-p3.x,2) +pow(p1.y-p3.y,2) + pow(p1.z-p3.z,2));
			double l3=(pow(p2.x-p3.x,2) +pow(p2.y-p3.y,2) + pow(p2.z-p3.z,2));
			if( ( l1 == l2 and ( l1==l3 || l2 == l3 ) ) || ( l1==l3 and (l2=l3) ))
				return true;
			return false;
		}
		double perimetre(){
			double l1=(pow(p1.x-p2.x,2) +pow(p1.y-p2.y,2) + pow(p1.z-p2.z,2));
			double l2=(pow(p1.x-p3.x,2) +pow(p1.y-p3.y,2) + pow(p1.z-p3.z,2));
			double l3=(pow(p2.x-p3.x,2) +pow(p2.y-p3.y,2) + pow(p2.z-p3.z,2));
			return sqrt( l1 )+sqrt( l2 )+sqrt(l3);

		}


	private:
		Point p1;
		Point p2;
		Point p3;
		void init1(double a, double b,double c){
			p1.x=a;
			p1.y=b;
			p1.z=c;
		}
		void init2(double a, double b,double c){
			p2.x=a;
			p2.y=b;
			p2.z=c;
		}
		void init3(double a, double b,double c){
			p3.x=a;
			p3.y=b;
			p3.z=c;
		}
};

int main(){
Triangle t;
Point a={0,0,0};
Point b={2.5,2.5,0};
Point c={0,5,0};
t.init(a,b,c);

cout<< t.perimetre()<<endl;
if (t.est_isocele())
	cout<<"woohoo"<<endl;

return 0;
}
