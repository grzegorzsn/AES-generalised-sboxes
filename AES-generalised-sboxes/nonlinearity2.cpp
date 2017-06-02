#include "nonlinearity2.h"

NonLinearity2::NonLinearity2()
{

}

int NonLinearity2::calucalate(SBox sbox)
{
    uint8_t max = 0;
    uint8_t min = 255;
    //uint8_t linearApproximationTable[256][256];
    for(int i = 0; i < 256; i++)
    {
        for(int j = 0; j < 256; j++)
        {
            bitset<8> output = bitset<8>(sbox.substitute(i).to_ulong());
            bitset<8> counter = output^bitset<8>(j);
            //linearApproximationTable[i][j] = counter.count();
            uint8_t value = counter.count();//linearApproximationTable[i][j];
            if(value > max) max = value;
            if(value < min) min = value;
        }
    }

    cout << "Min: " << int(min) << endl;
    cout << "Max: " << int(max) << endl;
    return max;
}
