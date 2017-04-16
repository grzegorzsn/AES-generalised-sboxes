#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gfirrpolgenerator.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnGenerate_clicked()
{
    try
    {
        uint8_t degree = ui->sbDegree->value();
        GFIrrPolGenerator * irrPolGen = new GFIrrPolGenerator();
        irrPolGen->setMaxDegree(degree);
        irrPolGen->generate();
        //ui->lblDegree->setText("OH!");
    }
    catch (exception e)
    {
        cout << e.what() << endl;
    }

}
