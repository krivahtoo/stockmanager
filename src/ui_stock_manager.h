/********************************************************************************
** Form generated from reading UI file 'stock_managerPNaKFv.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef STOCK_MANAGERPNAKFV_H
#define STOCK_MANAGERPNAKFV_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_stock_manager
{
public:
    QAction *actQuit;
    QAction *actQt_About;
    QAction *actAbout;
    QAction *actCheck_For_Updates;
    QAction *actAdd_Item;
    QAction *actionSell_Items;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionCut;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabMain;
    QWidget *tabStock;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tblStock;
    QToolBox *toolBox;
    QWidget *page;
    QVBoxLayout *verticalLayout;
    QPushButton *btnSellItem;
    QPushButton *btnAddItem;
    QPushButton *btnStats;
    QWidget *tabSettings;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuEdit;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *stock_manager)
    {
        if (stock_manager->objectName().isEmpty())
            stock_manager->setObjectName(QString::fromUtf8("stock_manager"));
        stock_manager->resize(716, 429);
        actQuit = new QAction(stock_manager);
        actQuit->setObjectName(QString::fromUtf8("actQuit"));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("application-exit")));
        actQuit->setIcon(icon);
        actQt_About = new QAction(stock_manager);
        actQt_About->setObjectName(QString::fromUtf8("actQt_About"));
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("help-about")));
        actQt_About->setIcon(icon1);
        actAbout = new QAction(stock_manager);
        actAbout->setObjectName(QString::fromUtf8("actAbout"));
        actAbout->setIcon(icon1);
        actCheck_For_Updates = new QAction(stock_manager);
        actCheck_For_Updates->setObjectName(QString::fromUtf8("actCheck_For_Updates"));
        QIcon icon2(QIcon::fromTheme(QString::fromUtf8("view-refresh")));
        actCheck_For_Updates->setIcon(icon2);
        actAdd_Item = new QAction(stock_manager);
        actAdd_Item->setObjectName(QString::fromUtf8("actAdd_Item"));
        QIcon icon3(QIcon::fromTheme(QString::fromUtf8("document-new")));
        actAdd_Item->setIcon(icon3);
        actionSell_Items = new QAction(stock_manager);
        actionSell_Items->setObjectName(QString::fromUtf8("actionSell_Items"));
        QIcon icon4(QIcon::fromTheme(QString::fromUtf8("document-send")));
        actionSell_Items->setIcon(icon4);
        actionCopy = new QAction(stock_manager);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        QIcon icon5(QIcon::fromTheme(QString::fromUtf8("edit-copy")));
        actionCopy->setIcon(icon5);
        actionPaste = new QAction(stock_manager);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        QIcon icon6(QIcon::fromTheme(QString::fromUtf8("edit-paste")));
        actionPaste->setIcon(icon6);
        actionCut = new QAction(stock_manager);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        QIcon icon7(QIcon::fromTheme(QString::fromUtf8("edit-cut")));
        actionCut->setIcon(icon7);
        centralWidget = new QWidget(stock_manager);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabMain = new QTabWidget(centralWidget);
        tabMain->setObjectName(QString::fromUtf8("tabMain"));
        tabMain->setTabPosition(QTabWidget::North);
        tabMain->setTabShape(QTabWidget::Rounded);
        tabStock = new QWidget();
        tabStock->setObjectName(QString::fromUtf8("tabStock"));
        horizontalLayout = new QHBoxLayout(tabStock);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tblStock = new QTableWidget(tabStock);
        if (tblStock->columnCount() < 4)
            tblStock->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblStock->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblStock->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblStock->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblStock->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tblStock->setObjectName(QString::fromUtf8("tblStock"));

        horizontalLayout->addWidget(tblStock);

        toolBox = new QToolBox(tabStock);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setMinimumSize(QSize(0, 0));
        toolBox->setMaximumSize(QSize(240, 16777215));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 240, 297));
        verticalLayout = new QVBoxLayout(page);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnSellItem = new QPushButton(page);
        btnSellItem->setObjectName(QString::fromUtf8("btnSellItem"));
        btnSellItem->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(btnSellItem);

        btnAddItem = new QPushButton(page);
        btnAddItem->setObjectName(QString::fromUtf8("btnAddItem"));
        btnAddItem->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(btnAddItem);

        btnStats = new QPushButton(page);
        btnStats->setObjectName(QString::fromUtf8("btnStats"));
        btnStats->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(btnStats);

        toolBox->addItem(page, QString::fromUtf8("Options"));

        horizontalLayout->addWidget(toolBox);

        tabMain->addTab(tabStock, QString());
        tabSettings = new QWidget();
        tabSettings->setObjectName(QString::fromUtf8("tabSettings"));
        tabMain->addTab(tabSettings, QString());

        gridLayout->addWidget(tabMain, 0, 1, 1, 1);

        stock_manager->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(stock_manager);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 716, 27));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        stock_manager->setMenuBar(menuBar);
        statusBar = new QStatusBar(stock_manager);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        stock_manager->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actAdd_Item);
        menuFile->addAction(actionSell_Items);
        menuFile->addSeparator();
        menuFile->addAction(actQuit);
        menuHelp->addAction(actQt_About);
        menuHelp->addAction(actAbout);
        menuHelp->addSeparator();
        menuHelp->addAction(actCheck_For_Updates);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addAction(actionCut);

        retranslateUi(stock_manager);

        tabMain->setCurrentIndex(0);
        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(stock_manager);
    } // setupUi

    void retranslateUi(QMainWindow *stock_manager)
    {
        stock_manager->setWindowTitle(QCoreApplication::translate("stock_manager", "Stock Manager", nullptr));
        actQuit->setText(QCoreApplication::translate("stock_manager", "Quit", nullptr));
#if QT_CONFIG(shortcut)
        actQuit->setShortcut(QCoreApplication::translate("stock_manager", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actQt_About->setText(QCoreApplication::translate("stock_manager", "Qt About", nullptr));
        actAbout->setText(QCoreApplication::translate("stock_manager", "About", nullptr));
        actCheck_For_Updates->setText(QCoreApplication::translate("stock_manager", "Check For Updates", nullptr));
        actAdd_Item->setText(QCoreApplication::translate("stock_manager", "Add Item", nullptr));
        actionSell_Items->setText(QCoreApplication::translate("stock_manager", "Sell Items", nullptr));
        actionCopy->setText(QCoreApplication::translate("stock_manager", "Copy", nullptr));
        actionPaste->setText(QCoreApplication::translate("stock_manager", "Paste", nullptr));
        actionCut->setText(QCoreApplication::translate("stock_manager", "Cut", nullptr));
#if QT_CONFIG(statustip)
        tabMain->setStatusTip(QCoreApplication::translate("stock_manager", "View items on stock", nullptr));
#endif // QT_CONFIG(statustip)
        QTableWidgetItem *___qtablewidgetitem = tblStock->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("stock_manager", "Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblStock->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("stock_manager", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblStock->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("stock_manager", "Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblStock->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("stock_manager", "Quantity", nullptr));
#if QT_CONFIG(statustip)
        btnSellItem->setStatusTip(QCoreApplication::translate("stock_manager", "Record sold items", nullptr));
#endif // QT_CONFIG(statustip)
        btnSellItem->setText(QCoreApplication::translate("stock_manager", "Sell Item", nullptr));
#if QT_CONFIG(statustip)
        btnAddItem->setStatusTip(QCoreApplication::translate("stock_manager", "Add new item into stock", nullptr));
#endif // QT_CONFIG(statustip)
        btnAddItem->setText(QCoreApplication::translate("stock_manager", "Add Item", nullptr));
#if QT_CONFIG(statustip)
        btnStats->setStatusTip(QCoreApplication::translate("stock_manager", "Display sales statistics", nullptr));
#endif // QT_CONFIG(statustip)
        btnStats->setText(QCoreApplication::translate("stock_manager", "Stats", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("stock_manager", "Options", nullptr));
        tabMain->setTabText(tabMain->indexOf(tabStock), QCoreApplication::translate("stock_manager", "Stock", nullptr));
        tabMain->setTabText(tabMain->indexOf(tabSettings), QCoreApplication::translate("stock_manager", "Settings", nullptr));
        menuFile->setTitle(QCoreApplication::translate("stock_manager", "File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("stock_manager", "Help", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("stock_manager", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class stock_manager: public Ui_stock_manager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // STOCK_MANAGERPNAKFV_H
