#include <iostream>
using namespace std;
class Livre {
	protected:
		string titre;
		string auteur;
		int nb_pages;
		bool bestseller;
	public:
		double calculer_prix() {
			double p=0;
			if(bestseller)
				p+=50
			return p+0.3*nb_pages;
		}
		Livre(string t, string a, int n, bool b): titre(t), auteur(a), nb_pages(n), bestseller(b) {}
		virtual ~Livre() {}
		void afficher() {
			cout<< titre << auteur << nb_pages;
			if(bestseller)
				cout<<" bestseller";
			cout<< endl;
		}
		

		
	
};



int main(){

return 0;
}
