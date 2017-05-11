#include "NumberObject.h"
#include <string>
#include <vector>
using namespace std;

//a class for Decimal calculation
class Decimal: public NumberObject {
public:
	Decimal();
    Decimal preoperation(Decimal&, Decimal&);
    Decimal divide(string, string);

	Decimal& operator+=(const Decimal& object2) {
		return *this;
	}
	Decimal& operator-=(const Decimal& object2) {
		return *this;
	}
	Decimal& operator*=(const Decimal& object2) {
		return *this;
	}
	Decimal& operator/=(const Decimal& object2) {
		return *this;
	}

	friend Decimal operator+(const Decimal&, const Decimal&);
	friend Decimal operator-(const Decimal&, const Decimal&);
	friend Decimal operator*(const Decimal&, const Decimal&);
    friend Decimal operator/(const Decimal&, const Decimal&);

	friend istream &operator >> (istream&, Decimal&);	//cin needs to use istream
	friend ostream &operator << (ostream&, const Decimal&);	//cout overload needs ostream

    string beforePoint;  //beforePoint.afterPoint
	string afterPoint;
};
