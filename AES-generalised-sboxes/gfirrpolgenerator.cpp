#include "gfirrpolgenerator.h"
#include <math.h>
#include <bitset>

GFIrrPolGenerator::GFIrrPolGenerator()
{

}

std::vector<GFNumber> GFIrrPolGenerator::generate()
{
    uint64_t limit = pow(2, maxDegree + 1);
    bool *isIrreducible = new bool[limit];
    for(int i = 0; i < limit; i++)
        isIrreducible[i] = true;
    isIrreducible[0] = false;
    isIrreducible[1] = false;

    for(int i = 0; gf.degree(GFNumber(i)) <= maxDegree; i++)
    {
        if(isIrreducible[i])
        {
            for(int j = i; gf.degree(GFNumber(i)) + gf.degree(GFNumber(j)) <= maxDegree; j++)
            {
                GFNumber reducible = gf.multiply(GFNumber(i),GFNumber(j));
                isIrreducible[reducible.to_ullong()] = false;
            }
        }
    }

    std::vector<GFNumber>result = std::vector<GFNumber>();
    for(int i = 0; i < limit; i++)
        if(isIrreducible[i]) result.push_back(GFNumber(i));


    delete [] isIrreducible;
    return result;
}

uint8_t GFIrrPolGenerator::getMaxDegree() const
{
    return maxDegree;
}

void GFIrrPolGenerator::setMaxDegree(const uint8_t &value)
{
    maxDegree = value;
}
