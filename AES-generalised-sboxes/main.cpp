#include "mainwindow.h"
#include <QApplication>
#include <QTest>
#include "UnitTests/galoisfieldtest.h"
#include "UnitTests/extendedeuclideanalgorithmtest.h"
#include "UnitTests/sboxtest.h"
#include "UnitTests/nonlinearitytest.h"

void executeTests()
{
    GaloisFieldTest gfTest;
    ExtendedEuclideanAlgorithmTest eeaTest;
    SBoxTest sboxTest;
    NonLinearityTest nlTest;
    QTest::qExec(&gfTest);
    QTest::qExec(&eeaTest);
    QTest::qExec(&sboxTest);
    QTest::qExec(&nlTest);
}


int main(int argc, char *argv[])
{
    executeTests();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

