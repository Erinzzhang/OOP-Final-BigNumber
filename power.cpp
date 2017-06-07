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

//NumberObject Power(string base, string times){
//    NumberObject num;
//    if(times == "0"){
//        num.real = "1";
//        return num;
//    }else if(times == "0.5"){
//        num.real = "1";
//        return num;
//    }else{
//        string result = base, one = "1", loop = "1";
//        while(num.compare(loop, times) != 1){
//            result = num.KaratsubaMultiply(result, base);
//            loop = num.AddString(loop, one);
//        }
//        num.real = result;
//        return num;
//    }
//}

NumberObject Power(int base, int times){
    NumberObject num;
    if(times == 0){
        num.real = "1";
        num.type = 0;
        return num;
    }else{
        stringstream t, b;
        t << times;
        b << base;
        string result = b.str(), one = "1", loop = "1";
        while(num.compare(loop, t.str()) != 1){
            result = num.KaratsubaMultiply(result, b.str());
            loop = num.AddString(loop, one);
        }
        num.real = result;
        num.type = 1;
        return num;
    }
}

NumberObject Power(int baseInt, float times){
    Decimal num, base = baseInt;
    NumberObject result;
    if(times == 0.5){
        bool negative = false;
        if(base.beforePoint[0] == '-'){
            base.beforePoint.erase(base.beforePoint.begin());
            negative = true;
        }
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
                string y = num.KaratsubaMultiply(num.AddString(num.KaratsubaMultiply("20", root), ss.str()), ss.str());
                //clean c
                c = num.KaratsubaMultiply("1", c);
                if(num.compare(c, y) == 0 || c == y){
                    ss.str("");
                    if(c != y) x--;
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
        for(it = 0; it < base.beforePoint.size()/2; it++){
            num.beforePoint.push_back(root[it]);
        }
        while(it < root.size()){
            num.afterPoint.push_back(root[it]);
            it++;
        }
        
        if(negative){
            result.real = "0.0";
            result.imag = num.beforePoint + "." + num.afterPoint;
            result.type = 2;
        }else{
            result.real = num.beforePoint + "." + num.afterPoint;
            result.type = 1;
        }
        return result;
    }else{
        cout << "error input" << endl;
        return result;
    }
}

NumberObject Power(float base, int times){
    NumberObject num;
    if(times == 0){
        num.real = "1.0";
        num.type = 1;
        return num;
    }else{
        stringstream b, t;
        b << base;
        t << times;
        string one = "1", loop = "1";
        Decimal temp = b.str().c_str();
        Decimal result = b.str().c_str();
        while(num.compare(loop, t.str()) != 1){
            result = result * temp;
            loop = num.AddString(loop, one);
        }
        num.real = result.beforePoint + "." + result.afterPoint;
        num.type = 1;
        return num;
    }
}

NumberObject Power(float baseFloat, float times){
    Decimal num, base = baseFloat;
    if(times == 0.5){
        bool negative = false;
        if(base.beforePoint[0] == '-'){
            base.beforePoint.erase(base.beforePoint.begin());
            negative = true;
        }
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
                string y = num.KaratsubaMultiply(num.AddString(num.KaratsubaMultiply("20", root), ss.str()), ss.str());
                //clean c
                c = num.KaratsubaMultiply("1", c);
                if(num.compare(c, y) == 0 || c == y){
                    ss.str("");
                    if(c != y) x--;
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
        for(it = 0; it < base.beforePoint.size()/2; it++){
            num.beforePoint.push_back(root[it]);
        }
        while(it < root.size()){
            num.afterPoint.push_back(root[it]);
            it++;
        }

        NumberObject result;
        if(negative){
            result.real = "0.0";
            result.imag = num.beforePoint + "." + num.afterPoint;
            result.type = 2;
        }else{
            result.real = num.beforePoint + "." + num.afterPoint;
            result.type = 1;
        }
        return result;
    }else{
        cout << "error input" << endl;
        return num;
    }
}

NumberObject Power(Integer base, int times) {
    NumberObject num;
    if(times == 0){
        num.real = "1.0";
        num.type = 1;
        return num;
    }else{
        stringstream t;
        t << times;
        string result = base.real, one = "1", loop = "1";
        while(num.compare(loop, t.str()) != 1){
            result = num.KaratsubaMultiply(result, base.real);
            loop = num.AddString(loop, one);
        }
        num.real = result;
        num.type = 1;
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

NumberObject Power(Integer base, float times){
    Decimal num;
    if(times == 0.5){
        bool negative = false;
        if(base.real[0] == '-'){
            base.real.erase(base.real.begin());
            negative = true;
        }
        //let size become even numbers
        if(base.real.size() % 2 != 0){
            base.real.insert(base.real.begin(), '0');
        }
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
        
        NumberObject result;
        if(negative){
            result.real = "0.0";
            result.imag = num.beforePoint + "." + num.afterPoint;
            result.type = 2;
        }else{
            result.real = num.beforePoint + "." + num.afterPoint;
            result.type = 1;
        }
        return result;
    }else{
        cout << "error input for Power(Integer, float)" << endl;
        return num;
    }
}

NumberObject Power(Decimal base, int times){
    Decimal result;
    NumberObject num;
    if(times == 0){
        num.real = "1.0";
        num.type = 1;
        return num;
    }else{
        stringstream t;
        t << times;
        result = base;
        string one = "1", loop = "1";
        cout << "loop = " << loop << endl;
        while(result.compare(loop, t.str()) != 1){
            result = result * base;
            loop = result.AddString(loop, one);
            cout << "loop = " << loop << endl;
        }
        num.real = result.beforePoint + "." + result.afterPoint;
        num.type = 1;
        return num;
    }
}

NumberObject Power(Decimal base, float times){
    Decimal num;
    if(times == 0.5){
        bool negative = false;
        if(base.beforePoint[0] == '-'){
            base.beforePoint.erase(base.beforePoint.begin());
            negative = true;
        }

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
                string y = num.KaratsubaMultiply(num.AddString(num.KaratsubaMultiply("20", root), ss.str()), ss.str());
                //clean c
                c = num.KaratsubaMultiply("1", c);
                if(num.compare(c, y) == 0 || c == y){
                    ss.str("");
                    if(c != y) x--;
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
        for(it = 0; it < base.beforePoint.size()/2; it++){
            num.beforePoint.push_back(root[it]);
        }
        while(it < root.size()){
            num.afterPoint.push_back(root[it]);
            it++;
        }
        
        NumberObject result;
        if(negative){
            result.real = "0.0";
            result.imag = num.beforePoint + "." + num.afterPoint;
            result.type = 2;
        }else{
            result.real = num.beforePoint + "." + num.afterPoint;
            result.type = 1;
        }
        
        return result;
        
        return result;
    }else{
        cout << "error input for Power(Decimal, float)" << endl;
        return num;
    }
}

void Power(Complex base, int times) {
    cout << "Error input for Power(), no complex allowed" << endl;
}

void Power(Complex base, float times) {
    cout << "Error input for Power(), no complex allowed" << endl;
}
