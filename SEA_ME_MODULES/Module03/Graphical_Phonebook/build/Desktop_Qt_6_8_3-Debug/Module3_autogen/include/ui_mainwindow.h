/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *nameInput;
    QLabel *label_2;
    QLineEdit *phoneInput;
    QLabel *label_3;
    QLineEdit *emailInput;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QPushButton *addButton;
    QPushButton *removeButton;
    QPushButton *searchButton;
    QPushButton *saveButton;
    QPushButton *loadButton;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QListWidget *contactList;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(458, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 20, 341, 171));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        nameInput = new QLineEdit(widget);
        nameInput->setObjectName("nameInput");

        gridLayout->addWidget(nameInput, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        phoneInput = new QLineEdit(widget);
        phoneInput->setObjectName("phoneInput");

        gridLayout->addWidget(phoneInput, 1, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        emailInput = new QLineEdit(widget);
        emailInput->setObjectName("emailInput");

        gridLayout->addWidget(emailInput, 2, 1, 1, 1);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(360, 10, 82, 191));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        addButton = new QPushButton(widget1);
        addButton->setObjectName("addButton");

        verticalLayout->addWidget(addButton);

        removeButton = new QPushButton(widget1);
        removeButton->setObjectName("removeButton");

        verticalLayout->addWidget(removeButton);

        searchButton = new QPushButton(widget1);
        searchButton->setObjectName("searchButton");

        verticalLayout->addWidget(searchButton);

        saveButton = new QPushButton(widget1);
        saveButton->setObjectName("saveButton");

        verticalLayout->addWidget(saveButton);

        loadButton = new QPushButton(widget1);
        loadButton->setObjectName("loadButton");

        verticalLayout->addWidget(loadButton);

        widget2 = new QWidget(centralwidget);
        widget2->setObjectName("widget2");
        widget2->setGeometry(QRect(10, 210, 431, 351));
        verticalLayout_2 = new QVBoxLayout(widget2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget2);
        label_4->setObjectName("label_4");

        verticalLayout_2->addWidget(label_4);

        contactList = new QListWidget(widget2);
        contactList->setObjectName("contactList");

        verticalLayout_2->addWidget(contactList);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 458, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Name :", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Phone Number :", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "E-mail :", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        removeButton->setText(QCoreApplication::translate("MainWindow", "remove", nullptr));
        searchButton->setText(QCoreApplication::translate("MainWindow", "search", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "save", nullptr));
        loadButton->setText(QCoreApplication::translate("MainWindow", "load", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Contact List : ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
