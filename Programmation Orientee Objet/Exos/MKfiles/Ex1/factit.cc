#include "factit.h"
#include <iostream>
using namespace std;
unsigned int factorielleIterative(unsigned int n)
{
  unsigned int fact(1);
  for (unsigned int i(2); i <= n; ++i)
    fact = fact * i;
  return fact;
}
 
