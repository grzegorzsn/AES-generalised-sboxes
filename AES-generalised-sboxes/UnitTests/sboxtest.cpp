#include "sboxtest.h"
#include <iostream>
using namespace std;

SBoxTest::SBoxTest()
{

}

void SBoxTest::substituteTest1()
{
    GFNumber expected = 0x63;
    GFNumber modulus = 0x11b;
    GFNumber a = GFNumber(0);
    SBox sbox = SBox(modulus);
    GFNumber result = sbox.substitute(a);
    QCOMPARE(result, expected);
}

void SBoxTest::substituteTest2()
{
    GFNumber expected = 0xfe;
    GFNumber modulus = 0x11b;
    GFNumber a = GFNumber(0x0c);
    SBox sbox = SBox(modulus);
    GFNumber result = sbox.substitute(a);
    QCOMPARE(result, expected);
}

void SBoxTest::substituteTest3()
{
    GFNumber expected = 0xdd;
    GFNumber modulus = 0x11b;
    GFNumber a = GFNumber(0xc9);
    SBox sbox = SBox(modulus);
    GFNumber result = sbox.substitute(a);
    QCOMPARE(result, expected);
}

void SBoxTest::substitutionTableTest()
{
    GFNumber modulus = 0x11b;
    SBox sbox = SBox(modulus);
    vector<GFNumber> table = sbox.substitionTable();
    vector<GFNumber>::size_type expectedSize = 256;
    QCOMPARE(table.size(), expectedSize);
    QCOMPARE(table[0], GFNumber(0x63));
    QCOMPARE(table[1], GFNumber(0x7c));
    QCOMPARE(table[254], GFNumber(0xbb));
    QCOMPARE(table[255], GFNumber(0x16));
}
