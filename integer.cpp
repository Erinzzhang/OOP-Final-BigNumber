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
    real = "";
}

Integer::Integer(const char *number){
    string temp(number);
    real = number;
}

Integer::Integer(const int number){
    string tempStr = to_string(number);
    real = tempStr;
}

//overload = operator
Integer& Integer::operator=(const int& rhs)
{
    string tempStr = to_string(rhs);
    // do the copy
    real = tempStr;
    // return the existing object so we can chain this operator
    return *this;
}

// A simplistic implementation of operator= (see better implementation below)
Integer& Integer::operator=(const Integer& rhs)
{
    // do the copy
    real = rhs.real;
    // return the existing object so we can chain this operator
    return *this;
}


//overload + operator
Integer operator+(const Integer& lhs, const Integer& rhs) {
    Integer result;
    result.real = result.AddString(lhs.real,rhs.real);
    return result;
}

//overload - operator
Integer operator-(const Integer& lhs, const Integer& rhs) {
    Integer result;
    result.real = result.MinusString(lhs.real,rhs.real);
    return result;
}

//overload * operator
Integer operator*(const Integer& lhs, const Integer& rhs) {
    Integer result;
    result.real = result.KaratsubaMultiply(lhs.real,rhs.real);
    return result;
}

//overload / operator
Integer operator/(const Integer& lhs, const Integer& rhs) {
    Integer result;
    if (rhs.real != "0"){
        result.real = result.integerDivide(lhs.real, rhs.real);
    }else{
        cout << "can't divide." << endl;
    }
    
    return result;
}

//Integer Integer::Power(Integer base, string times){
//    Integer result = base;
//    string one = "1", loop = "1";
//    while(compare(loop, times) != 1){
//        result = result * base;
//        loop = AddString(loop, one);
//    }
//    return result;
//}


//overload << operator
std::ostream &operator<<(std::ostream &os, Integer const &IntegerNum) {
    return os << IntegerNum.real;
}

//overload >> operator
std::istream& operator >> (istream& is, Integer& IntegerNum)
{
    is >> IntegerNum.real;
    return is;
}


string Integer::integerDivide(string a, string b) {
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
    ans.real = "";
    for (int i = 0; i < result.size() ; i++){
        ans.real = ans.real + result[i];
    }
    return result;
    
}

Integer Power(int base, string times){
    Integer num;
    stringstream ss;
    ss << base;
    string result = ss.str(), one = "1", loop = "1";
    while(num.compare(loop, times) != 1){
        result = num.KaratsubaMultiply(result, ss.str());
        loop = num.AddString(loop, one);
    }
    num.real = result;
    return num;
}

Integer Power(Integer base, string times){
    Integer num;
    if(times == "0"){
        num.real = "1";
        return num;
    }else if(times == "0.5"){
        num.real = "1";
        return num;
    }else{
        string result = base.real, one = "1", loop = "1";
        while(num.compare(loop, times) != 1){
            result = num.KaratsubaMultiply(result, base.real);
            loop = num.AddString(loop, one);
        }
        num.real = result;
        return num;
    }
}
