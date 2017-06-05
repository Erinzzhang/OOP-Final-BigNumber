#ifndef Decimal_H
#define Decimal_H

#include "inputFormula.h"
#include "integer.h"
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Integer;

//a class for Decimal calculation
class Decimal: public NumberObject {
public:
	Decimal();
    Decimal(const char *number);
    Decimal preoperation(Decimal&, Decimal&);
    bool decimalCheckZero(Decimal);

	Decimal& operator+=(const Decimal& object2) {
		return *this;
	}
	Decimal& operator-=(const Decimal& object2) {
		return *this;
	}
	Decimal& operator*=(const Decimal& object2) {
		return *this;
	}
	Decimal& operator/=(const Decimal& object2) {
		return *this;
	}
    Decimal& operator = (const char *number);
    Decimal& operator = (const Decimal& rhs);
    Decimal& operator = (const Integer& rhs);

	friend Decimal operator+(const Decimal&, const Decimal&);
    friend Decimal operator+(const Integer&, const Decimal&);
    friend Decimal operator+(const Decimal&, const Integer&);
    
	friend Decimal operator-(const Decimal&, const Decimal&);
    friend Decimal operator-(const Integer&, const Decimal&);
    friend Decimal operator-(const Decimal&, const Integer&);
    
	friend Decimal operator*(const Decimal&, const Decimal&);
    friend Decimal operator*(const Integer&, const Decimal&);
    friend Decimal operator*(const Decimal&, const Integer&);
    
    friend Decimal operator/(const Decimal&, const Decimal&);
    friend Decimal operator/(const Integer&, const Decimal&);
    friend Decimal operator/(const Decimal&, const Integer&);
 
    
	friend istream &operator >> (istream&, Decimal&);	//cin needs to use istream
	friend ostream &operator << (ostream&, const Decimal&);	//cout overload needs ostream

//    Decimal Power(Decimal, string);
    string divide(string, string);
    Decimal decimalAdd(const Decimal&, const Decimal&);
    Decimal decimalMinus(const Decimal&, const Decimal&);
    Decimal decimalMultiply(const Decimal&, const Decimal&);
    Decimal decimalDivide(const Decimal&, const Decimal&);
    
    string beforePoint;  //beforePoint.afterPoint
	string afterPoint;
};

Decimal Power(Decimal, string);

#endif
