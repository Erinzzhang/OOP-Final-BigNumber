//
//  inputFormula.hpp
//  BigNumber_Integer
//
//  Created by erin on 2017/5/10.
//  Copyright © 2017年 Erin Zhang. All rights reserved.
//

#include <string>
#include <vector>
#include <iostream>
#include "inputFormula.h"
using namespace std;

//is operator?
bool inputFormula::isOP(char word){
    if(((int)(word - '0') <= 9 && (int)(word - '0') >= 0) || word == '.'){
        return false;
    }else{
        return true;
    }
}

//inputFormula to StrVector
void inputFormula::toStrVector(string inputStr){
    char nextWord = '\0' ;
    string strTemp = "";
    for (int i = 0; i < inputStr.size(); i++)
    {
        // nextWord
        if ((i + 1) <= inputStr.size()){
            nextWord = inputStr[i+1];
        }
        
        // store number and operator
        if(isOP(inputStr[i]) == true){
            strTemp = inputStr[i];
            formulaStr.push_back(strTemp);
            strTemp = "";
        }else if (isOP(inputStr[i]) == false ){
            strTemp += inputStr[i];
            if (isOP(nextWord) == true){
                formulaStr.push_back(strTemp);
                strTemp = "";
            }
        }
    }
    
}


vector<string> inputFormula::toMinFormula(vector<string>tempVector){
    calFormula = tempVector;
    vector <string> minFormula;
    string temp;
    
    //find the location of minFormula
    endNum = (int)calFormula.size();
    for (int i = 0; i < endNum; i++){
        temp = calFormula[i];
        if (temp == ")"){
            endNum = i - 1;
            while (temp != "("){
                i --;
                temp = calFormula[i];
            }
            startNum = i + 1;
            break;
        }
        
    }
    
    //build minFormula
    for (int i = startNum; i <= endNum ; i++){
        minFormula.push_back(calFormula[i]);
    }
    
    //calculate the ans of minFormula
    minFormulaAns = tempAns(minFormula);
    return minFormula;
    
}

vector<string> inputFormula::toNewFormula(vector<string>tempVector){
    //clear newFormula
    newFormula.clear();
    
    //build newFormula
    for (int i = 0; i < calFormula.size(); i++){
        if (i == startNum - 1 ){
            newFormula.push_back(minFormulaAns);
            i = endNum + 1;
        }else{
            newFormula.push_back(calFormula[i]);
        }
    }
    
    //print newFormula
    cout <<"new: " ;
    for (int i = 0 ; i < newFormula.size(); i++){
        cout <<  newFormula[i] << " ";
    }
    cout << endl;
    
    // recursion : simplify formula
    newFormula = toMinFormula(newFormula);
    return newFormula;
}


string inputFormula::tempAns(vector<string>minFormula){
    string temp;
    vector<string>::iterator it;
    
    formulaTemp = minFormula;
    int size = (int)formulaTemp.size();
    
    // first : "*","/"
    for (int i = 0 ;i < size; i++){
        temp = formulaTemp[i];
        it = formulaTemp.begin() + i - 1;
        
        if (temp == "*"){
            ansNum = KaratsubaMultiply(formulaTemp[i-1], formulaTemp[i+1]);
            //cout << formulaTemp[i-1] << formulaTemp[i] << formulaTemp[i+1] << " = "  << ansNum << endl;
            formulaTemp.erase(it,it +3);
            formulaTemp.insert( it, ansNum);
            size = (int)formulaTemp.size();
            //ans = d1 * d2;
            //push_back(ans)
        }
        
    }

    
    
    // second : "+","-"
    for (int i = 0 ;i < size; i++){
        temp = formulaTemp[i];
        it = formulaTemp.begin() + i - 1 ;
        if (temp == "+"){
            ansNum = AddString(formulaTemp[i-1], formulaTemp[i+1]);
            //cout << formulaTemp[i-1] << formulaTemp[i] << formulaTemp[i+1] << " = "  << ansNum << endl;
            formulaTemp.erase(it,it +3);
            formulaTemp.insert( it, ansNum);
            size = (int)formulaTemp.size();
            
        }else if  (temp == "-"){
            ansNum = MinusString(formulaTemp[i-1], formulaTemp[i+1]);
            //cout << formulaTemp[i-1] << formulaTemp[i] << formulaTemp[i+1] << " = "  << ansNum << endl;
            formulaTemp.erase(it,it +3);
            formulaTemp.insert( it, ansNum);
            size = (int)formulaTemp.size();
            
            
        }
        // initialize i for rescan formula
        i = 0;
        
    }
    
    return ansNum;
}

void inputFormula::toAns(){
    
    // count how many "(",")"
    int count = 0;
    for (int i = 0; i < formulaStr.size(); i++){
        if (formulaStr[i] == "("){
            count ++;
        }
    }
    
    // simplify formula
    newFormula = toMinFormula(formulaStr);
    for (int i = 0; i < count - 1; i ++){
        newFormula = toNewFormula(calFormula);
    }
    
    // shoe answer
    cout << "Ans: " << minFormulaAns << endl;
    
}

void inputFormula::printFormula(){
    
    //print formula
    for (int i = 0; i < formulaStr.size(); i++){
        cout << formulaStr[i] ;
    }
    cout << endl;
}
