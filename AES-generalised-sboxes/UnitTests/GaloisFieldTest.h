#include <QString>
#include <QtTest>
#include <QCoreApplication>
#include "galoisfield.h"
#include "gfnumber.h"

class GaloisFieldTest : public QObject
{
    Q_OBJECT

public:
    GaloisFieldTest();

private Q_SLOTS:
    void dispayTest1();
    void dispayTest2();
    void multiplyTest();
    void divideTest1();
    void divideTest2();
    void moduloTest();
    void multiplicativeInverseTest();
    void degreeTest1();
    void degreeTest2();
};
