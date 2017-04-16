#include "galoisfield.h"

GaloisField::GaloisField()
{
}

GFNumber GaloisField::Multiply(GFNumber a, GFNumber b)
{
    if(degree(a) + degree(b) > 63) throw std::invalid_argument("Too big degrees to compute.");
    std::bitset<64> result = std::bitset<64>();
    result.reset();
    for(int i = 63; i >= 0; i--)
        for(int j = 63; j >= 0; j--)
            if(a[i] && b[j])
                result.flip(i+j);
    return GFNumber(result.to_ullong());
}

GFNumber GaloisField::getModulus()
{
    return modulus;
}

void GaloisField::setModulus(GFNumber value)
{
    modulus = value;
}

string GaloisField::display(GFNumber bits)
{
    stringstream ss = stringstream();
    bool firstXReached = false;
    for(int i = 63; i >= 0; i--)
        if (bits[i])
        {
            if(!firstXReached)
            {
                ss << "x^" << i;
                firstXReached = true;
            }
            else
            {
                ss << " + x^" << i;
            }
        }
    return ss.str();
}

uint8_t GaloisField::degree(GFNumber bits)
{
    for(int i = 63; i > 0; i--)
        if (bits[i])
            return i;
    return 0;
}
