/********************************************************************************
** Form generated from reading UI file 'Qt.ui'
**
** Created by: Qt User Interface Compiler version 5.15.19
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_H
#define UI_QT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *okButton;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(506, 341);
        MainWindow->setMinimumSize(QSize(506, 341));
        MainWindow->setMaximumSize(QSize(506, 341));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 30, 271, 71));
        label->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label->setScaledContents(true);
        okButton = new QPushButton(centralwidget);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(190, 240, 121, 71));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(130, 110, 281, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(130, 140, 281, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(130, 170, 941, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(130, 200, 281, 16));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "IconPlaceholder", nullptr));
        okButton->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Name: PRETTY_NAME GNU/Linux", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Kernel: KernelInfo", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Documentation: DOCUMENTATION_URL", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "License: link GPLV3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_H
