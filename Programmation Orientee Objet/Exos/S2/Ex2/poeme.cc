#include <iostream>
using namespace std;
class Fleur {
	public:
	Fleur(string nom, string coul) {
		cout<< nom << "fraichement cueillie"<<endl;
	}
	Fleur(Fleur const& fl) {
		cout<<"Fragile corolle taillee"<<endl;
	}
	void eclore() {
		cout<<"dans un cristal veine de bleu"<<endl;
	}
	
	~Fleur() {
		cout<<"ne laissant plus qu'un simple souffle..."<<endl<<"qu'un simple souffle..."<<endl;
	}
};



int main(){
Fleur f1("Violette", "bleu");
Fleur f2(f1);
cout << "dans un cristal ";
f2.eclore();
cout << "Donne un poème un peu fleur bleue" << endl;
return 0;
}
