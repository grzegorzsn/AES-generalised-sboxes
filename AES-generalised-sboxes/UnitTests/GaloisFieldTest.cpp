#include <QString>
#include <QCoreApplication>
#include "galoisfieldtest.h"

using namespace std;

GaloisFieldTest::GaloisFieldTest()
{
}

void GaloisFieldTest::dispayTest1()
{
    string expected = "x^2 + 1";
    GFNumber gfNumber = GFNumber(5);
    string result = GaloisField::display(gfNumber);
    QCOMPARE(result, expected);
}

void GaloisFieldTest::dispayTest2()
{
    string expected = "x^8 + x^4 + x^3 + x + 1";
    GFNumber gfNumber = GFNumber(0x11b);
    string result = GaloisField::display(gfNumber);
    QCOMPARE(result, expected);
}

void GaloisFieldTest::multiplyTest()
{
    GFNumber expected = GFNumber(0xc1);
    GFNumber a = GFNumber(0x57);
    GFNumber b = GFNumber(0x83);
    GaloisField gf = GaloisField(0x11b);
    GFNumber result = gf.multiply(a,b);
    QCOMPARE(result, expected);
}

// (x^10 + x^9 + x^8 + x^6 + x^5 + x^4 + 1) div (x^9 + x^6 + x^5 + x^3 + x^2 + 1) = (x + 1)
// 771 div 26D = 3
void GaloisFieldTest::divideTest1()
{
    GFNumber expected = GFNumber(0x3);
    GFNumber a = GFNumber(0x771);
    GFNumber b = GFNumber(0x26d);
    GaloisField gf = GaloisField();
    GFNumber result = gf.divide(a,b);
    QCOMPARE(expected, result);
}

// (x^8 + x^7 + x^6 + x^2 + 1) div (x^5 + x^2 + x + 1) = (x^3 + x^2 + x + 1)
// 1C5 div 27 = 15
void GaloisFieldTest::divideTest2()
{
    GFNumber expected = GFNumber(0xF);
    GFNumber a = GFNumber(0x1c5);
    GFNumber b = GFNumber(0x27);
    GaloisField gf = GaloisField();
    GFNumber result = gf.divide(a,b);
    QCOMPARE(expected, result);
}

// (x^13 + x^11 + x^9 + x^8 + x^6 + x^5 + x^4 + x^3 + 1) mod (x^8 + x^4 + x^3 + x + 1) = (x^7 + x^6 + 1)
// 2B79 mod 11B = C1
void GaloisFieldTest::moduloTest()
{
    GFNumber expected = GFNumber(0xc1);
    GFNumber a = GFNumber(0x2b79);
    GFNumber b = GFNumber(0x11b);
    GaloisField gf = GaloisField();
    GFNumber result = gf.modulo(a,b);
    QCOMPARE(expected, result);
}

// 0xca * 0x5 = 1
void GaloisFieldTest::multiplicativeInverseTest()
{
    GFNumber expected = GFNumber(0xca);
    GFNumber a = GFNumber(0x53);
    GaloisField gf = GaloisField(0x11b);
    GFNumber result = gf.multiplicativeInverse(a);
    QCOMPARE(result, expected);
}

void GaloisFieldTest::degreeTest1()
{
    int expected = -1;
    GFNumber a = GFNumber(0);
    GaloisField gf = GaloisField();
    int result = gf.degree(a);
    QCOMPARE(result, expected);
}

void GaloisFieldTest::degreeTest2()
{
    int expected = 13;
    GFNumber a = GFNumber(0x2A79);
    GaloisField gf = GaloisField();
    int result = gf.degree(a);
    QCOMPARE(result, expected);
}

