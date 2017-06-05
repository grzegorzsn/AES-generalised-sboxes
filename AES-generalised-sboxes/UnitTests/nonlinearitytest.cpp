#include "nonlinearitytest.h"

NonLinearityTest::NonLinearityTest()
{

}

void NonLinearityTest::computeTest1()
{
    GFNumber modulus = 0x11b;
    SBox sbox = SBox(modulus);
    NonLinearity nl = NonLinearity();
    nl.calucalate(sbox);
}
