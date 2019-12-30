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
    QPushButton *back, *forward, *gooo;
    QTextEdit *input, *start, *finish, *number;
    QStringList string_list;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void quit()
    {
        close();
    }
    void output();
    void work();
    void next();
    void prev();
private:
    Ui::MainWindow *ui;


};
#endif // MAINWINDOW_H
