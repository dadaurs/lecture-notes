#include <iostream>
#include <vector>
using namespace std;
struct qcm{
string question;
vector<string> reponses;
int solution;

};
typedef vector<qcm> Examen;
void affiche(qcm a){
	cout<<a.question<<endl;
	for(size_t i(0); i < a.reponses.size();++i){
		cout<< i+1<<"- "<<a.reponses[i]<<endl;
	}
}
int poser_question(qcm q){
	affiche(q);
	int rep;
	do{
		cout<<"Entre un nb"<<endl;
		cin >> rep;

	}while(rep<0);
	return rep;
}


int main(){
	Examen exa={
		// Question 1
{ "Combien de dents possède un éléphant adulte",
{ "32", "de 6 à 10", "beaucoup", "24", "2" },
2 // réponse
},
// Question 2
{ "Laquelle des instructions suivantes est un prototype de fonction",
{ "int f(0);"
,
"int f(int 0);" ,
"int f(int i);" ,
"int f(i);"
},
3 // réponse
},
// Question 3
{ "Qui pose des questions stupides",
{ "le prof. de math",
"mon copain/ma copine",
"le prof. de physique",
"moi",
"le prof. d'info",
"personne, il n'y a pas de question stupide",
},

}
};

int score=0;
for(auto h: exa){

if(poser_question(h)==h.solution){
	++score;
}

}
cout<< "Ton score est" << score<<endl;

return 0;
}
