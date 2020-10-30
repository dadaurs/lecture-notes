#include <iostream>
#include <vector>

using namespace std;
double scalaire(vector<double> u, vector<double> v){
	double res=0;
	for(size_t i(0); i<u.size(); ++i){
		res += u[i] * v[i];
	}
	return res;
}


int main(){
int taille;
cout << "Quelle taille"<< endl;
cin >> taille;

vector <double> a(taille);
vector <double> b(taille);
for (size_t i(0); i< a.size(); ++i){
	cout << " Pour vecteur a, element "<< i <<endl;
	cin >> a[i];
}
for (size_t i(0); i< b.size(); ++i){
	cout << " Pour vecteur b, element "<< i <<endl;
	cin >> b[i];
}
cout << scalaire(a,b) <<endl;
return 0;
}
