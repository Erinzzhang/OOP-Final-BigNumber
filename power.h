#ifndef Power_H
#define Power_H

#include "complex.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

NumberObject Power(string, string);

template <class T>
T Power(int, string);

template <class T>
T Power(float, string);
template <class T>
T Power(Integer, string);
template <class T>
T Power(Decimal, string);

Complex Power(Complex, string);

Complex PowerNegative(string, string);
Complex PowerNegative(int, string);
Complex PowerNegative(float, string);
Complex PowerNegative(Integer, string);
Complex PowerNegative(Decimal, string);

#endif
