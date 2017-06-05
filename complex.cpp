#include "complex.h"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

Complex::Complex(){
    complexImag.beforePoint = "0";
    complexImag.afterPoint = "0";
    complexReal.beforePoint = "0";
    complexReal.afterPoint = "0";
    real = complexReal.beforePoint + "." + complexReal.afterPoint;
    imag = complexImag.beforePoint + "." + complexImag.afterPoint;
}

Complex::Complex(const char *number){
    string temp(number);
    stringstream ss;
    bool afterP = false;
    char splitChar;
    ss << temp;
    ss >> splitChar;
    complexReal.beforePoint.clear();
    complexReal.afterPoint.clear();
    //input to decimal class
    if(splitChar == '-'){
        complexReal.beforePoint.push_back(splitChar);
        ss >> splitChar;
    }
    
    while(splitChar != '+' && splitChar != '-'){
        if(splitChar == '.'){
            afterP = true;
            ss >> splitChar;
        }
        if(afterP){
            complexReal.afterPoint.push_back(splitChar);
        }else{
            complexReal.beforePoint.push_back(splitChar);
        }
        if(!(ss >> splitChar)){
            break;
        }
    }
    
    
    if(splitChar == '-'){
        complexImag.beforePoint.push_back(splitChar);
    }
    afterP = false;
    if(ss >> splitChar){
        complexImag.beforePoint.clear();
        complexImag.afterPoint.clear();
        if(splitChar == 'i'){
            complexImag.beforePoint.push_back('1');
        }else{
            while(splitChar != 'i'){
                if(splitChar == '.'){
                    afterP = true;
                    ss >> splitChar;
                }
                if(afterP){
                    complexImag.afterPoint.push_back(splitChar);
                    ss >> splitChar;
                }else{
                    complexImag.beforePoint.push_back(splitChar);
                    ss >> splitChar;
                }
            }
        }
    }
    if(complexReal.afterPoint.size() == 0){
        real = complexReal.beforePoint + ".00";
    }else{
        real = complexReal.beforePoint + "." + complexReal.afterPoint;
    }
    
    if(complexImag.afterPoint.size() == 0){
        imag = complexImag.beforePoint + ".00";
    }else{
        imag = complexImag.beforePoint + "." + complexImag.afterPoint;
    }
    
    
}

//overload = operator
Complex& Complex::operator = (const char *number){
    string temp(number);
    stringstream ss;
    bool afterP = false;
    char splitChar;
    ss << temp;
    ss >> splitChar;
    complexReal.beforePoint.clear();
    complexReal.afterPoint.clear();
    //input to decimal class
    if(splitChar == '-'){
        complexReal.beforePoint.push_back(splitChar);
        ss >> splitChar;
    }
    
    while(splitChar != '+' && splitChar != '-'){
        if(splitChar == '.'){
            afterP = true;
            ss >> splitChar;
        }
        if(afterP){
            complexReal.afterPoint.push_back(splitChar);
        }else{
            complexReal.beforePoint.push_back(splitChar);
        }
        if(!(ss >> splitChar)){
            break;
        }
    }
    
    
    if(splitChar == '-'){
        complexImag.beforePoint.push_back(splitChar);
    }
    afterP = false;
    if(ss >> splitChar){
        complexImag.beforePoint.clear();
        complexImag.afterPoint.clear();
        if(splitChar == 'i'){
            complexImag.beforePoint.push_back('1');
        }else{
            while(splitChar != 'i'){
                if(splitChar == '.'){
                    afterP = true;
                    ss >> splitChar;
                }
                if(afterP){
                    complexImag.afterPoint.push_back(splitChar);
                    ss >> splitChar;
                }else{
                    complexImag.beforePoint.push_back(splitChar);
                    ss >> splitChar;
                }
            }
        }
    }
    if(complexReal.afterPoint.size() == 0){
        real = complexReal.beforePoint + ".00";
    }else{
        real = complexReal.beforePoint + "." + complexReal.afterPoint;
    }
    
    if(complexImag.afterPoint.size() == 0){
        imag = complexImag.beforePoint + ".00";
    }else{
        imag = complexImag.beforePoint + "." + complexImag.afterPoint;
    }
    

    return *this;
}

Complex& Complex::operator=(const Complex& rhs)
{
    complexImag.beforePoint = rhs.complexImag.beforePoint;
    complexImag.afterPoint = rhs.complexImag.afterPoint;
    complexReal.beforePoint = rhs.complexReal.beforePoint;
    complexReal.afterPoint = rhs.complexReal.afterPoint;
    return *this;
}

Complex& Complex::operator=(const Decimal& rhs)
{
    complexImag.beforePoint = "0";
    complexImag.afterPoint = "0";
    complexReal.beforePoint = rhs.beforePoint;
    complexReal.afterPoint = rhs.afterPoint;
    return *this;
}

Complex& Complex::operator=(const Integer& rhs)
{
    complexImag.beforePoint = "0";
    complexImag.afterPoint = "0";
    complexReal.beforePoint = rhs.real;
    complexReal.afterPoint = "0";
    return *this;
}


//overload + operator
Complex operator+(const Complex& lhs, const Complex& rhs) {
    Complex result;
    result = result.complexAdd(lhs, rhs);
    return result;
}

Complex operator+(const Complex& lhs, const Decimal& rhs) {
    Complex result,tempComplex;
    tempComplex = rhs;  // convert Decimal to Complex
    result = result.complexAdd(lhs, tempComplex);
    return result;
}

Complex operator+(const Decimal& lhs, const Complex& rhs) {
    Complex result,tempComplex;
    tempComplex = lhs;  // convert Decimal to Complex
    result = result.complexAdd(tempComplex, rhs);
    return result;
}

Complex operator+(const Integer& lhs, const Complex& rhs) {
    Complex result,tempComplex;
    tempComplex = lhs;  // convert Integer to Complex
    result = result.complexAdd(tempComplex, rhs);
    return result;
}

Complex operator+(const Complex& lhs, const Integer& rhs) {
    Complex result,tempComplex;
    tempComplex = rhs;  // convert Integer to Complex
    result = result.complexAdd(lhs, tempComplex);
    return result;
}



//overload - operator
Complex operator-(const Complex& lhs, const Complex& rhs){
    Complex result;
    result = result.complexMinus(lhs, rhs);
    return result;
}

Complex operator-(const Complex& lhs, const Decimal& rhs) {
    Complex result,tempComplex;
    tempComplex = rhs;  // convert Decimal to Complex
    result = result.complexMinus(lhs, tempComplex);
    return result;
}

Complex operator-(const Decimal& lhs, const Complex& rhs) {
    Complex result,tempComplex;
    tempComplex = lhs;  // convert Decimal to Complex
    result = result.complexMinus(tempComplex, rhs);
    return result;
}

Complex operator-(const Integer& lhs, const Complex& rhs) {
    Complex result,tempComplex;
    tempComplex = lhs;  // convert Integer to Complex
    result = result.complexMinus(tempComplex, rhs);
    return result;
}

Complex operator-(const Complex& lhs, const Integer& rhs) {
    Complex result,tempComplex;
    tempComplex = rhs;  // convert Integer to Complex
    result = result.complexMinus(lhs, tempComplex);
    return result;
}


//overload * operator
Complex operator*(const Complex& lhs, const Complex& rhs){
    Complex result;
    result = result.complexMultiply(lhs, rhs);
    return result;
}

Complex operator*(const Complex& lhs, const Decimal& rhs) {
    Complex result,tempComplex;
    tempComplex = rhs;  // convert Decimal to Complex
    result = result.complexMultiply(lhs, tempComplex);
    return result;
}

Complex operator*(const Decimal& lhs, const Complex& rhs) {
    Complex result,tempComplex;
    tempComplex = lhs;  // convert Decimal to Complex
    result = result.complexMultiply(tempComplex, rhs);
    return result;
}

Complex operator*(const Integer& lhs, const Complex& rhs) {
    Complex result,tempComplex;
    tempComplex = lhs;  // convert Integer to Complex
    result = result.complexMultiply(tempComplex, rhs);
    return result;
}

Complex operator*(const Complex& lhs, const Integer& rhs) {
    Complex result,tempComplex;
    tempComplex = rhs;  // convert Integer to Complex
    result = result.complexMultiply(lhs, tempComplex);
    return result;
}


//overload / operator
Complex operator/(const Complex& top, const Complex& bottom){
    Complex result;
    result = result.complexDivide(top, bottom);
    return result;
}

Complex operator/(const Complex& top, const Decimal& bottom) {
    Complex result,tempComplex;
    tempComplex = bottom;  // convert Decimal to Complex
    result = result.complexDivide(top, tempComplex);
    return result;
}

Complex operator/(const Decimal& top, const Complex& bottom) {
    Complex result,tempComplex;
    tempComplex = top;  // convert Decimal to Complex
    result = result.complexDivide(tempComplex, bottom);
    return result;
}

Complex operator/(const Integer& top, const Complex& bottom) {
    Complex result,tempComplex;
    tempComplex = top;  // convert Integer to Complex
    result = result.complexDivide(tempComplex, bottom);
    return result;
}

Complex operator/(const Complex& top, const Integer& bottom) {
    Complex result,tempComplex;
    tempComplex = bottom;  // convert Integer to Complex
    result = result.complexDivide(top, tempComplex);
    return result;
}

//overload >> operator
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
        c.complexReal.beforePoint.push_back(splitChar);
        ss >> splitChar;
    }
    
    while(splitChar != '+' && splitChar != '-'){
        if(splitChar == '.'){
            afterP = true;
            ss >> splitChar;
        }
        if(afterP){
            c.complexReal.afterPoint.push_back(splitChar);
            ss >> splitChar;
        }else{
            c.complexReal.beforePoint.push_back(splitChar);
            ss >> splitChar;
        }
    }
    if(splitChar == '-'){
        c.complexImag.beforePoint.push_back(splitChar);
    }
    afterP = false;
    ss >> splitChar;
    if(splitChar == 'i'){
        c.complexImag.beforePoint.push_back('1');
    }else{
        while(splitChar != 'i'){
            if(splitChar == '.'){
                afterP = true;
                ss >> splitChar;
            }
            if(afterP){
                c.complexImag.afterPoint.push_back(splitChar);
                ss >> splitChar;
            }else{
                c.complexImag.beforePoint.push_back(splitChar);
                ss >> splitChar;
            }
        }
    }
    
    return input;
}

//overload << operator
ostream &operator << (ostream& output, const Complex& c){
    for(int i = 0; i < c.complexReal.beforePoint.size(); i++){
        output << c.complexReal.beforePoint[i];
    }
    output << ".";
    
    if(c.complexReal.afterPoint.size() == 0){
        for(int i = 0; i < 10; i++){
            output << '0';
        }
    }else{
        int j;
        for(j = 0; j < c.complexReal.afterPoint.size(); j++){
            if(j == 10){
                break;
            }
            output << c.complexReal.afterPoint[j];
        }
        while(j < 10){
            output << '0';
            j++;
        }
    }
    if(c.complexImag.beforePoint[0] != '-'){
        output << "+";
    }
    for(int i = 0; i < c.complexImag.beforePoint.size(); i++){
        output << c.complexImag.beforePoint[i];
    }
    output << ".";
    if(c.complexImag.afterPoint.size() == 0){
        for(int i = 0; i < 10; i++){
            output << '0';
        }
    }else{
        int j;
        for(j = 0; j < c.complexImag.afterPoint.size(); j++){
            if(j == 10){
                break;
            }
            output << c.complexImag.afterPoint[j];
            
        }
        while(j < 10){
            output << '0';
            j++;
        }

    }
    output << "i";
    return output;
}
//
//Complex Complex::Power(Complex base, string times){
//    Complex result = base;
//    string one = "1", loop = "1";
//    while(compare(loop, times) != 1){
//        result = result * base;
//        loop = AddString(loop, one);
//    }
//    return result;
//}

Complex Complex::complexAdd(const Complex& lhs, const Complex& rhs){
    Complex result;
    result.complexReal = lhs.complexReal + rhs.complexReal;
    result.complexImag = lhs.complexImag + rhs.complexImag;
    return result;
}

Complex Complex::complexMinus(const Complex& lhs, const Complex& rhs){
    Complex result;
    result.complexReal = lhs.complexReal - rhs.complexReal;
    result.complexImag = lhs.complexImag - rhs.complexImag;
    return result;
}

Complex Complex::complexMultiply(const Complex& lhs, const Complex& rhs){
    Complex result;
    result.complexReal = (lhs.complexReal * rhs.complexReal) - (lhs.complexImag * rhs.complexImag);
    result.complexImag =  (lhs.complexImag * rhs.complexReal) + (lhs.complexReal * rhs.complexImag);
    return result;
}

Complex Complex::complexDivide(const Complex& top, const Complex& bottom){
    Complex rBottom;
    Complex result;
    Decimal negative;
    
    if(result.decimalCheckZero(bottom.complexReal) && result.decimalCheckZero(bottom.complexImag)){
        cout << "can't be divided by zero" << endl;
        result = "0+0i";
        return result;
    }
    
    negative.beforePoint = "-1";
    rBottom.complexReal = bottom.complexReal;
    rBottom.complexImag = bottom.complexImag * negative;
    Decimal bottomPlum = (bottom.complexReal * bottom.complexReal) + (bottom.complexImag * bottom.complexImag);
    
    result.complexReal = (top.complexReal * rBottom.complexReal) - (top.complexImag * rBottom.complexImag);
    result.complexImag = (top.complexImag * rBottom.complexReal) + (top.complexReal * rBottom.complexImag);
    result.complexReal = result.complexReal / bottomPlum;
    result.complexImag = result.complexImag / bottomPlum;
    
    return result;
}

Complex Power(Complex base, string times){
    Complex result = base;
    if(times == "0"){
        result = "1.0+0.0i";
        return result;
    }else if(times == "0.5"){
        result = "1.0+0.0i";
        return result;
    }else{
        string one = "1", loop = "1";
        while(result.compare(loop, times) != 1){
            result = result * base;
            loop = result.AddString(loop, one);
        }
        return result;
    }
}

