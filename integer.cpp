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

//Integer Power(int base, string times){
//    Integer num;
//    if(times == "0"){
//        num.real = "1";
//        return num;
//    }else if(times == "0.5"){
//        num.real = "1";
//        return num;
//    }else{
//        stringstream ss;
//        ss << base;
//        string result = ss.str(), one = "1", loop = "1";
//        while(num.compare(loop, times) != 1){
//            result = num.KaratsubaMultiply(result, ss.str());
//            loop = num.AddString(loop, one);
//        }
//        num.real = result;
//        return num;
//    }
//}

Decimal Power(Integer base, string times){
    Decimal num;
    if(times == "0"){
        num.beforePoint = "1";
        num.afterPoint = "0";
        return num;
    }else if(times == "0.5"){
        //let size become even numbers
        if(base.real.size() % 2 != 0){
            base.real.insert(base.real.begin(), '0');
        }
        
        //start calculating
        string c, root = "0";
        int i = 0;
        while(i < (base.real.size()+20)){
            if(i < base.real.size()){
                c.push_back(base.real[i]);
                i++;
                c.push_back(base.real[i]);
            }else{
                c.push_back('0');
                i++;
                c.push_back('0');
            }
            //compare with squared numbers(1-9)
            for(int x = 1; x <= 10; x++){
                stringstream ss;
                ss << x;
                //y = x(20*root + x)
                string y = num.KaratsubaMultiply(num.AddString(num.KaratsubaMultiply("20", root), ss.str()), ss.str());
                c = num.KaratsubaMultiply("1",c);
                if(num.compare(c, y) == 0){
                    ss.str("");
                    x--;
                    ss << x;
                    y = num.KaratsubaMultiply(num.AddString(num.KaratsubaMultiply("20", root), ss.str()), ss.str());
                    root = num.AddString(num.KaratsubaMultiply("10", root), ss.str());
                    c = num.MinusString(c, y);
                    break;
                }
            }
            i++;
        }
        
        int it;
        for(it = 0; it < base.real.size()/2; it++){
            num.beforePoint.push_back(root[it]);
        }
        while(it < root.size()){
            num.afterPoint.push_back(root[it]);
            it++;
        }
        return num;
    }else{
        string result = base.real, one = "1", loop = "1";
        while(num.compare(loop, times) != 1){
            result = num.KaratsubaMultiply(result, base.real);
            loop = num.AddString(loop, one);
        }
        num.beforePoint = result;
        return num;
//        string one = "1", loop = "1";
//        cout << "loop = " << loop << endl;
//        while(num.compare(loop, times) != 1){
//            num = num * base;
//            loop = num.AddString(loop, one);
//            cout << "loop = " << loop << endl;
//        }
//        return num;
    }
}
