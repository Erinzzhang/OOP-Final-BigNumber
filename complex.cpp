#include "complex.h"
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

Complex operator+(const Complex& lhs, const Complex& rhs) {
    Complex result;
    result.real = lhs.real + rhs.real;
    result.imag = lhs.imag + rhs.imag;
    return result;
}

Complex operator-(const Complex& lhs, const Complex& rhs){
    Complex result;
    result.real = lhs.real - rhs.real;
    result.imag = lhs.imag - rhs.imag;
    return result;
}

Complex operator*(const Complex& lhs, const Complex& rhs){
    Complex result;
    result.real = (lhs.real * rhs.real) - (lhs.imag * rhs.imag);
    result.imag =  (lhs.imag * rhs.real) + (lhs.real * rhs.imag);
    return result;
}

Complex operator/(const Complex& top, const Complex& bottom){
    Complex rBottom;
    Complex result;
    Decimal negative;
    negative.beforePoint = "-1";
    rBottom.real = bottom.real;
    rBottom.imag = bottom.imag * negative;
    Decimal bottomPlum = (bottom.real * bottom.real) + (bottom.imag * bottom.imag);
    
    result.real = (top.real * rBottom.real) - (top.imag * rBottom.imag);
    result.imag = (top.imag * rBottom.real) + (top.real * rBottom.imag);
    result.real = result.real / bottomPlum;
    result.imag = result.imag / bottomPlum;
    
    return result;
}

istream &operator >> (istream& input, Complex& c){
    string s;
    stringstream ss;
    bool afterP = false;
    char splitChar;
    input >> s;
    ss << s;
    ss >> splitChar;
    
    //input to decimal class
    if(splitChar == '-'){
        c.real.beforePoint.push_back(splitChar);
        ss >> splitChar;
    }
    
    while(splitChar != '+' && splitChar != '-'){
        if(splitChar == '.'){
            afterP = true;
            ss >> splitChar;
        }
        if(afterP){
            c.real.afterPoint.push_back(splitChar);
            ss >> splitChar;
        }else{
            c.real.beforePoint.push_back(splitChar);
            ss >> splitChar;
        }
    }
    if(splitChar == '-'){
        c.imag.beforePoint.push_back(splitChar);
    }
    afterP = false;
    ss >> splitChar;
    if(splitChar == 'i'){
        c.imag.beforePoint.push_back('1');
    }else{
        while(splitChar != 'i'){
            if(splitChar == '.'){
                afterP = true;
                ss >> splitChar;
            }
            if(afterP){
                c.imag.afterPoint.push_back(splitChar);
                ss >> splitChar;
            }else{
                c.imag.beforePoint.push_back(splitChar);
                ss >> splitChar;
            }
        }
    }
    
    return input;
}

ostream &operator << (ostream& output, const Complex& c){
    for(int i = 0; i < c.real.beforePoint.size(); i++){
        output << c.real.beforePoint[i];
    }
    output << ".";
    
    if(c.real.afterPoint.size() == 0){
        for(int i = 0; i < 10; i++){
            output << '0';
        }
    }else{
        int j;
        for(j = 0; j < c.real.afterPoint.size(); j++){
            if(j == 10){
                break;
            }
            output << c.real.afterPoint[j];
        }
        while(j < 10){
            output << '0';
            j++;
        }
    }
    if(c.imag.beforePoint[0] != '-'){
        output << "+";
    }
    for(int i = 0; i < c.imag.beforePoint.size(); i++){
        output << c.imag.beforePoint[i];
    }
    output << ".";
    if(c.imag.afterPoint.size() == 0){
        for(int i = 0; i < 10; i++){
            output << '0';
        }
    }else{
        int j;
        for(j = 0; j < c.imag.afterPoint.size(); j++){
            if(j == 10){
                break;
            }
            output << c.imag.afterPoint[j];
            
        }
        while(j < 10){
            output << '0';
            j++;
        }

    }
    output << "i";
    return output;
}
