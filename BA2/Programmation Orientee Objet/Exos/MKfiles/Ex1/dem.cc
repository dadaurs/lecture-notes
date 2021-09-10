#include "dem.h"
#include <iostream>
#include <limits>

using namespace std;

unsigned int demander_nombre(unsigned int a, unsigned int b)
{
    unsigned int res;
 
    do {
      cout << "Entrez un nombre entier ";
      if (a >= b)
	cout << "supérieur ou égal à " << a;
      else
	cout << "compris entre " << a << " et " << b;
      cout << " : ";
      cin >> res;
      if (cin.fail()) { 
	cout << "Je vous ai demandé d'entrer un nombre, "
	     << "pas du charabia !" << endl;
        // remet cin dans un état lisible
        cin.clear();
	// "jette" toute la ligne
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
	res = a-1;
      }
    } while ((res < a) or ((a < b) and (res > b)));
 
   return res;
}
 
