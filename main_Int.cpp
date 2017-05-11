//
//  main.cpp
//  BigNumber_Integer
//
//  Created by erin on 2017/4/27.
//  Copyright © 2017年 Erin Zhang. All rights reserved.
//


#include <iostream>
#include <string>
#include "integer.hpp"
#include "inputFormula.h"


using namespace std;


int main(){
    inputFormula formula;
    string inputStr;
    
    inputStr = "(2*((1+(2+(211*20+7-(3+99))))-2))=";
    
    formula.toStrVector(inputStr);
    formula.printFormula();
    formula.toAns();
    cout << endl;
    
    
    /*
    string num1, num2;
    cin >> num1 >> num2;
    string addResult = AddString(num1, num2);
    string minusResult = MinusString(num1, num2);
    string multiplyResult = KaratsubaMultiply(num1,num2);
    //string devideResult = *devide(num1,num2);
    
    //print
    cout << num1 << " + " << num2 << " = " << addResult << endl;
    cout << num1 << " - " << num2 << " = " << minusResult << endl;
    cout << num1 << " * " << num2 << " = " << multiplyResult << endl;
    //cout << num1 << " / " << num2 << " = " << devideResult << endl;
     */
    return 0;
}
