#include "galoisfield.h"

GaloisField::GaloisField()
{
}

GFNumber GaloisField::multiply(GFNumber a, GFNumber b)
{
    GFNumber result = multiplyWithoutModulo(a, b);
    if( modulus.to_ullong() > 0) result = findModulo(result);
    return result;
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

GFNumber GaloisField::findModulo(GFNumber a)
{
    // TODO: remove those output.
    //cout << "findModulo: " << endl;
    //cout << "a: " << display(a) << endl;
    //cout << "mod: " << display(modulus) << endl;
    GFNumber result = a;
    while(degree(result) >= degree(modulus))
    {
        uint8_t diff = degree(result) - degree(modulus);
        GFNumber quotient = GFNumber(0);
        quotient.set(diff);
        //cout << "quotient: " << display(quotient) << endl;
        GFNumber product = multiplyWithoutModulo(quotient, modulus);
        //cout << "product: " << display(product) << endl;
        result ^= product;
        //cout << "result: " << display(result) << endl;

    }
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

uint8_t GaloisField::degree(GFNumber bits)
{
    for(int i = 63; i > 0; i--)
        if (bits[i])
            return i;
    return 0;
}
