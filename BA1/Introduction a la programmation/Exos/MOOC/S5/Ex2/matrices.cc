#include <iostream>
#include <vector>

using namespace std;
vector<vector<double>> lire_matrice(){
int l1;
cout << "Quel nombre de lignes?"<< endl;
cin >> l1;
int c1;
cout << "Quel nombre de colonnes?"<< endl;
cin >> c1;


vector<vector<double>> A(l1, vector<double>(c1));
for(size_t i(0); i<A.size();i++){
	for(size_t j(0); j<A[0].size();j++){
	cout << "Element" << i << j << "?"<<endl;
	cin>> A[i][j];
	}
}
//vector<vector<double>> B(l2, vector<double>(c2));

return A;
}
void affiche_matrice(const vector<vector<double>>& M){
for(size_t i(0);i<M.size();++i){
	for(size_t j(0);j<M[0].size();++j){
		cout<<M[i][j];
	}
	cout<<endl;
}
}

vector<vector<double>> mult(vector<vector<double>> A, vector<vector<double>> B){
	vector<vector<double>> R(A.size(),vector<double> (B[0].size()));
	for(size_t i(0); i<A.size();++i){
		for(size_t j(0); j<B[0].size();++j){
			for(size_t k(0); k<A[0].size();++k){
				R[i][j]+= A[i][k] * B[k][j];
			}
		}
	}
	return R;
}


int main(){
vector<vector<double>> A=lire_matrice();
vector<vector<double>> B=lire_matrice();
if(B[0].size() != A.size()){
	cout<< "Non" << endl;
}

affiche_matrice(mult(A,B));
//affiche_matrice(B);
return 0;
}
