#include <iostream>
#include <string>
using namespace std;
struct Match{
	string e1;
	int pt1;
	string e2;
	int pt2;
};

void nouvmatch(Match &m, string eq1, string eq2){
cout << eq1 << " - " << eq2 << " ?";
m.e1=eq1;
m.e2=eq2;
cin>> m.pt1 >> m.pt2;
}


int main(){
Match sc;
nouvmatch( sc ,"Suisse","Croatie");


Match fa;
nouvmatch(fa,"France","Angleterre");


return 0;
}
