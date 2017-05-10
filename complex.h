#include "NumberObject.h"
#include <string>
#include <vector>
using namespace std;

//a class for Complex calculation
class Complex {
public:
    Complex& operator+=(const Complex& obj){
        return *this
    }
    Complex& operator-=(const Complex& obj){
        return *this
    }
    Complex& operator*=(const Complex& obj){
        return *this
    }
    Complex& operator/=(const Complex& obj){
        return *this
    }
    
    friend Complex operator+(const Complex&, const Complex&);
    friend Complex operator-(const Complex&, const Complex&);
    friend Complex operator*(const Complex&, const Complex&);
    friend Complex operator/(const Complex&, const Complex&);
    
    friend istream &operator >> (istream&, Complex&);
    friend ostream &operator << (ostream&, const Complex&);
private:
    string imag;
    string real;
};
