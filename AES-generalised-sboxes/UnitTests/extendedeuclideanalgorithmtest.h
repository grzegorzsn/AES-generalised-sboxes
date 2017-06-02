#include <QString>
#include <QtTest>
#include <QCoreApplication>
#include "galoisfield.h"
#include "gfnumber.h"

class ExtendedEuclideanAlgorithmTest : public QObject
{
    Q_OBJECT

public:
    ExtendedEuclideanAlgorithmTest();

private Q_SLOTS:
    void computeTest1();
    void computeTest2();
};

