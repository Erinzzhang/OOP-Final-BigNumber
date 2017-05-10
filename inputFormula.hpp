//
//  inputFormula.hpp
//  BigNumber_Integer
//
//  Created by erin on 2017/5/10.
//  Copyright © 2017年 Erin Zhang. All rights reserved.
//

#ifndef inputFormula_hpp
#define inputFormula_hpp
#include <string>
#include <vector>
#include <iostream>

#include "integer.hpp"
#include "intergerClass.h"
#include "inputFormulaClass.h"


using namespace std;


bool inputFormula::isOP(char word){
    if(((int)(word - '0') <= 9 && (int)(word - '0') >= 0) || word == '.'){
        return false;
    }else{
        return true;
    }
}

void inputFormula::toStrVector(string inputStr){
    char temp= '\0';
    char nextWord = '\0' ;
    string strTemp = "";
    for (int i = 0; i < inputStr.size(); i++){
        temp = inputStr[i];
        //cout << temp << " ";
        if ((i + 1) <= inputStr.size()){
            nextWord = inputStr[i+1];
        }
        
        if(isOP(temp) == true){
            if (temp == '('){
                strTemp = temp;
                formulaStr.push_back(strTemp);
                strTemp = "";
            }else if(temp == '+' || temp == '-' || temp == '*' || temp == '/'){
                strTemp = temp;
                formulaStr.push_back(strTemp);
                strTemp = "";
            }else if (temp == '='){
                strTemp = temp;
                formulaStr.push_back(strTemp);
                strTemp = "";
            }else if (temp == ')'){
                strTemp = temp;
                formulaStr.push_back(strTemp);
                strTemp = "";
                
            }else{
                
            }
        }else if (isOP(temp) == false ){
            
            strTemp += temp;
            if (isOP(nextWord) == true){
                //cout << strTemp << endl;
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
    string ans;
    
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
    
    /*
    //print minFormula
    cout <<"min: ";
    for (int i = 0 ; i < minFormula.size(); i++){
        cout <<  minFormula[i] << " ";
    }
    cout << endl;
    */
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
    return newFormula;
}


string inputFormula::tempAns(vector<string>minFormula){
    formulaTemp = minFormula;
    string temp;
    vector<string>::iterator it;
    int size = (int)formulaTemp.size();
    
    for (int i = 0 ;i < size; i++){
        temp = formulaTemp[i];
        it = formulaTemp.begin() + i - 1;
        
        if (temp == "*"){
            ansNum = KaratsubaMultiply(formulaTemp[i-1], formulaTemp[i+1]);
            //cout << formulaTemp[i-1] << formulaTemp[i] << formulaTemp[i+1] << " = "  << ansNum << endl;
            formulaTemp.erase(it,it +3);
            formulaTemp.insert( it, ansNum);
            size = (int)formulaTemp.size();
            
        }
        
    }
    
    
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
        i = 0;
        
    }
    
    return ansNum;
}

void inputFormula::ans(){
    int count = 0;
    string ans;
    for (int i = 0; i < formulaStr.size(); i++){
        if (formulaStr[i] == "("){
            count ++;
        }
    }
    newFormula = toMinFormula(formulaStr);
    newFormula = toNewFormula(calFormula);
    
    for (int i = 0; i < count - 1; i ++){
        newFormula = toMinFormula(newFormula);
        newFormula = toNewFormula(calFormula);
    }
    
    cout << "Ans: " << minFormulaAns << endl;
    
}

void inputFormula::printFormula(){
    for (int i = 0 ;i < formulaStr.size(); i++){
        cout << i << "\t";
    }
    cout << endl;
    for (int i = 0; i < formulaStr.size(); i++){
        cout << formulaStr[i] << "\t";
    }
    cout << endl;
}

#endif /* inputFormula_hpp */
