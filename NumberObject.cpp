#include "NumberObject.h"
#include <iostream>
#include <cmath>
using namespace std;

vector<int> NumberObject::add(vector<int> num1, vector<int> num2, bool isDecimalAfterPoint) {
	vector<int> result;		//a vector to sort results
	int ten = 0;
    
    //set both vector to the same length
    double gapSize = num1.size() - num2.size();
    if(gapSize > 0.0){
        if(isDecimalAfterPoint) num2.insert(num2.end() + 1, (int)abs(gapSize), 0);
        else num2.insert(num2.begin(), (int)abs(gapSize), 0);
    }
    if (gapSize < 0.0){
        if(isDecimalAfterPoint) num1.insert(num1.end() + 1, (int)abs(gapSize), 0);
        else num1.insert(num1.begin(), (int)abs(gapSize), 0);
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

vector<int> NumberObject::sub(vector<int> num1, vector<int> num2, bool isDecimalAfterPoint) {
	vector<int> result;
	int ten = 0;	//ten is whether the previous calculation had minus off one from the next tens

    //set both vector to the same length
    double gapSize = num1.size() - num2.size();
    if(gapSize > 0.0){
        if(isDecimalAfterPoint) num2.insert(num2.end(), (int)abs(gapSize), 0);
        else num2.insert(num2.begin(), (int)abs(gapSize), 0);
    }
    if (gapSize < 0.0){
        if(isDecimalAfterPoint) num1.insert(num1.end(), (int)abs(gapSize), 0);
        else num1.insert(num1.begin(), (int)abs(gapSize), 0);
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
