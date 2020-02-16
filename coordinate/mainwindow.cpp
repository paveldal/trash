#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QTextEdit>
#include <QTextStream>
#include <QClipboard>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QPushButton *back, *forward;
    gooo = new QPushButton("gooo", this);
    gooo->setGeometry((QRect(QPoint(50, 10), QSize(80, 30))));

    clear = new QPushButton("clear", this);
    clear->setGeometry((QRect(QPoint(50, 10), QSize(80, 30))));
    clear->setVisible(false);
//    gooo->setEnabled(false);
//    gooo->deleteLater();
    back = new QPushButton("back", this);
    back->setGeometry(QRect(QPoint(10, 150),QSize(120, 30)));

    forward = new QPushButton("forward", this);
    forward->setGeometry(QRect(QPoint(130, 150),QSize(100, 30)));
//    QTextEdit *input, *start, *finish, *number;

    input = new QTextEdit("", this);
    input->setGeometry(QRect(QPoint(130, 10), QSize(100, 130)));

    number = new QTextEdit("num", this);
    number->setGeometry(QRect(QPoint(10, 10), QSize(30, 30)));
    number->setReadOnly(1);

//    start = new QTextBrowser;
    start = new QPushButton("start", this);
    start->setGeometry(QRect(QPoint(10, 50), QSize(120, 40)));
    start->setStyleSheet("background-color: rgb(164,194,244); color: rgb(0, 0, 0)");


//    finish = new QTextBrowser;
    finish = new QPushButton("finish", this);
    finish->setGeometry(QRect(QPoint(10, 100), QSize(120, 40)));
    finish->setStyleSheet("background-color: rgb(246,178,107); color: rgb(0, 0, 0)");

    QObject::connect(forward, SIGNAL(clicked()), SLOT(next()));

    QObject::connect(back, SIGNAL(clicked()), SLOT(prev()));

    QObject::connect(gooo, SIGNAL(clicked()), SLOT(start_work()));

    QObject::connect(clear, SIGNAL(clicked()), SLOT(end_work()));

    QObject::connect(start, SIGNAL(clicked()), SLOT(copy_st()));

    QObject::connect(finish, SIGNAL(clicked()), SLOT(copy_en()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::start_work()
{
    counter = -1;
    string = this->input->toPlainText().trimmed();
    string_list = string.split('\n');
    if(string_list.size() / 2 * 2 == string_list.size())
    {
        gooo->setVisible(false);
        clear->setVisible(true);
        counter = 1;
        start->setText(string_list[0]);
        finish->setText(string_list[1]);
        number->setText("1");
        input->setReadOnly(1);
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Enter the correct data");
        msgBox.exec();
        string_list.clear();
        input->setText("");
    }
}

void MainWindow::end_work()
{
    QMessageBox msgBox;
    msgBox.setText("Are you sure?");
    msgBox.setStandardButtons(QMessageBox::No | QMessageBox::Yes);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();
    switch (ret) {
    case QMessageBox::No:
        break;
    case QMessageBox::Yes:
        clear->setVisible(false);
        gooo->setVisible(true);
        string_list.clear();
        start->setText("start");
        finish->setText("finish");
        number->setText("num");
        input->setReadOnly(0);
        input->setText("");
        counter = -1;
        break;
    default:
        break;
    }
}

void MainWindow::next()
{   if(!string_list.isEmpty())
        if(counter < ((string_list.size() + 1) / 2)
        && counter != -1)
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
    if(!string_list.isEmpty())
        if(counter > 1)
        {
            counter--;
            start->setText(string_list[(counter - 1) * 2]);
            finish->setText(string_list[(counter - 1) * 2 + 1]);
            string.setNum(counter);
            number->setText(string);
        }
}

void MainWindow::copy_st()
{
     QClipboard *clipboard = QGuiApplication::clipboard();
     if(!string_list.isEmpty()
     && counter != -1)
        clipboard->setText(string_list[((counter - 1) * 2)]);
}

void MainWindow::copy_en()
{
     QClipboard *clipboard = QGuiApplication::clipboard();
     if(!string_list.isEmpty()
     && counter != -1)
        clipboard->setText(string_list[((counter - 1) * 2 + 1)]);
}

void MainWindow::quit()
{
    close();
}
