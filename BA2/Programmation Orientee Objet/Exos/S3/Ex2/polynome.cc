#include <iostream>
#include <vector>
using namespace std;
typedef unsigned int Degre;

class Polynome {
	private:
		vector<double> facteurs;
	public:
		Polynome(double a=0) {
			facteurs.push_back(a);
		}
		Polynome(Polynome const & p): facteurs(p.getFacteurs()){
			//vector<double> v=p.getFacteurs();
			//for(auto i:v) {
				//facteurs.push_back(i);
			//}
			
			
		}
		Polynome(vector<double> v): facteurs(v){}
		Polynome(double a, Degre n) {
			for(size_t i(0);i<n;++i) {
				facteurs.push_back(0);
			}
			facteurs.push_back(a);
		}
		
		
		vector<double> getFacteurs() const{
			return facteurs;
		}
		
		
		Degre degre() const {
			if(facteurs.size()==0)
				return 0;
			return facteurs.size();
		}
		double get_coeff(Degre d) const {
			if(d>facteurs.size()-1)
				return 0;
			return facteurs[d];
		}
		void simplifie() {
		while(facteurs[facteurs.size()-1]==0) {
			facteurs.pop_back();
		}
		}
		
		
		
		
		

		

};
Polynome  operator+(Polynome q,Polynome const & p) {
	vector<double> v;
	if(q.degre()>=p.degre()) {
	for(size_t i(0);i<q.degre();++i) {
		v.push_back(q.get_coeff(i)+p.get_coeff(i));
	   }
	}else {
	for(size_t i(0);i<q.degre();++i) {
		v.push_back(q.get_coeff(i)+p.get_coeff(i));
	   }
	for(size_t i(q.degre());i<p.degre();++i) {
		v.push_back(p.get_coeff(i));	
	}
	
		
	}
	Polynome P(v);
	return P;
}
Polynome  operator-(Polynome q,Polynome const & p) {
	vector<double> Q;
	for(auto i:p.getFacteurs()) {
		Q.push_back(-i);
	}
	Polynome res= Q+q;
	res.simplifie();
	return res;
	
	
	
}

ostream& operator<<(ostream & os, Polynome p) {
	for(size_t i(0);i< p.degre();++i) {
	os<<p.get_coeff(i)<< " * X^"<< i;
	}
	return os;


	
}


int main(){

return 0;
}
