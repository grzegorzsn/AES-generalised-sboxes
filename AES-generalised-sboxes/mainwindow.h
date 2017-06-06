#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QListWidget>
#include <QMainWindow>
#include <QStandardItemModel>
#include <sstream>
#include "gfirrpolgenerator.h"
#include "extendedeuclideanalgorithm.h"
#include "sbox.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void displaySBox(SBox sbox);
    ~MainWindow();

private slots:
    void on_btnGenerate_clicked();
    void on_lstIrrPol_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    void prepareSboxTable();
};

#endif // MAINWINDOW_H
