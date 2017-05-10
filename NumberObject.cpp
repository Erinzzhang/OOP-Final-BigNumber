#include "NumberObject.h"
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

vector<int> NumberObject::add(vector<int> num1, vector<int> num2, bool isDecimalAfterPoint) {
	vector<int> result;		//a vector to sort results
	int ten = 0;
    
    //set both vector to the same length
    double gapSize = num1.size() - num2.size();
    if(gapSize > 0.0){
        if(isDecimalAfterPoint){
            for(int i = 0; i < gapSize; i++){
                num2.push_back(0);
            }
        }else{
            num2.insert(num2.begin(), (int)abs(gapSize), 0);
        }
    }
    if (gapSize < 0.0){
        if(isDecimalAfterPoint){
            for(int i = 0; i < gapSize; i++){
                num1.push_back(0);
            }
        }else{
            num1.insert(num1.begin(), (int)abs(gapSize), 0);
        }
    }
	
    //reverse the vector to calculate from the ones
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
    
    //start addition
	for (int i = 0; i < num1.size(); i++) {		//calculate one number at a time
		int sum = num1[i] + num2[i] + ten;		//add the ten that was left from last times calculation
		ten = sum / 10;		//save ten for later 
		result.push_back(sum % 10);		//add the result into the vector
	}
	if (ten != 0) {		//if ten isn't zero add it to the result vector
		result.push_back(ten);
	}
    reverse(result.begin(), result.end());
    
	return result;
}

vector<int> NumberObject::sub(vector<int> num1, vector<int> num2) {
	vector<int> result;
	int ten = 0;	//ten is whether the previous calculation had minus off one from the next tens

    //set both vector to the same length
    double gapSize = num1.size() - num2.size();
    if(gapSize > 0.0){
        num2.insert(num2.begin(), (int)abs(gapSize), 0);
    }
    if (gapSize < 0.0){
        num1.insert(num1.begin(), (int)abs(gapSize), 0);
    }

	//reverse the vector to calculate from the ones
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());

	if (num1.back() < num2.back()) {	//let the larger number minus the smaller one
		vector <int> temp;
		temp = num1;
		num1 = num2;
		num2 = temp;
		cout << "-";		//if swap, remember to add "-" into the output
	}

	for (int i = 0; i < num1.size(); i++) {
		int sum = num1[i] - num2[i] - ten;
		if (sum < 0) {
			ten = 1;	//set the ten for later minus
			sum = 10 + sum;
		}
		else {
			ten = 0;
		}
		result.push_back(sum);	//push back the result
	}
    reverse(result.begin(), result.end());
    
	return result;
}

// given two unequal sized bit strings, converts them to
// same length by adding leading 0s in the smaller string. Returns the
// the new length
int NumberObject::MakeSameLen(string& num1,string& num2){
    int len1 = (int)num1.length();
    int len2 = (int)num2.length();
    if(len1 < len2){
        for(int i = 0;i < len2 - len1;++i){
            num1 = "0" + num1;
        }
        return len2;
    }
    else{
        for(int i = 0;i < len1 - len2;++i){
            num2 = "0" + num2;
        }
        return len1;
    }
}

// big number minus function
string NumberObject::MinusString(string num1, string num2) {
    int len1 = (int)num1.length();
    int len2 = (int)num2.length();
    
    // equal
    if(num1 == num2){
        return "0";
    }
    // + or -
    bool positive = true;
    if(len1 < len2 || (len1 == len2 && num1 < num2)){
        positive = false;
        // 交換數字，使 num1 > num2
        string tmp = num1;
        num1 = num2;
        num2 = tmp;
        int temp = len1;
        len1 = len2;
        len2 = temp;
    }
    string result;
    int i = len1 - 1,j = len2 - 1;
    int a,b,sum,carray = 0;
    // 从低位到高位對位做减法
    while(i >= 0 || j >= 0){
        a = i >= 0 ? num1[i] - '0' : 0;
        b = j >= 0 ? num2[j] - '0' : 0;
        sum = a - b + carray;
        carray = 0;
        // 不夠减
        if(sum < 0){
            sum += 10;
            carray = -1;
        }//if
        result.insert(result.begin(),sum + '0');
        --i;
        --j;
    }
    // 删除前導0
    string::iterator it = result.begin();
    while(it != result.end() && *it == '0'){
        ++it;
    }
    result.erase(result.begin(),it);
    return positive ? result : "-"+result;
}
// big number add function
string NumberObject::AddString(string num1,string num2){
    int len1 = (int)num1.length();
    int len2 = (int)num2.length();
    // 容錯處理
    if(len1 <= 0){
        return num2;
    }
    if(len2 <= 0){
        return num1;
    }
    string result;
    int i = len1-1,j = len2-1;
    int a,b,sum,carry = 0;
    // 倒序相加
    while(i >= 0 || j >= 0 || carry > 0){
        a = i >= 0 ? num1[i] - '0' : 0;
        b = j >= 0 ? num2[j] - '0' : 0;
        // 按位相加並且加上進位
        sum = a + b + carry;
        // 進位
        carry = sum / 10;
        result.insert(result.begin(),sum % 10 + '0');
        --i;
        --j;
    }
    return result;
}


// 移位
string NumberObject::ShiftString(string num,int len){
    if(num == "0"){
        return num;
    }
    for(int i = 0;i < len;++i){
        num += "0";
    }
    return num;
}

// Karatsuba快速相乘算法
string NumberObject::KaratsubaMultiply(string num1, string num2) {
    int len = MakeSameLen(num1,num2);
    if(len == 0){
        return 0;
    }
    // all digit are one
    if(len == 1){
        return to_string((num1[0] - '0')*(num2[0] - '0'));
    }
    int mid = len / 2;
    // Find the first half and second half of first string.
    string x1 = num1.substr(0,mid);
    string x0 = num1.substr(mid,len - mid);
    // Find the first half and second half of second string
    string y1 = num2.substr(0,mid);
    string y0 = num2.substr(mid,len - mid);
    // Recursively computer
    string z0 = KaratsubaMultiply(x0,y0);
    string z1 = KaratsubaMultiply(AddString(x1,x0),AddString(y1,y0));
    string z2 = KaratsubaMultiply(x1,y1);
    // (z2*10^(2*m))+((z1-z2-z0)*10^(m))+(z0)
    // z2*10^(2*m)
    string r1 = ShiftString(z2,2*(len - mid));
    // (z1-z2-z0)*10^(m)
    string r2 = ShiftString(MinusString(MinusString(z1,z2),z0),len - mid);
    return  AddString(AddString(r1,r2),z0);
}

//大數比較
int NumberObject::compare(string a, string b){
    if(a.length()<b.length()) {
        return 0;
    } else if(a.length()==b.length()) {
        if(a<b) return 0;
    }return 1;
}

string* NumberObject::devide(string a, string b) {
    string *de = new string[2];
    de[0]="0"; de[1] = b;
    string one="1", ten="10";
    if(!compare(a,b)) return de;
    while(a[0]!='-') {
        de[1] = a;
        a = MinusString(a,b);
        de[0] = AddString(de[0],one);
    }
    de[0] = MinusString(de[0],one);
    return de;
}

