//
//  integer.h
//  OOP-BigNumber
//
//  Created by erin on 2017/5/30.
//  Copyright © 2017年 Erin Zhang. All rights reserved.
//

#ifndef Integer_H
#define Integer_H

#include "decimal.h"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Decimal;

//a class for Integer calculation
class Integer: public NumberObject {
public:
    Integer();
    Integer(const char *number);
    Integer(const int number);
    
    Integer& operator+=(const Integer& object2) {
        return *this;
    }
    Integer& operator-=(const Integer& object2) {
        return *this;
    }
    Integer& operator*=(const Integer& object2) {
        return *this;
    }
    Integer& operator/=(const Integer& object2) {
        return *this;
    }
    
    Integer& operator = (const Integer& rhs);
    Integer& operator = (const int& rhs);
    
    friend Integer operator+(const Integer&, const Integer&);
    friend Integer operator-(const Integer&, const Integer&);
    friend Integer operator*(const Integer&, const Integer&);
    friend Integer operator/(const Integer&, const Integer&);
    
    friend istream &operator >> (istream&, Integer&);	//cin needs to use istream
    friend ostream &operator << (ostream&, const Integer&);	//cout overload needs ostream
    
//    Integer Power(Integer, string);
    string integerDivide(string, string);
};

#endif /* integer_h */
