#include <sstream>
#include "Fraction.h"

using namespace std;

int main() {
   Fraction f1(4,3);
   Fraction f2(8,7);

   istringstream iSS("9/8");
   iSS >> f2;

   cout << (f1 + f2) << endl; //  59/24
   cout << (f1 - f2) << endl; //  4/3 
   cout << (f1 * f2) << endl; //  3/2
   cout << (f1 / f2) << endl; //  4/3
   cout << (f1 < f2) << endl; //  0
   cout << (f1 > f2) << endl; //  1
   cout << (f1 == f2) << endl; // 0

   return 0;
}
