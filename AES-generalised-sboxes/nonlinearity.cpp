#include "nonlinearity.h"

NonLinearity::NonLinearity()
{
    approximation = vector<Coverage>();
    for(int i = 0; i < 8; i++)
    {
        Coverage f;
        f.coverage = 0;
        f.function = Function(0);
        approximation.push_back(f);
    }
}

int NonLinearity::calucalate(SBox sbox)
{
    if(!sboxCorrect(sbox)) throw invalid_argument("Only 8x8 S-Boxes are supported!");
    for(int i = 0; i < 8; i++) // for each bit in sbox output
    {
        cout << "#";
        for(int j = 0; j < 256; j++) // for every possible linear function
        {
            Function f = Function(i);
            int coverage = computeCoverage(sbox, i, f);
            if(coverage > approximation[i].coverage)
            {
                approximation[i].coverage = coverage;
                approximation[i].function = f;
            }

        }
    }
    int min = 257;
    int max = -1;
    for(int i = 0; i < 8; i++)
    {
        int a = approximation[i].coverage;
        int b = 256 - approximation[i].coverage;
        cout << "Coverage: " << approximation[i].coverage << endl;
        cout << "Coverage: " << 256 - approximation[i].coverage << endl;

    }
    return -1;
}


bool NonLinearity::sboxCorrect(SBox sbox)
{
    vector<GFNumber> sTable = sbox.substitionTable();
    if(sTable.size() != 256) return false;
    for(int i = 0; i < sTable.size(); i++)
        if(GaloisField::degree(sTable[i]) >= 8)
            return false;
    return true;
}

bool NonLinearity::computeFunction(Function f, GFNumber input)
{
    bitset<8> i = bitset<8>(input.to_ulong());
    i ^= f;
    if(i.count() % 2 == 1) return true;
    else return false;
}

int NonLinearity::computeCoverage(SBox sbox, uint8_t outputPosition, Function f)
{
    vector<GFNumber> sTable = sbox.substitionTable();
    int coverage = 0;
    for(int k = 0; k < 256; k++) // for every possible input value
    {
        if(computeFunction(f, GFNumber(k)) == sTable[k][outputPosition])
            coverage++;
    }
    return coverage;
}


