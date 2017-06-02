#include "integer.h"
#include <string>
#include <vector>
using namespace std;

//a class for Complex calculation
class Complex: public Decimal {
public:
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
    
    friend Complex operator+(const Complex&, const Complex&);
    friend Complex operator-(const Complex&, const Complex&);
    friend Complex operator*(const Complex&, const Complex&);
    friend Complex operator/(const Complex&, const Complex&);
    
    friend istream &operator >> (istream&, Complex&);
    friend ostream &operator << (ostream&, const Complex&);
    
    Complex Power(Complex, string);
private:
    Decimal imag;
    Decimal real;
};
