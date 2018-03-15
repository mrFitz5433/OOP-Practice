//Fitzgerald Brideweser
//Rational Class

#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <cstdlib>
#include <iostream>

// Represents a rational number. The rational numbers are the set of
// numbers that can be represented as the quotient of two integers.
struct rational
{
  int numer;
  int denom;

  rational();
  rational(int top, int bot);
  rational(int wholeNum);
  rational(const rational &, const rational &);

  // Returns the numerator.
  int num() const { return numer; }

  // Returns the denominator
  int den() const { return denom; }
};
//operator ==
bool operator==(const rational & frac1, const rational & frac2);
//operator !=
bool operator !=(const rational & frac1, const rational & frac2);
//operator <
bool operator<(const rational & frac1, const rational & frac2);
//operator <=
bool operator<=(const rational & frac1, const rational & frac2);
//operator >
bool operator>(const rational & frac1, const rational & frac2);
//operator >=
bool operator>=(const rational & frac1, const rational & frac2);
//operator +
Rational operator+(const rational & frac1, const rational & frac2);
//operator -
Rational operator-(const rational & frac1, const rational & frac2);
//operator *
Rational operator*(const rational & frac1, const rationa & frac2);
//operator /
Rational operator/(const rational & frac1, const rational & frac2);

//helper functions
int gcd(int, int);
int lcm(int, int);