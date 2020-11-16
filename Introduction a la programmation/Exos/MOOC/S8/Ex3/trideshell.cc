#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> tab;
void swap(tab& t, int a, int b){
int tmp=t[a];
t[a]=t[b];
t[b]=tmp;
}
// Cet exo est pete
void trishell(tab& t){
	for(size_t k=t.size()/2;k>=1;k/=2){
		for(size_t i=k+1;k<=t.size();++k){
			unsigned int j= i-k;
			while(j > 0){
				if(t[j] >t[j+k]){
					swap(t,j,j+k);
					j=j-k;
				}else {
					j=0;
				}
			}
		}
	}
}



int main(){
	int inp;
	vector<int> t;
do{
	cin>> inp;
	t.push_back(inp);
}while(inp!=0);
trishell(t);
for(size_t i=0;i<t.size();++i){
	cout<<t[i];
}
cout<<endl;

return 0;
}
