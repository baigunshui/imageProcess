/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *showButton;
    QPushButton *cannyButton;
    QPushButton *morphingButton;
    QPushButton *faceDetection;
    QLabel *Label;
    QLineEdit *lineEdit_currentPath;
    QListWidget *listWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(729, 527);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(580, 50, 111, 321));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        showButton = new QPushButton(verticalLayoutWidget);
        showButton->setObjectName(QString::fromUtf8("showButton"));

        verticalLayout->addWidget(showButton);

        cannyButton = new QPushButton(verticalLayoutWidget);
        cannyButton->setObjectName(QString::fromUtf8("cannyButton"));

        verticalLayout->addWidget(cannyButton);

        morphingButton = new QPushButton(verticalLayoutWidget);
        morphingButton->setObjectName(QString::fromUtf8("morphingButton"));

        verticalLayout->addWidget(morphingButton);

        faceDetection = new QPushButton(verticalLayoutWidget);
        faceDetection->setObjectName(QString::fromUtf8("faceDetection"));

        verticalLayout->addWidget(faceDetection);

        Label = new QLabel(centralWidget);
        Label->setObjectName(QString::fromUtf8("Label"));
        Label->setGeometry(QRect(210, 50, 331, 311));
        lineEdit_currentPath = new QLineEdit(centralWidget);
        lineEdit_currentPath->setObjectName(QString::fromUtf8("lineEdit_currentPath"));
        lineEdit_currentPath->setGeometry(QRect(10, 50, 171, 20));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 90, 171, 281));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 729, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        showButton->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\345\233\276\347\211\207", nullptr));
        cannyButton->setText(QApplication::translate("MainWindow", "Canny", nullptr));
        morphingButton->setText(QApplication::translate("MainWindow", "\345\233\276\345\203\217\345\217\230\345\275\242", nullptr));
        faceDetection->setText(QApplication::translate("MainWindow", "\344\272\272\350\204\270\346\243\200\346\265\213", nullptr));
        Label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
