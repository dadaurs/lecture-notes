#include <iostream>
using namespace std;
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
struct Coord{
	double x;
	double y;
};

class Cercle {
	
	public: 
		Coord centre;
		double r;
		void getCentre(double& x, double& y) const{
			x=centre.x;
			y=centre.y;
		}
		void setCentre(double x, double y) {
			centre.x=x;
			centre.y=y;
		}
		double surface () const{
			return M_PI*r*r;
		}
		bool estInterieur(double x, double y) const{
			double dx = centre.x-x;
			double dy = centre.y-y;
			if( dx*dx + dy*dy < r*r)
				return true;
			return false;
		}
};

int main(){
	Cercle c1;
	Cercle c2;

return 0;
}
