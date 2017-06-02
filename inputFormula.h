//
//  inputFormula.cpp
//  BigNumber_Integer
//
//  Created by erin on 2017/5/10.
//  Copyright © 2017年 Erin Zhang. All rights reserved.
//

#include "NumberObject.h"
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

// a class for input formula
class inputFormula: public NumberObject{
public:
    bool isOP(char);
    void toStrVector(string);
    void toAns();
    void printFormula();
    vector<string> toMinFormula(vector<string>);
    vector<string> toNewFormula(vector<string>);
    string tempAns(vector<string>);
    
private:
    vector <string> formulaStr;
    vector <string> formulaTemp;
    vector <string> calFormula;
    vector <string> ansFormula;
    vector <string> newFormula;
    string ansNum,leftNum,rightNum,minFormulaAns;
    int startNum,endNum;
};






