#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;


int main(){
	string nom_fich="data.dat";
ifstream fich;
fich.open(nom_fich);
if(fich.fail()){
	cout<<"Misere"<<endl;
	return 0;
}
string nom;
int age;
int somme_age=0;
int nbpersonnes=0;
vector<int> ages;
int min=0;
int max=0;

while(fich>>nom>>age){
	cout<<setw(15)<<left<<nom<<setw(3)<<right<<age<<endl;
	somme_age+=age;
	if(age<min){
		min=age;
	}
	if(age>max)
		max=age;
	nbpersonnes++;

}
cout<<"Age moyen"<<1.0*somme_age/nbpersonnes<<endl;
cout<<"Max"<<max<<endl;
cout<<"Min"<<min<<endl;

fich.close();
return 0;
}
