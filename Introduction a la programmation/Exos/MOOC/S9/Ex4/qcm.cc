#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;
struct qcm{
string question;
vector<string> reponses;
int solution;

};
typedef vector<qcm> Examen;
Examen creer(ifstream& fich){
	Examen exa;
	int numsol=0;
	string ligne;
	while(fich>>ligne){
	if(ligne[0]=='Q'&&ligne[1]==':'){
		exa.push_back({"",{ "" },0});
		exa[exa.size()-1].question=ligne.substr(2,ligne.size()-1);
		numsol=0;
	}else if(ligne[0]!='#'){
		if(!( ligne[0]=='-' && ligne[1]=='>' )){
			exa[exa.size()-1].reponses.push_back(ligne);
			numsol++;
		}else{
			exa[exa.size()-1].solution=numsol;
			exa[exa.size()-1].reponses.push_back(ligne);

			
		
		}
	}
	}


	return exa;
	
}

bool demander_fichier(ifstream& fichier){
	int compteur=0;
	string essai;

	while(compteur<3){
		cin>>essai;
		fichier.open(essai);
		if(fichier.fail()){
			cout<<"Non"<<endl;
			compteur++;
		}else{
			return true;
		}
	}
	cout<<"Franchement baise tes morts"<<endl;

	return false;
	

}


int main(){

return 0;
}
