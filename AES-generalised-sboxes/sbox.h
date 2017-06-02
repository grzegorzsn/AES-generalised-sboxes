#ifndef SBOX_H
#define SBOX_H

#include "galoisfield.h"
#include <vector>

class SBox
{
public:
    SBox();
    SBox(GFNumber modulus);
    void setModulus(GFNumber modulus);
    GFNumber substitute(GFNumber a);
    std::vector<GFNumber> substitionTable();
private:
    GFNumber modulus;
    GFNumber trim(GFNumber a, int8_t degree = 8);
    uint8_t rotate(uint8_t a);
    GFNumber affineTransformation(GFNumber a);
};

#endif // SBOX_H
