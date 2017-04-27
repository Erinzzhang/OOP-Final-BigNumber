#include "decimal.h"
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

//decimal constructor function
Decimal::Decimal(){
    
}

//overload + operator
Decimal operator+(const Decimal& d1, const Decimal& d2) {
	Decimal result;
    
	//add numbers after the point
	result.afterPoint = result.add(d1.afterPoint, d2.afterPoint, true);
	//add numbers before the point
	result.beforePoint = result.add(d1.beforePoint, d2.beforePoint, false);

	//check if there is a carrier from the afterpoint addition
	if(result.afterPoint.size() > d1.afterPoint.size()) {
		int carry = result.afterPoint[0];
		result.afterPoint.erase(result.afterPoint.begin());
		//add the carrier to d1 beforPoint vector
		vector<int> carrV(result.beforePoint.size() - 1);
		carrV.push_back(carry);
		result.afterPoint = result.add(result.afterPoint, carrV, false);
	}
    
    return result;
}

Decimal operator-(const Decimal& d1, const Decimal& d2) {
    Decimal lhs = d1, rhs = d2, result;
    
    //set both vector to the same length
    double gapSize = lhs.beforePoint.size() - rhs.beforePoint.size();
    if(gapSize > 0.0) {
        rhs.beforePoint.insert(rhs.beforePoint.begin(), (int)abs(gapSize), 0);
    }
    if (gapSize < 0.0) {
        lhs.beforePoint.insert(lhs.beforePoint.begin(), (int)abs(gapSize), 0);
    }
    
    gapSize = lhs.afterPoint.size() - rhs.afterPoint.size();
    if(gapSize > 0.0){
        for(int i = 0; i < gapSize; i++){
            rhs.afterPoint.push_back(0);
        }
    }
    if (gapSize < 0.0){
        for(int i = 0; i < gapSize; i++){
            lhs.afterPoint.push_back(0);
        }
    }
    for(int i = 0; i < rhs.afterPoint.size(); i++){
        cout << rhs.afterPoint[i];
    }
    cout << endl;
    
    vector<int> l, r, subRes;
    l.reserve(lhs.beforePoint.size() + lhs.afterPoint.size());
    r.reserve(rhs.beforePoint.size() + rhs.afterPoint.size());
    l.insert(l.end(), lhs.beforePoint.begin(), lhs.beforePoint.end());
    l.insert(l.end(), lhs.afterPoint.begin(), lhs.afterPoint.end());
    r.insert(r.end(), rhs.beforePoint.begin(), rhs.beforePoint.end());
    r.insert(r.end(), rhs.afterPoint.begin(), rhs.afterPoint.end());
    for(int i = 0; i < l.size(); i++){
        cout << l[i];
    }
    cout << endl;
    for(int i = 0; i < r.size(); i++){
        cout << r[i];
    }
    cout << endl;
    
    subRes = result.sub(l, r);
    for(int i = 0; i < subRes.size(); i++){
    cout << subRes[i];
    }
    cout << endl;
    return result;
}


Decimal operator*(const Decimal&, const Decimal&);


Decimal operator/(const Decimal&, const Decimal&);

istream &operator >> (istream& input, Decimal& d) {
    string s;
    stringstream ss;
    char splitChar;
    input >> s;
    ss << s;
    ss >> splitChar;
    //input to decimal class
    while(splitChar != '.'){
        d.beforePoint.push_back((int)splitChar - 48);
        ss >> splitChar;
    }
    while(ss >> splitChar){
        d.afterPoint.push_back((int)splitChar - 48);
    }
    
    return input;
}

ostream &operator << (ostream& output, const Decimal& d) {
    //print numbers before point
    for(int i = 0; i < d.beforePoint.size(); i++) {
        output << d.beforePoint[i];
    }
	output << ".";
    //print numbers after point
    for(int i = 0; i < d.afterPoint.size(); i++) {
        output << d.afterPoint[i];
    }
    cout << endl;
    
	return output;
}
