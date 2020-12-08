#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


int main(){
string nom_fich;
cout<<"Nom du fichier"<<endl;
cin>> nom_fich;
ofstream fichier(nom_fich);
if(fichier.fail())
{
	cout<<"Misere"<<endl;
	return 0;
}
	string nom;
	string age;
do{
	cout<<"Nom:"<<endl;
	cin>>ws;
	getline(cin, nom);
	if(cin.fail()){
	fichier.close();
	return 0;
	}
	cout<<"Age:"<<endl;
	cin>>ws;
	getline(cin, age);
	if(cin.fail()){
	fichier.close();
	return 0;
	}
	fichier<<setw(40)<<left<<nom<<right<<age<<endl;

}while(!fichier.eof());
fichier.close();


return 0;
}
