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
    Integer I1, I2,I4;
    I1 = "250";
    I2 = "100";
    I4 = I2;
    Integer I3("10");
    Integer I5 = "10";
    cout << I5 << endl;
    cout << I1 << " " << I2 << " " << I4 << endl;
    cout << I1 + I2 << endl;
    cout << I1 - I2 << endl;
    cout << I1 * I2 << endl;
    cout << I1 / I2 << endl;

    
//        Decimal d1, d2;
//        cin >> d1 >> d2;
//        cout << d1 - d2 << endl;
//        cout << d1 * d2 << endl;
//        cout << d1/d2 << endl;
    
//    Complex c1, c2;
//    cin >> c1;
//    cout << c1.Power(c1, "100") << endl;
    //    cout << "c1 + c2 = " << c1 + c2 << endl;
    //    cout << "c1 - c2 = " << c1 - c2 << endl;
    //    cout << "c1 * c2 = " << c1 * c2 << endl;
    //    cout << "c1 / c2 = " << c1 / c2 << endl;
    //    
    return 0;
}





/*
//#include "integer.cpp"
//#include "inputFormula.h"
#include "decimal.cpp"
#include <iostream>

using namespace std;


int main(){
    Decimal d1, d2;
    cin >> d1 >> d2 ;
    cout << d1 + d2 << endl;
    
    
    inputFormula formula;
    string inputStr;
    
    inputStr = "(2*((1+(2+(211*20+7-(3+99))))-2))=";
    
    formula.toStrVector(inputStr);
    formula.printFormula();
    formula.toAns();
    cout << endl;
 
    
    //Integer lhs,rhs;
    //lhs = "1";
    //rhs = "2";
    //cout << lhs.value << endl;
    

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
     
    return 0;
}
*/
