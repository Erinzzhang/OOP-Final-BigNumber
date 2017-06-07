//
//  integer.cpp
//  OOP-BigNumber
//
//  Created by erin on 2017/5/30.
//  Copyright © 2017年 Erin Zhang. All rights reserved.
//

#include "power.h"
#include <iostream>
#include <sstream>

using namespace std;

NumberObject Power(string base, string times){
    NumberObject num;
    if(times == "0"){
        num.real = "1";
        return num;
    }else if(times == "0.5"){
        num.real = "1";
        return num;
    }else{
        string result = base, one = "1", loop = "1";
        while(num.compare(loop, times) != 1){
            result = num.KaratsubaMultiply(result, base);
            loop = num.AddString(loop, one);
        }
        num.real = result;
        return num;
    }
}

NumberObject Power(int, string);

NumberObject Power(float base, string times){
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

NumberObject Power(Integer base, string times) {
    Decimal num;
    if(times == "0"){
        num.beforePoint = "1";
        num.afterPoint = "0";
        return num;
    }else if(times == "0.5"){
        bool negative = false;
        if(base.real[0] == '-'){
            base.real.erase(base.real.begin());
            negative = true;
        }
        //let size become even numbers
        if(base.real.size() % 2 != 0){
            base.real.insert(base.real.begin(), '0');
        }
        cout << base << endl;
        //start calculating
        string c, root = "0";
        int i = 0;
        while(i < (base.real.size()+20)){
            if(i < base.real.size()){
                c.push_back(base.real[i]);
                i++;
                c.push_back(base.real[i]);
            }else{
                c.push_back('0');
                i++;
                c.push_back('0');
            }
            //compare with squared numbers(1-9)
            for(int x = 1; x <= 10; x++){
                stringstream ss;
                ss << x;
                //y = x(20*root + x)
                string y = num.KaratsubaMultiply(num.AddString(num.KaratsubaMultiply("20", root), ss.str()), ss.str());
                c = num.KaratsubaMultiply("1",c);
                if(num.compare(c, y) == 0){
                    ss.str("");
                    x--;
                    ss << x;
                    y = num.KaratsubaMultiply(num.AddString(num.KaratsubaMultiply("20", root), ss.str()), ss.str());
                    root = num.AddString(num.KaratsubaMultiply("10", root), ss.str());
                    c = num.MinusString(c, y);
                    break;
                }
            }
            i++;
        }
        
        int it;
        for(it = 0; it < base.real.size()/2; it++){
            num.beforePoint.push_back(root[it]);
        }
        while(it < root.size()){
            num.afterPoint.push_back(root[it]);
            it++;
        }
        if(negative){
            
        }
        
        return num;
    }else{
        string result = base.real, one = "1", loop = "1";
        while(num.compare(loop, times) != 1){
            result = num.KaratsubaMultiply(result, base.real);
            loop = num.AddString(loop, one);
        }
        num.beforePoint = result;
        return num;
        //        string one = "1", loop = "1";
        //        cout << "loop = " << loop << endl;
        //        while(num.compare(loop, times) != 1){
        //            num = num * base;
        //            loop = num.AddString(loop, one);
        //            cout << "loop = " << loop << endl;
        //        }
        //        return num;
    }
}

NumberObject Power(Decimal base, string times){
    NumberObject result;
    if(times == "0"){
        result = "1.0";
        return result;
    }else if(times == "0.5"){
        //let size become even numbers
        if(base.beforePoint.size() % 2 != 0){
            base.beforePoint.insert(base.beforePoint.begin(), '0');
        }
        if(base.afterPoint.size() % 2 != 0){
            base.afterPoint.push_back('0');
        }
        
        //start calculating
        string c, root = "0";
        int i = 0;
        while(i < (base.beforePoint.size() + base.afterPoint.size()+ 20)){
            if(i < base.beforePoint.size()){
                c.push_back(base.beforePoint[i]);
                i++;
                c.push_back(base.beforePoint[i]);
            }else if (i >= base.beforePoint.size() && i < (base.beforePoint.size() + base.afterPoint.size())){
                c.push_back(base.afterPoint[i - base.beforePoint.size()]);
                i++;
                c.push_back(base.afterPoint[i - base.beforePoint.size()]);
            }else{
                c.push_back('0');
                i++;
                c.push_back('0');
            }
            //compare with squared numbers(1-9)
            for(int x = 0; x <= 10; x++){
                stringstream ss;
                ss << x;
                //y = x(20*root + x)
                string y = result.KaratsubaMultiply(result.AddString(result.KaratsubaMultiply("20", root), ss.str()), ss.str());
                //clean c
                c = result.KaratsubaMultiply("1", c);
                if(result.compare(c, y) == 0 || c == y){
                    ss.str("");
                    if(c != y) x--;
                    ss << x;
                    y = result.KaratsubaMultiply(result.AddString(result.KaratsubaMultiply("20", root), ss.str()), ss.str());
                    root = result.AddString(result.KaratsubaMultiply("10", root), ss.str());
                    c = result.MinusString(c, y);
                    break;
                }
            }
            i++;
        }
        int it;
        for(it = 0; it < base.beforePoint.size()/2; it++){
            result.beforePoint.push_back(root[it]);
        }
        while(it < root.size()){
            result.afterPoint.push_back(root[it]);
            it++;
        }
        
        return result;
    }else{
        result = base;
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

Complex Power(Complex base, string times) {
    cout << "In complex" << endl;
    Complex result = base;
    if(times == "0"){
        result = "1.0+0.0i";
        return result;
    }else if(times == "0.5"){
        result = "1.0+0.0i";
        return result;
    }else{
        string one = "1", loop = "1";
        while(result.compare(loop, times) != 1){
            result = result * base;
            loop = result.AddString(loop, one);
        }
        return result;
    }
}

Complex PowerNegative(string, string);
Complex PowerNegative(int, string);
Complex PowerNegative(float, string);
Complex PowerNegative(Integer, string);
Complex PowerNegative(Decimal, string);
