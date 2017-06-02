#include "sbox.h"

SBox::SBox()
{

}

SBox::SBox(GFNumber modulus)
{
    setModulus(modulus);
}

void SBox::setModulus(GFNumber value)
{
    modulus = value;
}

GFNumber SBox::substitute(GFNumber a)
{
    GFNumber inverted;
    if(a == GFNumber(0))
    {
        inverted = GFNumber(0);
    }
    else
    {
        GaloisField gf = GaloisField(modulus);
        inverted = gf.multiplicativeInverse(a);
    }
    GFNumber transformated = affineTransformation(inverted);
    return transformated ^ GFNumber(0x63);
}

std::vector<GFNumber> SBox::substitionTable()
{
    std::vector<GFNumber> result = std::vector<GFNumber>();
    for(int i = 0; i < 256; i++)
        result.push_back(substitute(GFNumber(i)));
    return result;
}

GFNumber SBox::trim(GFNumber a, int8_t degree)
{
    for(int i = degree; i < a.size(); i++)
        a.reset(i);
    return a;
}

uint8_t SBox::rotate(uint8_t x)
{
    return ((x) << (1) | ((x) >> (7)));
}



GFNumber SBox::affineTransformation(GFNumber s)
{
    if(GaloisField::degree(s) >= 8 )
    {
        string message = "Affine transformation operates only on polynomials with degree lower than 8.";
        throw std::invalid_argument(message);
    }
    uint8_t result = 0;
    uint8_t input = (uint8_t)s.to_ullong();
    for(int i = 0; i < 5; i++)
    {
        result ^= input;
        input = rotate(input);
    }
    return trim(GFNumber(result));
}
