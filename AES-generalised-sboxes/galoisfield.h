#ifndef GFIELD_H
#define GFIELD_H
#include <sstream>
#include <iostream>
#include "gfnumber.h"
using namespace std;

//class ExtendedEuclideanAlgorithm; // eea pointer needed to compute multiplicative inverse.

class GaloisField
{
public:
    GaloisField();
    GaloisField(GFNumber modulus);
    bool inField(GFNumber a);
    GFNumber multiply(GFNumber a, GFNumber b);
    GFNumber divide(GFNumber a, GFNumber b);
    GFNumber modulo(GFNumber a, GFNumber b);
    GFNumber multiplicativeInverse(GFNumber a);
    static string display(GFNumber bits);
    int8_t degree(GFNumber bits);
    GFNumber getModulus();
    void setModulus(GFNumber value);

protected:
    GFNumber multiplyWithoutModulo(GFNumber a, GFNumber b);
    GFNumber modulus;
};

#endif // GFIELD_H
