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
        vector<GFNumber> irrPolynomials = irrPolGen->generate();
        QList<QStandardItem*> dataList;
        for(int i = 0; i < irrPolynomials.size(); i++)
        {
            QStandardItem *item = new QStandardItem(GaloisField::display(irrPolynomials[i]).c_str());
            dataList.append(item);
        }
        QStandardItemModel *stdModel = new QStandardItemModel(this);
        stdModel->appendColumn(dataList);
        ui->lstIrrPol->setModel(stdModel);

       // ui->lstIrrPol->show();
        //ui->lblDegree->setText("OH!");
    }
    catch (exception e)
    {
        cout << e.what() << endl;
    }

}
