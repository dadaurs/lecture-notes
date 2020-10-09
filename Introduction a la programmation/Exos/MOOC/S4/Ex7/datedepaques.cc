#include <iostream>
using namespace std;

int demander_annee(){
	int nb;
	do{
		cout << "Entrez une annee (1583-4000) :"<<endl;
		cin>>nb;
	}while(nb<1583|| nb>4000);
	return nb;
}
int date_Paques(int an){
	int siecle=an/100;
	int p = ( 13 + 8*siecle )/25;
	int q = siecle/4;
	int M = ( 15-p + siecle -q )%30;
	int N = (4+siecle-q)%30;
	int d = ( M + 19* (an%19) ) %30;
	int e = (2 * (an % 4) + 4 * (an % 7) + 6 * d + N) % 7;
	int jour= e+d + 22;
	if(e==6 && (d==29 || (d= 28 && 11* (M+1)%30 < 19))){
	jour=jour-7;
	}
	return jour;
}

void affiche_date(int annee, int j){
	if(j<32){
	cout << "Date de Paques en "<< annee<<" : "<< j<< " mars."<<endl;
	}else{
	cout << "Date de Paques en "<< annee<<" : "<< j-31<< " avril."<<endl;
	}
	
}
int main(){
	int an=demander_annee();
	affiche_date(an,date_Paques(an));


return 0;
}
