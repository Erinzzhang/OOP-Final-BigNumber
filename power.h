#ifndef Power_H
#define Power_H

#include "complex.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

//NumberObject Power(string, int);

NumberObject Power(int, int);
NumberObject Power(int, float);
NumberObject Power(float, int);
NumberObject Power(float, float);
NumberObject Power(Integer, int);
NumberObject Power(Integer, float);
NumberObject Power(Decimal, int);
NumberObject Power(Decimal, float);

void Power(Complex, int);
void Power(Complex, float);

#endif
