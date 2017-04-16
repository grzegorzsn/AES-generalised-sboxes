#include "gfield.h"
#include "gfnumber.h"

GField::GField()
{

}

GFNumber GField::Multiply(GFNumber a, GFNumber b)
{
    if(a.getDegree() + b.getDegree() > 63) throw std::invalid_argument("Too big degrees to compute.");
    std::bitset<64> aBits = a.getBits();
    std::bitset<64> bBits = b.getBits();
    std::bitset<64> result = std::bitset<64>();
    result.reset();
    for(int i = 63; i >= 0; i--)
        for(int j = 63; j >= 0; j--)
            if(aBits[i] && bBits[j])
                result.flip(i+j);
    return GFNumber(result.to_ullong());
}

GFNumber *GField::getModulusCopy()
{
    return modulus->getCopy();
}

void GField::setModulusCopy(GFNumber *value)
{
    modulus = new GFNumber(value->getBits());
}
