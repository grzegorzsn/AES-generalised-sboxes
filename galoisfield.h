#ifndef GFIELD_H
#define GFIELD_H
#include <bitset>
#include <sstream>
#include <iostream>
using namespace std;

const uint8_t BITSET_LEN = 64;
typedef bitset<BITSET_LEN> GFNumber;

class GaloisField
{
public:
    GaloisField();
    bool inField(GFNumber a);
    GFNumber multiply(GFNumber a, GFNumber b);
    string display(GFNumber bits);
    uint8_t degree(GFNumber bits);
    GFNumber getModulus();
    void setModulus(GFNumber value);

protected:
    GFNumber multiplyWithoutModulus(GFNumber a, GFNumber b);
    GFNumber findModulo(GFNumber a);
    GFNumber modulus;
};

#endif // GFIELD_H
