#include "gfirrpolgenerator.h"
#include <math.h>
#include <iostream> // TODO: remove after devolpment.
#include <bitset>

GFIrrPolGenerator::GFIrrPolGenerator()
{

}

std::vector<GFNumber> GFIrrPolGenerator::generate()
{
    uint64_t limit = pow(2, maxDegree + 1);
    cout << "limit: " << limit;
    bool *isIrreducible = new bool[limit];
    for(int i = 0; i*i < limit; i++)
        isIrreducible[i] = true;
    isIrreducible[0] = false;
    isIrreducible[1] = false;
    for(int i = 0; i < limit; i++)
    {
        if(isIrreducible[i])
        {
            for(int j = i; j < limit; j++)
            {

                GFNumber reducible = gf.Multiply(GFNumber(i),GFNumber(j));
                isIrreducible[reducible.to_ullong()] = false;
            }
        }
    }

    std::vector<GFNumber>result = std::vector<GFNumber>();
    for(int i = 0; i < limit; i++)
        if(isIrreducible[i]) result.push_back(GFNumber(i));

    for(int i = 0; i < result.size(); i++)
        std::cout << gf.display(result[i]) << std::endl;

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
