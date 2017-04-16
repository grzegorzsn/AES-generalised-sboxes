#include "galoisfield.h"

GaloisField::GaloisField()
{
}

GFNumber GaloisField::multiply(GFNumber a, GFNumber b)
{
    GFNumber result = multiplyWithoutModulus(a, b);
    if( modulus.to_ullong() > 0) result = findModulo(result);
    return result;
}

GFNumber GaloisField::getModulus()
{
    return modulus;
}

GFNumber GaloisField::multiplyWithoutModulus(GFNumber a, GFNumber b)
{
    if(degree(a) + degree(b) > BITSET_LEN) throw std::invalid_argument("Too big degrees to compute.");
    GFNumber result = GFNumber();
    result.reset();
    for(int i = degree(a); i >= 0; i--)
        for(int j = degree(b); j >= 0; j--)
            if(a[i] && b[j])
                result.flip(i+j);
    return result;
}

GFNumber GaloisField::findModulo(GFNumber a)
{
    GFNumber result;
    // TODO: fill with implementation :)
    return result;
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
