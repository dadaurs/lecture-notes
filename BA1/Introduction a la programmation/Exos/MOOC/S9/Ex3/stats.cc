#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;
typedef vector<long int> Statistique;
void initialise_statistique(Statistique& stat){
	for(size_t i(0);i<stat.size();++i){
		stat[i]=0;
	}
}
unsigned long int collecte_statistique(Statistique& stat, ifstream& fich){
	long int total=0;

	for(int i(32);i<126;++i){
		char car;
		stat.push_back(0);
		while(fich.get(car)){
			if(car==char(i)){
				stat[i]+=1;
				total++;
			}
		}
		

	}
	return total;
}
void affiche_stats(Statistique & stat){
for(size_t i =0;i<stat.size();i++){
if(stat[i]!=0){
	cout<< setw(30)<<left<<char(i) <<right<< stat[i]<<endl;
}
}
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
