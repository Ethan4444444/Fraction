#include "Fraction.h"

void Fraction::simplify() {
   int gcf = -1; //greatest common factor

   for(int i = numerator; i > 0; i--) { //loop through all ints in [numerator,1]
      for(int j = denominator; j > 0; j--) { //for each int in [numerator,1], loop through all ints in [denominator,1]
         if((numerator % i) == 0 && (denominator % j) == 0) { //checks to see whether the entries are factors of the numerator & denominator
            if(i == j) { //if the factors are equal
               gcf = i; //then we have our greatest common factor
               break; // so we can stop looping through denominator factors.
            }
         }
      }
      if(gcf != -1) { //if we have our GCF after breaking from the inner loop,
         break; //      then we can stop looping through numerator factors.
      }
   }

   numerator /= gcf;
   denominator /= gcf;
}

Fraction Fraction::operator+(const Fraction& right) {
   Fraction tempRight;
   tempRight.numerator = right.numerator * denominator; // adjust for easiest common denominator (multiple of the denominators)
   numerator *= right.denominator;
   denominator *= right.denominator;
   //no need to define tempRight.denominator, as it will always be equal to denominator.

   numerator += tempRight.numerator;

   simplify();
   return *this;
}
Fraction Fraction::operator-(const Fraction& right) {
   Fraction tempRight;
   tempRight.numerator = right.numerator * denominator;// adjust for easiest common denominator (multiple of the denominators)
   numerator *= right.denominator;
   denominator *= right.denominator;
   //no need to define tempRight.denominator, as it will always be equal to denominator.

   numerator -= tempRight.numerator;

   simplify();
   return *this;
}

Fraction Fraction::operator*(const Fraction& right) {
   numerator *= right.numerator;
   denominator *= right.denominator;

   simplify();
   return *this;
}

Fraction Fraction::operator/(const Fraction& right) {
   numerator *= right.denominator;
   denominator *= right.numerator; // multiply by the reciprocal

   simplify();
   return *this;
}

bool Fraction::operator<(const Fraction& right) {
   Fraction tempRight;
   Fraction tempLeft;
   tempLeft.numerator = numerator * right.denominator; // adjust for easiest common denominator (multiple of the denominators)
   tempRight.numerator = right.numerator * denominator; // two temp variables this time because we don't want to change the values of the fractions
   //no need to define denominator for tempLeft or tempRight, as we will only compare the numerators.

   return tempLeft.numerator < tempRight.numerator;
}

bool Fraction::operator>(const Fraction& right) {
   Fraction tempRight;
   Fraction tempLeft;
   tempLeft.numerator = numerator * right.denominator; // adjust for easiest common denominator (multiple of the denominators)
   tempRight.numerator = right.numerator * denominator; //two temp variables because we don't want to change the values of the fractions
   //no need to define denominator for tempLeft or tempRight, as we will only compare the numerators.

   return tempLeft.numerator > tempRight.numerator;
}

bool Fraction::operator==(const Fraction& right) {
   Fraction tempRight;// adjust for easiest common denominator (multiple of the denominators)
   Fraction tempLeft;//two temp variables because we don't want to change the values of the fractions
   tempLeft.numerator = numerator * right.denominator;
   tempRight.numerator = right.numerator * denominator;
   //no need to define denominator for tempLeft or tempRight, as we will only compare the numerators.

   return tempLeft.numerator == tempRight.numerator;
}

std::ostream& operator<<(std::ostream& o, const Fraction& right) {
   o << right.numerator << "/" << right.denominator; //fraction will be output as 3/2, 7/6, etc.
   return o;
}
std::istream& operator>>(std::istream& i, Fraction& right) {
   i >> right.numerator; //fraction will be input as 3/2, 7/6, etc.
   i.ignore();
   i >> right.denominator;
   return i;
}
