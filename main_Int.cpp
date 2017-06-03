//
//  main.cpp
//  BigNumber_Integer
//
//  Created by erin on 2017/4/27.
//  Copyright © 2017年 Erin Zhang. All rights reserved.
//

#include "complex.h"
#include <iostream>

using namespace std;


int main(){
    
    
    // 重載三個數字類別的 Constructor
    Integer i = "100";
    Decimal d = "100.0";
    Complex c = "100+100i";
    i = "100";
    
    // 三個數值類別繼承自 NumberObject
    vector<NumberObject*> nums; nums.push_back(&i); nums.push_back(&d); nums.push_back(&c);
    for(const auto& num : nums){
        cout << *num << endl;
    }
    cout << endl;
    
    // 任意數的加減乘除及括弧運算。
    cout << (i + d - c)*c/(c-i)<< endl;
    cout << endl;
    
    // Integer、Decimal、Complex 重載operator <<, >>, +, -, *, /分別為輸出、輸入及四則運算功能,並且可以互相運算
    cout << "+:" << endl;
    cout << i + d << endl;
    cout << i + c << endl;
    cout << d + c << endl;
    cout << endl;

    cout << "- : " << endl;
    cout << i - d << endl;
    cout << i - c << endl;
    cout << d - c << endl;
    cout << endl;

    cout << "* : " << endl;
    cout << i * d << endl;
    cout << i * c << endl;
    cout << d * c << endl;
    cout << endl;

    cout << "/ : " << endl;
    cout << i / d << endl;
    cout << i / c << endl;
    cout << d / c << endl;
    cout << endl;

    
//    cout << "Complex" << endl;
//    Complex c1 = "1.2+i";
//    Complex c2,c3=c1,c4=c3;
//    c2 = "2.2+2i";
//    c3 = c2;
//    cout << c1 << endl << c2 << endl;
//    cout << c3 << endl << c4 << endl;
//    cout << endl;
//    cout << c1 + c2 << endl;
//    cout << c1 - c2  << endl;
//    cout << c1 * c2  << endl;
//    cout << c1 / c2  << endl;
//    cout << endl;
//
//    cout << "Decimal" << endl;
//    Decimal d1 = "100.0";
//    Decimal d2,d3;
//    d2 = "100.1";
//    d3 = d2;
//    cout << d1 << endl << d2 << endl << d3 << endl;
//    cout << d1 + d2 << endl;
//    cout << d1 - d2 << endl;
//    cout << d1 * d2 << endl;
//    cout << d1/d2 << endl;
//    cout << endl;
//
//    cout << "Integer" << endl;
//    Integer I1, I2,I4;
//    I1 = "10";
//    I2 = "20";
//    I4 = I2;
//    Integer I3("30");
//    Integer I5 = "50";
//    
//    cout << I1 << " " << I2 << " " << I3 << " " << I4 << " " << I5 << endl;
//    cout << I1 + I2 << endl;
//    cout << I1 - I2 << endl;
//    cout << I1 * I2 << endl;
//    cout << I1 / I2 << endl;


    
//    inputFormula formula;
//    string inputStr;
//    
//    inputStr = "(2.0*((1.0+(2.0+(211.0*20.0+7.0-(3.0+99.0))))-2))=";
//    
//    formula.toStrVector(inputStr);
//    formula.printFormula();
//    formula.toAns();
//    cout << endl;

     
    return 0;
}

