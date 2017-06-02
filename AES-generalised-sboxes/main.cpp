#include "mainwindow.h"
#include <QApplication>
#include <QTest>
#include "UnitTests/galoisfieldtest.h"
#include <UnitTests/extendedeuclideanalgorithmtest.h>

void executeTests()
{
    GaloisFieldTest gfTest;
    ExtendedEuclideanAlgorithmTest eeaTest;
    QTest::qExec(&gfTest);
    QTest::qExec(&eeaTest);
}


int main(int argc, char *argv[])
{
    executeTests();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

