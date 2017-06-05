#include "nonlinearity3.h"

NonLinearity3::NonLinearity3()
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

int NonLinearity3::calucalate(SBox sbox)
{
    if(!sboxCorrect(sbox)) throw invalid_argument("Only 8x8 S-Boxes are supported!");
    vector<Function>
}



