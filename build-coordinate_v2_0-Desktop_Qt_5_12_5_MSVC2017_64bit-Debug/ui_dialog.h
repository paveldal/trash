/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(800, 600);
        menubar = new QMenuBar(Dialog);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        Dialog->setMenuBar(menubar);
        centralwidget = new QWidget(Dialog);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Dialog->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Dialog);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Dialog->setStatusBar(statusbar);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QMainWindow *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
