#include <iostream>
using namespace std;
struct complexe{
	double r;
	double i;
};


void affiche(complexe c){
	cout << c.r << "+ i ."<< c.i << endl;
}

complexe add(complexe a, complexe b){
	complexe c;
	c.r= a.r+ b.r;
	c.i= a.i+ b.i;
	return c;
}
complexe sub(complexe a, complexe b){
	complexe c;
	c.r= a.r- b.r;
	c.i= a.i- b.i;
	return c;
}
complexe mult(complexe a, complexe b){
	complexe c;
	c.r= a.r*b.r- a.i*b.i;
	c.i= a.r*b.i+ a.i*b.r;
	return c;
}
complexe div(complexe a, complexe b){
	complexe c;
	c.r= (a.r*b.r + a.i*b.i)/(b.r*b.r + b.i *b.i);
	c.i= (a.i*b.r - a.r*b.i)/(b.r*b.r + b.i *b.i);
	return c;
}

int main(){
	complexe b= {3,4};
	complexe a= {3,4};
	affiche(add(a,b));
	affiche(sub(a,b));
	affiche(mult(a,b));
	affiche(div(a,b));

return 0;
}
