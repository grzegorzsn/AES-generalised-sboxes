#include <QString>
#include <QtTest>
#include <QCoreApplication>
#include "nonlinearity.h"
#include "nonlinearity2.h"

using namespace std;

class NonLinearityTest : public QObject
{
    Q_OBJECT

public:
    NonLinearityTest();

private Q_SLOTS:
    void computeTest1();

};


