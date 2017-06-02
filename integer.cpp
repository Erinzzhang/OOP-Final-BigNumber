//
//  integer.cpp
//  OOP-BigNumber
//
//  Created by erin on 2017/5/30.
//  Copyright © 2017年 Erin Zhang. All rights reserved.
//

#include "integer.h"
#include <iostream>
#include <sstream>

using namespace std;

//Integer constructor function
Integer::Integer(){
    value = "";
}


//overload + operator
Integer operator+(const Integer& lhs, const Integer& rhs) {
    Integer result;
    result.value = result.AddString(lhs.value,rhs.value);
    return result;
}

Integer operator-(const Integer& lhs, const Integer& rhs) {
    Integer result;
    result.value = result.MinusString(lhs.value,rhs.value);
    return result;
}


Integer operator*(const Integer& lhs, const Integer& rhs) {
    Integer result;
    result.value = result.KaratsubaMultiply(lhs.value,rhs.value);
    return result;
}


Integer operator/(const Integer& lhs, const Integer& rhs) {
    Integer result;
    result.value = result.divide(lhs.value, rhs.value);
    return result;
}

std::ostream &operator<<(std::ostream &os, Integer const &IntegerNum) {
    return os << IntegerNum.value;
}

std::istream& operator >> (istream& is, Integer& IntegerNum)
{
    is >> IntegerNum.value;
    return is;
}


string Integer::divide(string a, string b) {
    //string lhs,rhs;
    Decimal lhs, rhs, temp;
    Integer ans;
    lhs.beforePoint = a;
    lhs.afterPoint = "0";
    rhs.beforePoint = b;
    rhs.afterPoint = "0";
    cout << "lhs: " << lhs << " ,rhs: " << rhs << endl;
    temp = temp.preoperation(lhs, rhs);
    string result = temp.divide(temp.beforePoint, temp.afterPoint);
    //cout << "result: " << result;
    ans.value = "";
    for (int i = 0; i < result.size() ; i++){
        ans.value = ans.value + result[i];
    }
    return result;
    
}


