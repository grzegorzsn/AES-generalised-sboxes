#include <QString>
#include <QtTest>
#include <QCoreApplication>
#include "sbox.h"

using namespace std;

class SBoxTest : public QObject
{
    Q_OBJECT

public:
    SBoxTest();

private Q_SLOTS:
    void substituteTest1();
    void substituteTest2();
    void substituteTest3();
    void substitutionTableTest1();
    void substitutionTableTest2();
};

