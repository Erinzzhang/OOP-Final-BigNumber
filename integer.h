//
//  integer.h
//  OOP-BigNumber
//
//  Created by erin on 2017/5/30.
//  Copyright © 2017年 Erin Zhang. All rights reserved.
//

#ifndef integer_h
#define integer_h

#include "decimal.h"

#include <string>
#include <vector>
#include <algorithm>

using namespace std;



//a class for Integer calculation
class Integer: public NumberObject {
    


public:
    Integer();
    
    Integer(const char *number){
        string temp(number);
        value = temp;
    }
    
    string divide(string, string);
    
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
    
    // A simplistic implementation of operator= (see better implementation below)
    Integer& operator= (const char *number )
    {
        string temp(number);
        // do the copy
        value = number;
        // return the existing object so we can chain this operator
        return *this;
    }
    
    friend Integer operator+(const Integer&, const Integer&);
    friend Integer operator-(const Integer&, const Integer&);
    friend Integer operator*(const Integer&, const Integer&);
    friend Integer operator/(const Integer&, const Integer&);
    
    
    friend istream &operator >> (istream&, Integer&);	//cin needs to use istream
    friend ostream &operator << (ostream&, const Integer&);	//cout overload needs ostream
    
private:
    string value;
    int data;
};


#endif /* integer_h */
