#include <iostream>
using namespace std;


int main(){
int choice;

cout << "Pensez à  un champignon : amanite tue-mouches, pied bleu, girolle," << endl
<< "cèpe de Bordeaux, coprin chevelu ou agaric jaunissant." << endl << endl;
  

cout << "Est-ce que votre champignon a un anneau (1 : oui, 0 : non) ? ";
cin >> choice;
if(choice==1){
cout << "Est-ce que votre champignon vit en forêt (1 : oui, 0 : non) ? ";
cin>>choice;
	if(choice){
	cout << "==> Le champignon auquel vous pensez est ";
	cout << "l'amanite tue-mouches";
	}else{
	cout << "Est-ce que votre champignon a un chapeau convexe (1 : oui, 0 : non) ? ";
	cin>>choice;
		if(choice==1){
		cout << "==> Le champignon auquel vous pensez est ";
		cout << "l'agaric jaunissant";
		}else{
			cout << "==> Le champignon auquel vous pensez est ";
			cout << "le coprin chevelu";
		}
	}

}else{
cout << "Est-ce que votre champignon a des lamelles (1 : oui, 0 : non) ? ";
cin>>choice;
	if(choice==0){
	cout << "==> Le champignon auquel vous pensez est ";
	cout << "le cèpe de Bordeaux";
	}else{
	cout << "Est-ce que votre champignon a un chapeau convexe (1 : oui, 0 : non) ? ";
	cin>>choice;
	if(choice==1){
	cout << "==> Le champignon auquel vous pensez est ";
	cout << "le pied bleu";
	}else{
	cout << "==> Le champignon auquel vous pensez est ";
	cout << "la girolle";
	}

	}

}


return 0;
}
