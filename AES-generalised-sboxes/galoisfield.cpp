#include "galoisfield.h"
#include "extendedeuclideanalgorithm.h"

GaloisField::GaloisField()
{
}

GaloisField::GaloisField(GFNumber modulus)
{
    this->modulus = modulus;
}

GFNumber GaloisField::multiply(GFNumber a, GFNumber b)
{
    GFNumber result = multiplyWithoutModulo(a, b);
    if( modulus.to_ullong() > 0) result = modulo(result, modulus);
    return result;
}

GFNumber GaloisField::divide(GFNumber a, GFNumber b)
{
    GFNumber result = GFNumber(0);
    while(degree(a) >= degree(b))
    {
        uint8_t diff = degree(a) - degree(b);
        GFNumber quotient = GFNumber(0);
        quotient.set(diff);
        result.set(diff);
        GFNumber product = multiplyWithoutModulo(quotient, b);
        a ^= product;
    }

    return result;
}

GFNumber GaloisField::modulo(GFNumber a, GFNumber b)
{
    GFNumber result = a;
    while(degree(result) >= degree(b))
    {
        uint8_t diff = degree(result) - degree(b);
        GFNumber quotient = GFNumber(0);
        quotient.set(diff);
        GFNumber product = multiplyWithoutModulo(quotient, b);
        result ^= product;
    }
    return result;
}

GFNumber GaloisField::multiplicativeInverse(GFNumber a)
{
    ExtendedEuclideanAlgorithm eea = ExtendedEuclideanAlgorithm(a, modulus);
    eea.compute();
    return eea.getS();
}

GFNumber GaloisField::getModulus()
{
    return modulus;
}

GFNumber GaloisField::multiplyWithoutModulo(GFNumber a, GFNumber b)
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

void GaloisField::setModulus(GFNumber value)
{
    modulus = value;
}

string GaloisField::display(GFNumber bits)
{
    stringstream result = stringstream();
    bool firstXReached = false;
    for(int i = 63; i >= 0; i--)
    {
        stringstream part = stringstream();
        if(i == 0) part << "1";
        else if(i == 1) part << "x";
        else part << "x^" << i ;
        if (bits[i])
        {
            if(!firstXReached)
            {
                result << part.str();
                firstXReached = true;
            }
            else
            {
                result << " + " << part.str();
            }
        }
    }
    return result.str();
}


int8_t GaloisField::degree(GFNumber bits)
{
    // The degree of the zero polynomial is either left undefined,
    // or is defined to be negative (usually −1 or −∞).
    // Let assume it is -1.
    if(bits == GFNumber(0)) return -1;
    for(int i = 63; i > 0; i--)
        if (bits[i])
            return i;
    return 0;
}
