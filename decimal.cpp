#include "decimal.h"
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

//decimal constructor function
Decimal::Decimal(){

}

//preoperation for decimal calculation
Decimal Decimal::preoperation(Decimal& lhs, Decimal& rhs) {
    Decimal res;
    
    //set both vector to the same length
    double gapSize = (int)lhs.beforePoint.size() - (int)rhs.beforePoint.size();
    if(gapSize > 0.0) {
        rhs.beforePoint.insert(rhs.beforePoint.begin(), (int)abs(gapSize), '0');
    }
    if (gapSize < 0.0) {
        lhs.beforePoint.insert(lhs.beforePoint.begin(), (int)abs(gapSize), '0');
    }
    
    gapSize = (int)lhs.afterPoint.size() - (int)rhs.afterPoint.size();
    if(gapSize > 0.0){
        for(int i = 0; i < abs(gapSize); i++){
            rhs.afterPoint.push_back('0');
        }
    }
    if (gapSize < 0.0){
        for(int i = 0; i < abs(gapSize); i++){
            lhs.afterPoint.push_back('0');
        }
    }
    
    string l, r;
    l.reserve(lhs.beforePoint.size() + lhs.afterPoint.size());
    r.reserve(rhs.beforePoint.size() + rhs.afterPoint.size());
    l.insert(l.end(), lhs.beforePoint.begin(), lhs.beforePoint.end());
    l.insert(l.end(), lhs.afterPoint.begin(), lhs.afterPoint.end());
    r.insert(r.end(), rhs.beforePoint.begin(), rhs.beforePoint.end());
    r.insert(r.end(), rhs.afterPoint.begin(), rhs.afterPoint.end());
    
    res.beforePoint = l;
    res.afterPoint = r;
    
    return res;
}

//overload + operator
Decimal operator+(const Decimal& d1, const Decimal& d2) {
    Decimal lhs = d1, rhs = d2, result, temp;
    
    temp = result.preoperation(lhs, rhs);
    string SResult = result.AddString(temp.beforePoint, temp.afterPoint);
    
    for(int i = 0; i < SResult.size(); i++){
        if(i < ((int)SResult.size() - (int)lhs.afterPoint.size())){
            result.beforePoint.push_back(SResult[i]);
        }else{
            result.afterPoint.push_back(SResult[i]);
        }
    }
    
    return result;
}

Decimal operator-(const Decimal& d1, const Decimal& d2) {
    Decimal lhs = d1, rhs = d2, result, temp;
    
    temp = result.preoperation(lhs, rhs);
    string SResult = result.MinusString(temp.beforePoint, temp.afterPoint);
    
    for(int i = 0; i < SResult.size(); i++){
        if(i < ((int)SResult.size() - (int)lhs.afterPoint.size())){
            result.beforePoint.push_back(SResult[i]);
        }else{
            result.afterPoint.push_back(SResult[i]);
        }
    }
    
    return result;
}


Decimal operator*(const Decimal& d1, const Decimal& d2) {
    Decimal lhs = d1, rhs = d2, result, temp;
    
    //delete zeros after point
    while(lhs.afterPoint.back() == '0'){
        lhs.afterPoint.pop_back();
    }
    while(rhs.afterPoint.back() == '0'){
        rhs.afterPoint.pop_back();
    }
    
    temp = result.preoperation(lhs, rhs);
    
    string SResult = result.KaratsubaMultiply(temp.beforePoint, temp.afterPoint);
    
    if(((int)lhs.afterPoint.size() + (int)rhs.afterPoint.size()) > (int)SResult.size()){
        result.beforePoint.push_back('0');
        for(int i = 0; i < ((int)lhs.afterPoint.size() + (int)rhs.afterPoint.size()); i++){
            if(i >= (int)SResult.size()){
                result.afterPoint.insert(result.afterPoint.begin(), '0');
            }else{
                result.afterPoint.push_back(SResult[i]);
            }
        }
    }else{
        for(int i = 0; i < SResult.size(); i++){
            if(i < ((int)SResult.size() - ((int)lhs.afterPoint.size() + (int)rhs.afterPoint.size()))){
                result.beforePoint.push_back(SResult[i]);
            }else{
                result.afterPoint.push_back(SResult[i]);
            }
        }
    }
    return result;
}


Decimal operator/(const Decimal& d1, const Decimal& d2) {
    Decimal lhs = d1, rhs = d2, result, temp;
    
    temp = result.preoperation(lhs, rhs);
    string SResult = temp.divide(temp.beforePoint, temp.afterPoint);
    
    bool beforeDot = true;
    for(int i = 0; i < SResult.size(); i++){
        if(SResult[i] == '.'){
            beforeDot = false;
            i++;
        }
        if(beforeDot){
            result.beforePoint.push_back(SResult[i]);
        }
        else{
            result.afterPoint.push_back(SResult[i]);
        }
    }
    
    return result;
}

istream &operator >> (istream& input, Decimal& d) {
    string s;
    stringstream ss;
    char splitChar;
    input >> s;
    ss << s;
    ss >> splitChar;
    //input to decimal class
    while(splitChar != '.'){
        d.beforePoint.push_back(splitChar);
        ss >> splitChar;
    }
    while(ss >> splitChar){
        d.afterPoint.push_back(splitChar);
    }

    return input;
}

ostream &operator << (ostream& output, const Decimal& d) {
    //print numbers before point
    for(int i = 0; i < d.beforePoint.size(); i++) {
        output << d.beforePoint[i];
    }
	output << ".";
    //print numbers after point
    for(int i = 0; i < d.afterPoint.size(); i++) {
        output << d.afterPoint[i];
    }
    
	return output;
}

string Decimal::divide(string a, string b) {
    Decimal result, x1, up, down, xn;
    string one = "1", temp = b;
    up.beforePoint = a;
    down.beforePoint = b;
    
    x1.beforePoint.push_back('0');
    for(int i = 0; i < b.size(); i++) {
        one.push_back('0');
        if(i > 0) x1.afterPoint.push_back('0');
    }
    
    for(int j = 0; j < b.size(); j++){
        for(int i = 1; i < 10; i++) {
            string num;
            num.push_back((char)(i + 48));
            string cmpMulti = result.KaratsubaMultiply(num, temp);
            string oneTemp = result.MinusString(one, cmpMulti);
            if(result.compare(oneTemp, temp) == 0){
                x1.afterPoint.push_back((char)(i + 48));
                string multiplyTen;
                multiplyTen.push_back((char)(10 + 48));
                one = result.KaratsubaMultiply(oneTemp, multiplyTen);
                break;
            }
        }
    }
    
    for(int i = 0; i < a.size() + 1; i++){
        Decimal sTwo;
        sTwo.beforePoint.push_back('2');
        
        //xn = (sTwo - (x1 * down)) * x1;
        xn = x1 * down;
        xn = sTwo - xn;
        xn = xn * x1;
        x1 = xn;
    }
    result = up * xn;
    if(result.beforePoint.size() == 0){
        result.beforePoint.push_back('0');
    }
    string outString = result.beforePoint + "." + result.afterPoint;
    
    return outString;
}
