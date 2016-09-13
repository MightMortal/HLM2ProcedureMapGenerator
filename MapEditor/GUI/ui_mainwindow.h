/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QListView *descriptorsListView;
    QHBoxLayout *horizontalLayout;
    QPushButton *loadButton;
    QPushButton *saveButton;
    QGraphicsView *graphicsView;
    QTableWidget *propertyEditWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(820, 501);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetNoConstraint);
        descriptorsListView = new QListView(centralWidget);
        descriptorsListView->setObjectName(QStringLiteral("descriptorsListView"));
        descriptorsListView->setAlternatingRowColors(true);
        descriptorsListView->setResizeMode(QListView::Adjust);
        descriptorsListView->setModelColumn(0);

        gridLayout->addWidget(descriptorsListView, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        loadButton = new QPushButton(centralWidget);
        loadButton->setObjectName(QStringLiteral("loadButton"));

        horizontalLayout->addWidget(loadButton);

        saveButton = new QPushButton(centralWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        horizontalLayout->addWidget(saveButton);


        gridLayout->addLayout(horizontalLayout, 2, 1, 1, 1);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 0, 3, 1);

        propertyEditWidget = new QTableWidget(centralWidget);
        if (propertyEditWidget->columnCount() < 2)
            propertyEditWidget->setColumnCount(2);
        propertyEditWidget->setObjectName(QStringLiteral("propertyEditWidget"));
        QFont font;
        font.setPointSize(9);
        propertyEditWidget->setFont(font);
        propertyEditWidget->setAutoScrollMargin(12);
        propertyEditWidget->setColumnCount(2);
        propertyEditWidget->horizontalHeader()->setVisible(false);
        propertyEditWidget->horizontalHeader()->setCascadingSectionResizes(false);
        propertyEditWidget->horizontalHeader()->setDefaultSectionSize(200);
        propertyEditWidget->verticalHeader()->setVisible(false);
        propertyEditWidget->verticalHeader()->setDefaultSectionSize(20);
        propertyEditWidget->verticalHeader()->setMinimumSectionSize(15);

        gridLayout->addWidget(propertyEditWidget, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "HLM2ProcedureMapGenerator", 0));
        loadButton->setText(QApplication::translate("MainWindow", "Load", 0));
        saveButton->setText(QApplication::translate("MainWindow", "Save", 0));
    } // retranslateUi

};

namespace Ui
{
class MainWindow: public Ui_MainWindow
{
};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
