#ifndef Complex_H
#define Complex_H

#include "integer.h"
#include <string>
#include <vector>

using namespace std;

//a class for Complex calculation
class Complex: public Decimal {
public:
    Complex();
    Complex(const char *number);

    Complex& operator+=(const Complex& obj){
        return *this;
    }
    Complex& operator-=(const Complex& obj){
        return *this;
    }
    Complex& operator*=(const Complex& obj){
        return *this;
    }
    Complex& operator/=(const Complex& obj){
        return *this;
    }
    Complex& operator = (const char *number);
    Complex& operator = (const Complex& top);
    Complex& operator = (const Decimal& rhs);
    Complex& operator = (const Integer& rhs);
    

    friend Complex operator+(const Complex&, const Complex&);
    friend Complex operator+(const Complex&, const Decimal&);
    friend Complex operator+(const Decimal&, const Complex&);
    friend Complex operator+(const Complex&, const Integer&);
    friend Complex operator+(const Integer&, const Complex&);

    friend Complex operator-(const Complex&, const Complex&);
    friend Complex operator-(const Complex&, const Decimal&);
    friend Complex operator-(const Decimal&, const Complex&);
    friend Complex operator-(const Complex&, const Integer&);
    friend Complex operator-(const Integer&, const Complex&);
    
    friend Complex operator*(const Complex&, const Complex&);
    friend Complex operator*(const Complex&, const Decimal&);
    friend Complex operator*(const Decimal&, const Complex&);
    friend Complex operator*(const Complex&, const Integer&);
    friend Complex operator*(const Integer&, const Complex&);
    
    friend Complex operator/(const Complex&, const Complex&);
    friend Complex operator/(const Complex&, const Decimal&);
    friend Complex operator/(const Decimal&, const Complex&);
    friend Complex operator/(const Complex&, const Integer&);
    friend Complex operator/(const Integer&, const Complex&);
    
    
    friend istream &operator >> (istream&, Complex&);
    friend ostream &operator << (ostream&, const Complex&);
    
//    Complex Power(Complex, string);
    Complex complexAdd(const Complex&, const Complex&);
    Complex complexMinus(const Complex&, const Complex&);
    Complex complexMultiply(const Complex&, const Complex&);
    Complex complexDivide(const Complex&, const Complex&);
    
    Decimal complexImag;
    Decimal complpexReal;
};

Complex Power(Complex, string);

#endif
