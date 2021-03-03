#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction {
   private:
      int numerator;
      int denominator;
   public:
      Fraction() {numerator = 1; denominator = 1;}
      Fraction(int num, int denom) {numerator = num; denominator = denom;}
      Fraction(int num) {numerator = num; denominator = 1;}
      int getNumerator() {return numerator;}
      int getDenominator() {return denominator;}
      void setNumerator(int num) {numerator = num;}
      void setDenominator(int denom) {denominator = denom;}
      void simplify();
      Fraction operator+(const Fraction&);
      Fraction operator-(const Fraction&);
      Fraction operator*(const Fraction&);
      Fraction operator/(const Fraction&);
      bool operator<(const Fraction&);
      bool operator>(const Fraction&);
      bool operator==(const Fraction&);
      friend std::ostream& operator<<(std::ostream&, const Fraction&);
      friend std::istream& operator>>(std::istream&, Fraction&);
};

#endif // FRACTION_H
