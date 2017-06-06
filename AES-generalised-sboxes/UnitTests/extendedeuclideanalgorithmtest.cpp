#include <QString>
#include <QCoreApplication>
#include "extendedeuclideanalgorithmtest.h"
#include "extendedeuclideanalgorithm.h"

ExtendedEuclideanAlgorithmTest::ExtendedEuclideanAlgorithmTest()
{

}

// INPUT:
// g(x) =  (x^10 + x^9 + x^8 + x^6 + x^5 + x^4 + 1) -> 0x771
// h(x) = (x^9 + x^6 + x^5 + x^3 + x^2 + 1) -> 0x26d
// RESULT:
// d(x) = gcd(g(x), h(x)) = x^3 + x + 1 -> 0xB
// s(x) = (x^4) -> 0x10
// t(x) = (x^5 + x^4 + x^3 + x^2 + x + 1) -> 0x3F
// EQUATION:
// (x^4)g(x) + (x^5 + x^4 + x^3 + x^2 + x + 1)h(x) = x^3 + x + 1.
void ExtendedEuclideanAlgorithmTest::computeTest1()
{
    GFNumber expectedD = GFNumber(0xB);
    GFNumber expectedS = GFNumber(0x10);
    GFNumber expectedT = GFNumber(0x3f);
    GFNumber g = GFNumber(0x771);
    GFNumber h = GFNumber(0x26d);
    ExtendedEuclideanAlgorithm eea = ExtendedEuclideanAlgorithm(g, h);
    eea.compute();
    QCOMPARE(eea.getD(), expectedD);
    QCOMPARE(eea.getS(), expectedS);
    QCOMPARE(eea.getT(), expectedT);
}

void ExtendedEuclideanAlgorithmTest::computeTest2()
{

}
