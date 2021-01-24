#include <iostream>
#include <vector>
using namespace std;

int somme_consecutifs_max(vector<int> tab){
int max=tab[0];
int r=0;
size_t i=0;
while(i<tab.size()){
if(tab[i]==0){
		r=0;
}
r+=tab[i];
if(max<r){
max=r;
}
++i;
}
return max;
}
vector<size_t> lignes_max(vector<vector<int>> tab){
	int valmax=0;
	vector<size_t> rep;
	for(size_t i=0;i<tab.size();i++){
		int r=somme_consecutifs_max(tab[i]);
		if(r>valmax){
			valmax=r;
		}

	}
	for(size_t i=0;i<tab.size();++i){
		if(somme_consecutifs_max(tab[i])==valmax){

			rep.push_back(i);
		}
	}
	return rep;
}

vector<vector<int>> tranches_max(vector<vector<int>> tab){
	vector<vector<int>> ret;
	vector<size_t> a = lignes_max(tab);
	for(auto i: a){
		ret.push_back(tab[i]);
	}
	return ret;


}
void printarr(vector<vector<int>> t){
	for(auto i:t){
	for(auto j:i){
		cout<< j;
	}
	cout<<endl;
	}
}


int main(){
	vector<vector<int>> t= {{2,1,0,2},{0,1,0,3},{1,3,0,0},{0,2,2,0}};
	printarr(tranches_max(t));
return 0;
}
