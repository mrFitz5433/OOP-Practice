//Fitzgerald Brideweser
//Rational.cpp

#include "Rational.hpp"
#include <iostream>

// Rational implementation
rational(int n = 0, int d = 1) 
	: numer(n), denom(d){}
rational(const rational &, const rational &)
  : numer(n.numer), denom(d.denom){}

  //r1 == t2
  //if returned false r1 != r2
  bool operator==(const rational & frac1, const rational & frac2)
  {
 	bool temp;
 	if((frac1.numer * frac2.denom) == (frac1.denom * frac2.numer))
 		temp = true;
 	else
 		temp = false;
 	return temp; 
  }
 
  //r1 < r2
  bool operator<(const rational & r)const{
    return numer * r.denom < denom * r.numer;
  }
  //r1 > r2
  bool operator>(const rational & r)const{
    return numer * r.denom > denom * r.numer;
  }
  //r1 <= r2
  bool operator<=(const rational & r)const{
    return numer * r.denom <= denom * r.numer;
  }
  //r1 >= r2
  bool operator>=(const rational & r)const{
    return numer * r.denom >= denom * r.numer;
  }
  //r1 + r2
  const rational operator+(const ratioal & r)const{
    int n = numer * r.denom + denom * r.numer;
    int d = denom * r.denom;
    return rational(n,d);
  }
  //r1 - r2
  const rational operator-(const rational & r)const{
    int n = numer *r.denom - denom * r.numer;
    int d = denom * r.denom;
    return rational(n,d);
  }
  //r1 * r2
  const rational operator*(const rational & r)const{
    int n = numer * r.numer;
    int d = demon * r.denom;
    return rational(n,d);
  }
  //r1 / r2
  const rational operator/(const rational & r)const{
    int n = numer * r.denom;
    int d = denom * r.numer;
    return rationl(n,d);
  }

//GCD uses Euclid's algorithm
int gcd(int a, int b)
{
  while (b != 0) {
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}

//LCM of two integers
int lcm(int a, int b)
{
  return (std::abs(a) / gcd(a, b)) * std::abs(b);
}