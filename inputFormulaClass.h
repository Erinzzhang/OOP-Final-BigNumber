//
//  inputFormula.cpp
//  BigNumber_Integer
//
//  Created by erin on 2017/5/10.
//  Copyright © 2017年 Erin Zhang. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>

class inputFormula{
public:
    bool isOP(char);
    void toStrVector(string);
    void ans();
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
    int endNum;
    int startNum;
    
};






