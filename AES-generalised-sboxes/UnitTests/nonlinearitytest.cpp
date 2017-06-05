#include "nonlinearitytest.h"

NonLinearityTest::NonLinearityTest()
{

}

void NonLinearityTest::computeTest1()
{
    double expected = 112.0;
    GFNumber modulus = 0x11b;
    SBox sbox = SBox(modulus);
    NonLinearity nl = NonLinearity(sbox);
    double result = nl.compute();
    QCOMPARE(result, expected);
}
