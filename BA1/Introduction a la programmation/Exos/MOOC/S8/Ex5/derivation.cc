#include <iostream>
using namespace std;
struct Arbre{
	bool est_vide;
	char val;
	Arbre * gauche;
	Arbre * droite;
};

void construire_nouveau(char valeur, Arbre * arbre1, Arbre * arbre2, Arbre &arbre_final){
	arbre_final.est_vide = false;
	arbre_final.val= valeur;
	arbre_final.gauche = arbre1;
	arbre_final.droite = arbre2;
}

void affiche_arbre(Arbre * arb){
if(arb->est_vide){
	cout<< arb->val;
}else{
	affiche_arbre(( arb->gauche ));
	cout<< arb->val;
	affiche_arbre(( arb->droite ));
}
}


Arbre derivation(Arbre * expr, char d){
	Arbre derivee;
	if(expr->est_vide){
		if(expr->val == d){
			derivee.val='1';
			derivee.est_vide=true;
		}else {
			derivee.val='0';
			derivee.est_vide=true;
		}

	}else{
	Arbre tempgauche;
	Arbre tempdroite;
	tempgauche.est_vide=true;
	tempdroite.est_vide=true;
		if (expr->val == '+'){
			derivee.est_vide=false;
			derivee.val='+';
			tempgauche=derivation( expr->gauche ,d);
			tempdroite=derivation( expr->droite ,d);
			derivee.gauche=& tempgauche;
			derivee.droite=& tempdroite;

		}
		if (expr->val == '-'){
			derivee.est_vide=false;
			derivee.val='-';
			tempgauche=derivation( expr->gauche ,d);
			tempdroite=derivation( expr->droite ,d);
			derivee.gauche=& tempgauche;
			derivee.droite=& tempdroite;

		}
		if (expr->val == '*'){
			Arbre tempgauchep;
			Arbre tempdroitep;
			tempgauchep.est_vide=true;
			tempdroitep.est_vide=true;
			tempgauche.est_vide=true;
			tempdroite.est_vide=true;
			tempgauche=derivation(expr->gauche,d);
			tempdroite=derivation(expr->droite,d);
			construire_nouveau('*',&tempgauche,expr->droite,tempgauchep);
			construire_nouveau('*',&tempdroite,expr->gauche,tempdroitep);

			construire_nouveau('+',&tempgauchep,&tempdroitep,derivee);

		}
		if (expr->val == '/'){
			Arbre numerateur;
			Arbre denominateur;



			numerateur.val='-';
			numerateur.est_vide=false;
			Arbre tempgauchep;
			Arbre tempdroitep;
			tempgauche=derivation(expr->gauche,d);
			tempdroite=derivation(expr->droite,d);
			construire_nouveau('*',&tempgauche,expr->droite,tempgauchep);
			construire_nouveau('*',&tempdroite,expr->gauche,tempdroitep);
			numerateur.gauche=&tempgauchep;
			numerateur.droite=&tempdroitep;

			denominateur.est_vide=false;
			denominateur.val='*';
			denominateur.gauche=expr->droite;
			denominateur.droite=expr->droite;
			construire_nouveau('/',&numerateur,&denominateur,derivee);

			

		}
		if (expr->val == '^'){
			derivee.est_vide=false;
			Arbre agauche;
			tempdroite=derivation(expr->gauche,d);
			construire_nouveau('*',expr->droite,&tempdroite,agauche);
			Arbre adroite;
			Arbre asousdroite;
			Arbre trivial;
			trivial.est_vide= true;
			trivial.val='1';

			construire_nouveau('-',expr->droite,&trivial,asousdroite);
			construire_nouveau('^',expr->gauche,&asousdroite,adroite);
			
			construire_nouveau('*',&agauche,&adroite,derivee);


		}
	}

	return derivee;
}


int main(){
	Arbre x;
	x.est_vide= true;
	x.val = 'x';
	
	Arbre a;
	a.est_vide= true;
	a.val = 'a';

	Arbre b;
	b.est_vide= true;
	b.val = 'b';

	Arbre additiona;
	construire_nouveau('+',&x,&a,additiona);

	Arbre additionb;
	construire_nouveau('+',&x,&b,additionb);

	Arbre prodxaxb;
	construire_nouveau('*',&additiona,&additionb,prodxaxb);

	Arbre prodxx;
	construire_nouveau('*',&x,&x,prodxx);

	Arbre prodxxx;
	construire_nouveau('*',&prodxx,&x,prodxxx);

	Arbre prodbx;
	construire_nouveau('*',&b,&x,prodbx);

	Arbre apx;
	construire_nouveau('^',&x,&a,apx);

	Arbre prodxxpprodbx;
	construire_nouveau('+',&prodxx,&prodbx,prodxxpprodbx);

	Arbre grosdiv;
	construire_nouveau('/',&apx,&prodxxpprodbx,grosdiv);

	Arbre derivee;
	affiche_arbre(&prodxaxb);
	cout<< endl;
	derivee=derivation(&apx,'a');
	affiche_arbre(&derivee);







return 0;
}
