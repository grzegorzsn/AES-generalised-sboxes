#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "nonlinearity.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lblNonLinearity->setText("");
    prepareSboxTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::prepareSboxTable()
{
    QStandardItemModel * tableModel = new QStandardItemModel(16,16,this);
    ui->tblSBox->setModel(tableModel);    for(int i = 0; i < 16; i++)
    {
         ui->tblSBox->setColumnWidth(i, 30);
         ui->tblSBox->setRowHeight(i, 20);
    }
    QStringList columnsLabels;
    QStringList rowsLabels;
    for(int i = 0; i < 16; i++)
    {
        stringstream ssCol = stringstream("");
        stringstream ssRow = stringstream("");
        ssCol << hex << i;
        ssRow << hex << i*16;
        columnsLabels << ssCol.str().c_str();
        rowsLabels << ssRow.str().c_str();
    }
    tableModel->setHorizontalHeaderLabels(columnsLabels);
}

void MainWindow::on_btnGenerate_clicked()
{
    try
    {
        QListWidget *listWidget =  ui->lstIrrPol;
        uint8_t degree = 8;
        GFIrrPolGenerator * irrPolGen = new GFIrrPolGenerator();
        irrPolGen->setMaxDegree(degree);
        vector<GFNumber> irrPolynomials = irrPolGen->generate();
        for(int i = 0; i < irrPolynomials.size(); i++)
        {
            if( GaloisField::degree(irrPolynomials[i]) == 8)
            {
                QListWidgetItem* newItem = new QListWidgetItem(tr(GaloisField::display(irrPolynomials[i]).c_str()), listWidget);
                int value =irrPolynomials[i].to_ulong();
                QVariant data(value);
                newItem->setData(32, data);
            }
        }

    }
    catch (exception e)
    {
        cout << e.what() << endl;
    }

}

void MainWindow::displaySBox(SBox sbox)
{
    QStandardItemModel * tableModel = (QStandardItemModel*)ui->tblSBox->model();
    vector<GFNumber> sboxTable = sbox.substitionTable();

    for(int i = 0; i < 16; i++) // rows
    {
        for(int j = 0; j < 16; j++) // columns
        {
            stringstream ss = stringstream("");
            ss << hex << sboxTable[i*16 + j].to_ulong();
            QModelIndex index
                    = tableModel->index(i,j,QModelIndex());
            tableModel->setData(index, ss.str().c_str());
        }
    }
}

void MainWindow::on_lstIrrPol_itemDoubleClicked(QListWidgetItem *item)
{
    GFNumber modulus = GFNumber(item->data(32).toInt());
    SBox sbox = SBox(modulus);
    displaySBox(sbox);
    NonLinearity nl = NonLinearity(sbox);
    string message = "Irreducible polynomial: \n";
    message += GaloisField::display(modulus) + "\n";
    message += "Non linearity of S-Box based on it: \n";
    ui->lblNonLinearity->setText(message.c_str());
    double result = nl.compute();
    message += "NL(S-Box) = " + to_string(result);
    ui->lblNonLinearity->setText(message.c_str());
}
