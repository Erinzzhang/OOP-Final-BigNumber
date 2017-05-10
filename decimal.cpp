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
    
    temp = result.preoperation(lhs, rhs);
    string SResult = result.KaratsubaMultiply(temp.beforePoint, temp.afterPoint);
    
    for(int i = 0; i < SResult.size(); i++){
        if(i < ((int)SResult.size() - ((int)lhs.afterPoint.size() + (int)rhs.afterPoint.size()))){
            result.beforePoint.push_back(SResult[i]);
        }else{
            result.afterPoint.push_back(SResult[i]);
        }
    }
    
    return result;
}


Decimal operator/(const Decimal& d1, const Decimal& d2) {
    Decimal lhs = d1, rhs = d2, result, temp;
    
    temp = result.preoperation(lhs, rhs);
    string* SResult = result.devide(temp.beforePoint, temp.afterPoint);
    cout << SResult[0] << endl;
    cout << SResult[1] << endl;
//    for(int i = 0; i < SResult.size(); i++){
//        if(i < ((int)SResult.size() - ((int)lhs.afterPoint.size() + (int)rhs.afterPoint.size()))){
//            result.beforePoint.push_back(SResult[i]);
//        }else{
//            result.afterPoint.push_back(SResult[i]);
//        }
//    }
    
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
