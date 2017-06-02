#include "nonlinearitytest.h"

NonLinearityTest::NonLinearityTest()
{

}

void NonLinearityTest::computeTest1()
{
    GFNumber modulus = 0x11b;
    SBox sbox = SBox(modulus);
    NonLinearity2 nl = NonLinearity2();
    nl.calucalate(sbox);
}
