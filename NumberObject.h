#include <vector>
#include <string>
using namespace std;

class NumberObject {
public:
//    NumberObject(int);
//    NumberObject(string);
//    NumberObject(float);
    
	vector<int> add(vector<int>, vector<int>, bool);    //bool is true if is calculating decimal numbers after the point
	vector<int> sub(vector<int>, vector<int>);
    int MakeSameLen(string&,string&);
    string MinusString(string, string);
    string AddString(string,string);
    string ShiftString(string,int);
    string KaratsubaMultiply(string, string);
    int compare(string, string);
    bool compareValue(string, string);
    
    friend ostream &operator << (ostream&, const NumberObject&);	//cout overload needs ostream
    
    string imag;
    string real;
    int type; //0: Integer, 1: Decimal, 2: Complex
};

//NumberObject Power(string, string);
//NumberObject Power(float, float);
NumberObject Power(NumberObject, int);
NumberObject Power(NumberObject, float);
