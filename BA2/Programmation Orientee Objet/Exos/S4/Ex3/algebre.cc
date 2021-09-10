#include <iostream>
using namespace std;
class EnsembleFini {
	protected:
	unsigned int p;
	public: 
	EnsembleFini(unsigned int pr) :p(pr) {}
	
};
class Groupe: public EnsembleFini {
	public:
		unsigned int add(unsigned int a, unsigned int b) {
			return  (a+b)%p;
		}
	Groupe(unsigned int a): EnsembleFini(a) {}
	
		
};
class Anneau:public Groupe {
	public:
		Anneau(unsigned int a): Groupe(a){}
		unsigned int mult(unsigned int a, unsigned int b) {
			return (a*b)%p;
		}
		
};
class Corps:public Anneau {
	public:
		Corps(unsigned int a): Anneau(a) {} 
		unsigned int inv(unsigned int a) {
			for(unsigned int i(0);i<p;++i) {
				if(( a*i )%p==1) {
					return i;
				}
				
			}
			
			return p-1;
		}
		unsigned int div(unsigned int a, unsigned int b) {
			return a* inv(a);
		}
		
		

};






int main(){
Corps k(5); // c'est le corps Z/5Z
cout << "0 + 1 = " << k.add(0, 1) << endl;
cout << "3 + 3 = " << k.add(3, 3) << endl;
cout << "3 * 2 = " << k.mult(3, 2) << endl;
cout << "1/2 = " << k.inv(2) << endl;
cout << "3 * 4 = " << k.mult(3, 4) << endl;
return 0;
}
