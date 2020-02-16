#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    int counter;
    QString string;
    QPushButton *back, *forward, *gooo, *clear, *start, *finish;
    QTextEdit *input, *number;
    QStringList string_list;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void quit();
    void next();
    void prev();
    void start_work();
    void end_work();
    void copy_st();
    void copy_en();
private:
    Ui::MainWindow *ui;


};
#endif // MAINWINDOW_H
