#include <iostream>
#include <string>
using namespace std;
struct Personne{
char sexe;
string prenom;

};
struct lettre{
Personne personne;
string sujet;
int date_jour;
int date_mois;
string politesse;
string auteur;


};
void generelettre(lettre test){
	string salutations;
	if (test.personne.sexe == 'F'){
		string salutations="Chere";
	}else{
		string salutations="Cher";
	}

	cout<< "Bonjour "<< salutations << " " << test.personne.prenom << endl<< "Je vous écris à propos de "<< test.sujet<<endl<< "Il faudrait que nous nous voyons le "<< test.date_jour << "/"<<test.date_mois <<"pour en discuter."<<endl<<" Donnez-moi vite de vos nouvelles !"<<endl<< test.politesse<< test.auteur<<endl;
}

int main(){
	

Personne mireil;
mireil.sexe='F';
mireil.prenom="Mireille";


lettre test= {mireil, "votre cours", 18, 12 , "Amicalement" , "John." };
generelettre(test);
return 0;
}
