#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QTextEdit>
#include <QTextStream>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QPushButton *back, *forward;
    gooo = new QPushButton("gooo", this);
    gooo->setGeometry((QRect(QPoint(50, 10), QSize(60, 30))));

    clear = new QPushButton("clear", this);
    clear->deleteLater();
//    gooo->setEnabled(false);
//    gooo->deleteLater();
    back = new QPushButton("back", this);
    back->setGeometry(QRect(QPoint(10, 150),QSize(100, 30)));

    forward = new QPushButton("forward", this);
    forward->setGeometry(QRect(QPoint(130, 150),QSize(100, 30)));
//    QTextEdit *input, *start, *finish, *number;

    input = new QTextEdit("", this);
    input->setGeometry(QRect(QPoint(130, 10), QSize(100, 130)));

    number = new QTextEdit("num", this);
    number->setGeometry(QRect(QPoint(10, 10), QSize(30, 30)));
    number->setReadOnly(1);

    start = new QTextEdit("start", this);
    start->setGeometry(QRect(QPoint(10, 50), QSize(100, 40)));
    start->setReadOnly(1);

    finish = new QTextEdit("finish", this);
    finish->setGeometry(QRect(QPoint(10, 100), QSize(100, 40)));
    finish->setReadOnly(1);

    QObject::connect(forward, SIGNAL(clicked()), SLOT(next()));

    QObject::connect(back, SIGNAL(clicked()), SLOT(prev()));

    QObject::connect(gooo, SIGNAL(clicked()), SLOT(start_work()));

    QObject::connect(clear, SIGNAL(clicked()), SLOT(end_work()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::start_work()
{
    gooo->deleteLater();
    clear->setGeometry((QRect(QPoint(50, 10), QSize(60, 30))));
    string = this->input->toPlainText().trimmed();
    string_list = string.split('\n');
    counter = 1;
    start->setText(string_list[0]);
    finish->setText(string_list[1]);
    number->setText("1");
}

void MainWindow::end_work()
{
    clear->deleteLater();
    gooo->setGeometry((QRect(QPoint(50, 10), QSize(60, 30))));
    string_list.clear();
    start->setText("start");
    finish->setText("finish");
    number->setText("num");
}

void MainWindow::next()
{
    if(counter < ((string_list.size() + 1) / 2))
    {
        counter++;
        start->setText(string_list[(counter - 1) * 2]);
        finish->setText(string_list[(counter - 1) * 2 + 1]);
        string.setNum(counter);
        number->setText(string);
    }
}
void MainWindow::prev()
{
    if(counter > 1)
    {
        counter--;
        start->setText(string_list[(counter - 1) * 2]);
        finish->setText(string_list[(counter - 1) * 2 + 1]);
        string.setNum(counter);
        number->setText(string);
    }
}
