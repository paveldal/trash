#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include "form.h"
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    int count = QInputDialog::getInt(this, tr("helo"), tr("world"), 0, 100);
    Form ban[100];

    ui->setupUi(this);
    for(auto i = 0; i < count; i++)
        ban[i].;
        ban[i].show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

