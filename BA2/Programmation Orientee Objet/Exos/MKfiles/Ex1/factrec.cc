#include "factrec.h"
#include <iostream>
using namespace std;
unsigned int factorielleRecursive(unsigned int n)
{
  if (n == 0)
    return 1;
  else
    return (n * factorielleRecursive(n-1));
}
 
