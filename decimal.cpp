#include "decimal.h"
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

//decimal constructor function
Decimal::Decimal(){
    beforePoint = "";
    afterPoint = "";
    real = beforePoint + "." + afterPoint;
}

//decimal constructor function
Decimal::Decimal(const char *number){
    string temp(number);
    char splitChar;
    stringstream ss;
    ss << temp;
    ss >> splitChar;
    //input to decimal class
    while(splitChar != '.'){
        beforePoint.push_back(splitChar);
        if(!(ss >> splitChar)){
            afterPoint.push_back('0');
            break;
        }
    }
    while(ss >> splitChar){
        afterPoint.push_back(splitChar);
    }
    real = beforePoint + "." + afterPoint;
}

Decimal::Decimal(const double number){
    stringstream ss;
    char splitChar;
    ss << number;
    ss >> splitChar;
    //input to decimal class
    while(splitChar != '.'){
        beforePoint.push_back(splitChar);
        if(!(ss >> splitChar)){
            afterPoint.push_back('0');
            break;
        }
    }
    while(ss >> splitChar){
        afterPoint.push_back(splitChar);
    }
    real = beforePoint + "." + afterPoint;
}


//overload = operator
Decimal& Decimal::operator = (const char *number){
    string temp(number);
    char splitChar;
    stringstream ss;
    ss << temp;
    ss >> splitChar;
    //input to decimal class
    while(splitChar != '.'){
        beforePoint.push_back(splitChar);
        if(!(ss >> splitChar)){
            afterPoint.push_back('0');
            break;
        }
    }
    while(ss >> splitChar){
        afterPoint.push_back(splitChar);
    }
    real = beforePoint + "." + afterPoint;
    return *this;
}

Decimal& Decimal::operator = (const double rhs){
    stringstream ss;
    char splitChar;
    ss << rhs;
    ss >> splitChar;
    string temp = ss.str();
    //input to decimal class
    while(splitChar != '.'){
        beforePoint.push_back(splitChar);
        if(!(ss >> splitChar)){
            afterPoint.push_back('0');
            break;
        }
    }
    while(ss >> splitChar){
        afterPoint.push_back(splitChar);
    }
    // return the existing object so we can chain this operator
    real = beforePoint + "." + afterPoint;
    return *this;
}
Decimal& Decimal::operator=(const Decimal& rhs)
{
    beforePoint = rhs.beforePoint;
    afterPoint = rhs.afterPoint;
    // return the existing object so we can chain this operator
    real = beforePoint + "." + afterPoint;
    return *this;
}

Decimal& Decimal::operator=(const Integer& rhs)
{
    beforePoint = rhs.real;
    afterPoint = "0";
    // return the existing object so we can chain this operator
    real = beforePoint + "." + afterPoint;
    return *this;
}


//overload + operator
Decimal operator+(const Decimal& d1, const Decimal& d2) {
    Decimal result;
    result = result.decimalAdd(d1, d2);
    return result;
}

Decimal operator+(const Decimal& lhs, const Integer& rhs) {
    Decimal result,tempDecimal;
    tempDecimal = rhs;  // convert Integer to Complex
    result = result.decimalAdd(lhs, tempDecimal);
    return result;
}

Decimal operator+(const Integer& lhs, const Decimal& rhs) {
    Decimal result,tempDecimal;
    tempDecimal = lhs;  // convert Integer to Complex
    result = result.decimalAdd(tempDecimal, rhs);
    return result;
}

//overload - operator
Decimal operator-(const Decimal& d1, const Decimal& d2) {
    Decimal result;
    result = result.decimalMinus(d1, d2);
    return result;
}

Decimal operator-(const Decimal& lhs, const Integer& rhs) {
    Decimal result,tempDecimal;
    tempDecimal = rhs;  // convert Integer to Complex
    result = result.decimalMinus(lhs, tempDecimal);
    return result;
}

Decimal operator-(const Integer& lhs, const Decimal& rhs) {
    Decimal result,tempDecimal;
    tempDecimal = lhs;  // convert Integer to Complex
    cout << "tmep:" << tempDecimal << endl;
    result = result.decimalMinus(tempDecimal, rhs);
    return result;
}

//overload * operator
Decimal operator*(const Decimal& d1, const Decimal& d2) {
    Decimal result;
    result = result.decimalMultiply(d1, d2);
    return result;
}

Decimal operator*(const Decimal& lhs, const Integer& rhs) {
    Decimal result,tempDecimal;
    tempDecimal = rhs;  // convert Integer to Complex
    result = result.decimalMultiply(lhs, tempDecimal);
    return result;
}

Decimal operator*(const Integer& lhs, const Decimal& rhs) {
    Decimal result,tempDecimal;
    tempDecimal = lhs;  // convert Integer to Complex
    result = result.decimalMultiply(tempDecimal, rhs);
    return result;
}

Decimal operator*(const Decimal& lhs, const double rhs) {
    Decimal result,tempDecimal;
    tempDecimal = rhs;  // convert Integer to Complex
    result = result.decimalMultiply(lhs, tempDecimal);
    return result;
}

Decimal operator*(const double lhs, const Decimal& rhs) {
    Decimal result,tempDecimal;
    tempDecimal = lhs;  // convert Integer to Complex
    result = result.decimalMultiply(tempDecimal, rhs);
    return result;
}

//overload / operator
Decimal operator/(const Decimal& d1, const Decimal& d2) {
    Decimal result;
    result = result.decimalDivide(d1, d2);
    return result;
}

Decimal operator/(const Decimal& lhs, const Integer& rhs) {
    Decimal result,tempDecimal;
    tempDecimal = rhs;  // convert Integer to Complex
    result = result.decimalDivide(lhs, tempDecimal);
    return result;
}

Decimal operator/(const Integer& lhs, const Decimal& rhs) {
    Decimal result,tempDecimal;
    tempDecimal = lhs;  // convert Integer to Complex
    result = result.decimalDivide(tempDecimal, rhs);
    return result;
}

//overload >> operator
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

//overload << operator
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
    real = beforePoint + "." + afterPoint;
    return res;
}

//decimalAdd for decimal calculation
Decimal Decimal::decimalAdd(const Decimal& d1, const Decimal& d2){
    Decimal lhs = d1, rhs = d2, result, temp;
    bool negative = false;
    string SResult;
    
    
    //process '-'
    if(lhs.beforePoint[0] == '-' && rhs.beforePoint[0] == '-'){   // -(a+b)
        lhs.beforePoint.erase(lhs.beforePoint.begin());
        rhs.beforePoint.erase(rhs.beforePoint.begin());
        negative = true;
        temp = result.preoperation(lhs, rhs);
        SResult = result.AddString(temp.beforePoint, temp.afterPoint);
    }else if(lhs.beforePoint[0] == '-' && rhs.beforePoint[0] != '-'){     // b-a
        lhs.beforePoint.erase(lhs.beforePoint.begin());
        temp = result.preoperation(lhs, rhs);
        SResult = result.MinusString(temp.afterPoint, temp.beforePoint);
    }else if(lhs.beforePoint[0] != '-' && rhs.beforePoint[0] == '-'){     // a-b
        rhs.beforePoint.erase(rhs.beforePoint.begin());
        temp = result.preoperation(lhs, rhs);
        SResult = result.MinusString(temp.beforePoint, temp.afterPoint);
    }else{
        temp = result.preoperation(lhs, rhs);
        SResult = result.AddString(temp.beforePoint, temp.afterPoint);
    }
    
    for(int i = 0; i < SResult.size(); i++){
        if(i < ((int)SResult.size() - (int)lhs.afterPoint.size())){
            result.beforePoint.push_back(SResult[i]);
        }else{
            result.afterPoint.push_back(SResult[i]);
        }
    }
    
    if(result.beforePoint.size() == 0){
        result.beforePoint.push_back('0');
    }
    
    //delete the 0 in front of the number
    reverse(result.beforePoint.begin(), result.beforePoint.end());
    while(result.beforePoint.back() == '0' && result.beforePoint.size() > 1){
        result.beforePoint.pop_back();
    }
    reverse(result.beforePoint.begin(), result.beforePoint.end());
    
    if(result.beforePoint.size() == 0 || (result.beforePoint.size() == 1 && result.beforePoint.back() == '-')){
        result.beforePoint.push_back('0');
    }
    if(result.afterPoint.size() == 0){
        result.afterPoint.push_back('0');
    }
    
    if(negative){
        result.beforePoint.insert(result.beforePoint.begin(), '-');
    }
    
    
    result.real = result.beforePoint + "." + result.afterPoint;
    return result;
}

//decimalMinus for decimal calculation
Decimal Decimal::decimalMinus(const Decimal& d1, const Decimal& d2){
    Decimal lhs = d1, rhs = d2, result, temp;
    string SResult;
    bool negative = false;
    
    //process '-'
    if(lhs.beforePoint[0] == '-' && rhs.beforePoint[0] == '-'){   // b-a
        lhs.beforePoint.erase(lhs.beforePoint.begin());
        rhs.beforePoint.erase(rhs.beforePoint.begin());
        temp = result.preoperation(lhs, rhs);
        SResult = result.MinusString(temp.afterPoint, temp.beforePoint);
    }else if(lhs.beforePoint[0] == '-' && rhs.beforePoint[0] != '-'){     // -(a+b)
        lhs.beforePoint.erase(lhs.beforePoint.begin());
        negative = true;
        temp = result.preoperation(lhs, rhs);
        SResult = result.AddString(temp.beforePoint, temp.afterPoint);
    }else if(lhs.beforePoint[0] != '-' && rhs.beforePoint[0] == '-'){     // a+b
        rhs.beforePoint.erase(rhs.beforePoint.begin());
        temp = result.preoperation(lhs, rhs);
        SResult = result.AddString(temp.beforePoint, temp.afterPoint);
    }else{
        temp = result.preoperation(lhs, rhs);
        SResult = result.MinusString(temp.beforePoint, temp.afterPoint);
    }
    
    for(int i = 0; i < SResult.size(); i++){
        if(i < ((int)SResult.size() - (int)lhs.afterPoint.size())){
            result.beforePoint.push_back(SResult[i]);
        }else{
            result.afterPoint.push_back(SResult[i]);
        }
    }
    
    if(result.beforePoint.size() == 0){
        result.beforePoint.push_back('0');
    }
    
    //delete the 0 in front of the number
    reverse(result.beforePoint.begin(), result.beforePoint.end());
    while(result.beforePoint.back() == '0' && result.beforePoint.size() > 1){
        result.beforePoint.pop_back();
    }
    reverse(result.beforePoint.begin(), result.beforePoint.end());
    
    if(result.beforePoint.size() == 0 || (result.beforePoint.size() == 1 && result.beforePoint.back() == '-')){
        result.beforePoint.push_back('0');
    }
    if(result.afterPoint.size() == 0){
        result.afterPoint.push_back('0');
    }
    
    if(negative){
        result.beforePoint.insert(result.beforePoint.begin(), '-');
    }
    
//    cout  << "result.beforePoint: " << result.beforePoint << endl;
    result.real = result.beforePoint + "." + result.afterPoint;     // bug: 100.0 - 100.1 = -.1 ,need:-0.1
    return result;

    
}

//decimalMultiply for decimal calculation
Decimal Decimal::decimalMultiply(const Decimal& d1, const Decimal& d2){
    Decimal lhs = d1, rhs = d2, result, temp;
    bool negative = false;
    
    if(lhs.beforePoint[0] == '-' && rhs.beforePoint[0] == '-'){
        lhs.beforePoint.erase(lhs.beforePoint.begin());
        rhs.beforePoint.erase(rhs.beforePoint.begin());
    }else if(lhs.beforePoint[0] == '-' && rhs.beforePoint[0] != '-'){
        lhs.beforePoint.erase(lhs.beforePoint.begin());
        negative = true;
    }else if(lhs.beforePoint[0] != '-' && rhs.beforePoint[0] == '-'){
        rhs.beforePoint.erase(rhs.beforePoint.begin());
        negative = true;
    }
    
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
    
    if(result.beforePoint.size() == 0){
        result.beforePoint.push_back('0');
    }
    
    //delete the 0 in front of the number
    reverse(result.beforePoint.begin(), result.beforePoint.end());
    while(result.beforePoint.back() == '0' && result.beforePoint.size() > 1){
        result.beforePoint.pop_back();
    }
    reverse(result.beforePoint.begin(), result.beforePoint.end());
    
    if(result.beforePoint.size() == 0){
        result.beforePoint.push_back('0');
    }
    if(result.afterPoint.size() == 0){
        result.afterPoint.push_back('0');
    }
    
    if(negative){
        result.beforePoint.insert(result.beforePoint.begin(), '-');
    }
    
    
    result.real = result.beforePoint + "." + result.afterPoint;
    return result;
}

//decimalDivide for decimal calculation
Decimal Decimal::decimalDivide(const Decimal& d1, const Decimal& d2){
    Decimal lhs = d1, rhs = d2, result, temp;
    bool negative = false;
    
    if(lhs.beforePoint[0] == '-' && rhs.beforePoint[0] == '-'){
        lhs.beforePoint.erase(lhs.beforePoint.begin());
        rhs.beforePoint.erase(rhs.beforePoint.begin());
    }else if(lhs.beforePoint[0] == '-' && rhs.beforePoint[0] != '-'){
        lhs.beforePoint.erase(lhs.beforePoint.begin());
        negative = true;
    }else if(lhs.beforePoint[0] != '-' && rhs.beforePoint[0] == '-'){
        rhs.beforePoint.erase(rhs.beforePoint.begin());
        negative = true;
    }
    
    if(decimalCheckZero(rhs)){
        cout << "can't be divided by zero" << endl;
        result.beforePoint.push_back('0');
        result.afterPoint.push_back('0');
        return result;
    }
    
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
    
    //delete the 0 in front of the number
    reverse(result.beforePoint.begin(), result.beforePoint.end());
    while(result.beforePoint.back() == '0' && result.beforePoint.size() > 1){
        result.beforePoint.pop_back();
    }
    reverse(result.beforePoint.begin(), result.beforePoint.end());
    
    if(result.beforePoint.size() == 0 || (result.beforePoint.size() == 1 && result.beforePoint.back() == '-')){
        result.beforePoint.push_back('0');
    }
    if(result.afterPoint.size() == 0){
        result.afterPoint.push_back('0');
    }
    
    if(negative){
        result.beforePoint.insert(result.beforePoint.begin(), '-');
    }
    

    result.real = result.beforePoint + "." + result.afterPoint;
    return result;

}

//Power for decimal calculation
//Decimal Decimal::Power(Decimal base, string times){
//    Decimal result = base;
//    string one = "1", loop = "1";
//    cout << "loop = " << loop << endl;
//    while(compare(loop, times) != 1){
//        result = result * base;
//        loop = AddString(loop, one);
//        cout << "loop = " << loop << endl;
//        
//    }
//    return result;
//}


//divide calculation for decimalDivide function
string Decimal::divide(string a, string b) {
    Decimal result, x1;
    bool negative = false;
    
    if(a[0] == '-' && b[0] == '-'){
        a.erase(a.begin());
        b.erase(b.begin());
    }else if(a[0] == '-' && b[0] != '-'){
        a.erase(a.begin());
        negative = true;
    }else if(a[0] != '-' && b[0] == '-'){
        b.erase(b.begin());
        negative = true;
    }
    
    string top, temp = b, ten = "10";
    a = result.KaratsubaMultiply("1", a);   //clear the zeros before (a)
    temp = result.KaratsubaMultiply("1", temp);     //clear the zeros before temp
    top.push_back(a[0]);
    
    
    for(int i = 0; i < temp.length() - 1; i++) {
        if(a.length()-1 > i){
            top.push_back(a[i+1]);
        }else if((a.length() - 1) == i){
            top.push_back('0');
            x1.beforePoint.push_back('0');
        }else{
            top.push_back('0');
            x1.afterPoint.push_back('0');
        }
    }
    
    int topLength = (int)top.length();
    for(int j = topLength; j <= 1000; j++){
        for(int i = 1; i < 10; i++) {   //multiply until the gap between cmpMulti and top is less than temp
            string num;
            num.push_back((char)(i + 48));
            string cmpMulti = result.KaratsubaMultiply(num, temp);  //multiply starting from one
            string topTemp = result.MinusString(top, cmpMulti);     //minus by the multiplied number
            
            //if topTemp is smaller than temp, enter
            if(result.compare(topTemp, temp) == 0){
                if(topTemp[0] == '-') i--; //minus i by one if the topTemp is a negative number -> i = 0
                else top = topTemp;  //cover top with the remaining value if topTemp is positive
                
                if(j < a.length()){     //if there is more digits in (a), read another digit from (a), and add i to beforePoint
                    top.push_back(a[j]);
                    x1.beforePoint.push_back((char)(i + 48));
                }else if(j == a.length()){  //if the same length, push i at beforePoint and add 0 to top
                    top = result.KaratsubaMultiply(top, "10");
                    x1.beforePoint.push_back((char)(i + 48));
                }else{      //push i at afterPoint and add 0 to top
                    top = result.KaratsubaMultiply(top, "10");
                    x1.afterPoint.push_back((char)(i + 48));
                }
                top = result.KaratsubaMultiply(top, "1");
                break;
            }
        }
    }
    
    if(result.beforePoint.size() == 0 || (result.beforePoint.size() == 1 && result.beforePoint.back() == '-')){
        result.beforePoint.push_back('0');
    }
    if(result.afterPoint.size() == 0){
        result.afterPoint.push_back('0');
    }
    
    if(negative){
        x1.beforePoint.insert(x1.beforePoint.begin(), '-');
    }
    
    string outString = x1.beforePoint + "." + x1.afterPoint;
    return outString;
}


//string Decimal::divide(string a, string b) {
//    Decimal result, x1, up, down, xn;
//    bool negative = false;
//
//    if(a[0] == '-' && b[0] == '-'){
//        a.erase(a.begin());
//        b.erase(b.begin());
//    }else if(a[0] == '-' && b[0] != '-'){
//        a.erase(a.begin());
//        negative = true;
//    }else if(a[0] != '-' && b[0] == '-'){
//        b.erase(b.begin());
//        negative = true;
//    }
//
//    string one = "1", temp = b, ten = "10";
//    up.beforePoint = a;
//    down.beforePoint = b;
//    cout << temp << endl;
//    temp = result.KaratsubaMultiply(one, temp);
//    cout << temp << endl;
//    x1.beforePoint.push_back('0');
//    for(int i = 0; i < temp.length() - 1; i++) {
//        one.push_back('0');
//        if(i > 0) x1.afterPoint.push_back('0');
//        //if((b.size()-1) == 0) x1.afterPoint.push_back('0');
//    }
//
//    cout << one << endl;
//
//    for(int j = 0; j < b.size(); j++){
//        for(int i = 1; i < 10; i++) {
//            string num;
//            num.push_back((char)(i + 48));
//            string cmpMulti = result.KaratsubaMultiply(num, temp);
//            string oneTemp = result.MinusString(one, cmpMulti);
//            if(result.compare(oneTemp, temp) == 0){
//                string multiplyTen;
//                multiplyTen.push_back((char)(10 + 48));
//                if(oneTemp[0] == '-'){
//                    i--;
//                    x1.afterPoint.push_back((char)(i + 48));
//                    one = result.KaratsubaMultiply(one, multiplyTen);
//                }else{
//                    x1.afterPoint.push_back((char)(i + 48));
//                    one = result.KaratsubaMultiply(oneTemp, multiplyTen);
//                }
//                break;
//            }
//        }
//    }
//
//    cout << one << endl;
//
//    for(int i = 0; i < a.size() + 1; i++){
//        Decimal sTwo;
//        sTwo.beforePoint.push_back('2');
//
//        //xn = (sTwo - (x1 * down)) * x1;
//        xn = x1 * down;
//        cout << x1 << "," << down << endl;
//        cout << xn << endl;
//        xn = sTwo - xn;
//        cout << xn << endl;
//        xn = xn * x1;
//        cout << xn << endl;
//        x1 = xn;
//    }
//    result = up * xn;
//    if(result.beforePoint.size() == 0){
//        result.beforePoint.push_back('0');
//    }
//
//    if(negative){
//        result.beforePoint.insert(result.beforePoint.begin(), '-');
//    }
//
//    string outString = result.beforePoint + "." + result.afterPoint;
//
//    return outString;
//}

Decimal Power(float base, string times){
    Decimal num;
    if(times == "0"){
        num = "1.0";
        return num;
    }else if(times == "0.5"){
        num = "1.0";
        return num;
    }else{
        stringstream ss;
        ss << base;
        string one = "1", loop = "1";
        Decimal temp = ss.str().c_str();
        Decimal result = ss.str().c_str();
        while(num.compare(loop, times) != 1){
            result = result * temp;
            loop = num.AddString(loop, one);
        }
        num = result;
        return num;
    }
}


Decimal Power(Decimal base, string times){
    Decimal result = base;
    if(times == "0"){
        result = "1.0";
        return result;
    }else if(times == "0.5"){
        result = "1.0";
        return result;
    }else{
        string one = "1", loop = "1";
        cout << "loop = " << loop << endl;
        while(result.compare(loop, times) != 1){
            result = result * base;
            loop = result.AddString(loop, one);
            cout << "loop = " << loop << endl;
        }
        return result;
    }
}

bool Decimal::decimalCheckZero(Decimal d){
    bool zero = true;
    for(int i = 0; i < d.beforePoint.size(); i++){
        if(d.beforePoint[i] != '0'){
            zero = false;
        }
    }
    for(int i = 0; i < d.afterPoint.size(); i++){
        if(d.afterPoint[i] != '0'){
            zero = false;
        }
    }
    return zero;
}
