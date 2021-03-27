/********************************************************************************
** Form generated from reading UI file 'stock_managerafadKR.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef STOCK_MANAGERAFADKR_H
#define STOCK_MANAGERAFADKR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
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
    QAction *actionHome;
    QAction *actionSales;
    QAction *actionStock;
    QAction *actionSettings;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabMain;
    QWidget *tabHome;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QTableWidget *tableWidget_2;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_4;
    QPushButton *btnAdd_Cart;
    QPushButton *btnRemove_Cart;
    QFormLayout *formLayout_5;
    QLabel *label_4;
    QComboBox *comboBox_2;
    QPushButton *btnDone_Cart;
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *groupBox_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *lblItem_Count;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lblTotal;
    QWidget *tabSales;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *tableWidget;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLabel *label_2;
    QDateEdit *dateSales;
    QPushButton *btnRefreshSales;
    QSpacerItem *verticalSpacer;
    QLabel *label_12;
    QWidget *tabStock;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tblStock;
    QToolBox *toolBox;
    QWidget *page;
    QVBoxLayout *verticalLayout;
    QPushButton *btnSellItem;
    QPushButton *btnAddItem;
    QPushButton *btnRefresh;
    QLabel *label;
    QWidget *page_2;
    QWidget *tabSettings;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_3;
    QFormLayout *formLayout_3;
    QLabel *label_5;
    QComboBox *comboBox;
    QLabel *label_9;
    QLineEdit *lineEdit;
    QLabel *label_10;
    QGroupBox *grpPass;
    QFormLayout *formLayout_2;
    QLineEdit *txtOldPass;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *txtNewPass;
    QLabel *label_8;
    QLineEdit *txtNewPass_Confirm;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkBox;
    QGroupBox *groupBox_4;
    QFormLayout *formLayout_4;
    QLineEdit *lineEdit_2;
    QLabel *label_11;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuEdit;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *stock_manager)
    {
        if (stock_manager->objectName().isEmpty())
            stock_manager->setObjectName(QString::fromUtf8("stock_manager"));
        stock_manager->resize(759, 420);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/logo.svg"), QSize(), QIcon::Normal, QIcon::Off);
        stock_manager->setWindowIcon(icon);
        actQuit = new QAction(stock_manager);
        actQuit->setObjectName(QString::fromUtf8("actQuit"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/exit.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actQuit->setIcon(icon1);
        actQt_About = new QAction(stock_manager);
        actQt_About->setObjectName(QString::fromUtf8("actQt_About"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/information.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actQt_About->setIcon(icon2);
        actAbout = new QAction(stock_manager);
        actAbout->setObjectName(QString::fromUtf8("actAbout"));
        actAbout->setIcon(icon2);
        actCheck_For_Updates = new QAction(stock_manager);
        actCheck_For_Updates->setObjectName(QString::fromUtf8("actCheck_For_Updates"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/retweet.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actCheck_For_Updates->setIcon(icon3);
        actAdd_Item = new QAction(stock_manager);
        actAdd_Item->setObjectName(QString::fromUtf8("actAdd_Item"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/document-new.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actAdd_Item->setIcon(icon4);
        actionSell_Items = new QAction(stock_manager);
        actionSell_Items->setObjectName(QString::fromUtf8("actionSell_Items"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/shopping-bag.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionSell_Items->setIcon(icon5);
        actionCopy = new QAction(stock_manager);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/copy.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon6);
        actionPaste = new QAction(stock_manager);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/blog.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon7);
        actionCut = new QAction(stock_manager);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons/document-delete.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon8);
        actionHome = new QAction(stock_manager);
        actionHome->setObjectName(QString::fromUtf8("actionHome"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icons/home.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionHome->setIcon(icon9);
        actionSales = new QAction(stock_manager);
        actionSales->setObjectName(QString::fromUtf8("actionSales"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icons/to-do.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionSales->setIcon(icon10);
        actionStock = new QAction(stock_manager);
        actionStock->setObjectName(QString::fromUtf8("actionStock"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/icons/archive.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionStock->setIcon(icon11);
        actionSettings = new QAction(stock_manager);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/icons/gear.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionSettings->setIcon(icon12);
        centralWidget = new QWidget(stock_manager);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabMain = new QTabWidget(centralWidget);
        tabMain->setObjectName(QString::fromUtf8("tabMain"));
        tabMain->setTabPosition(QTabWidget::North);
        tabMain->setTabShape(QTabWidget::Rounded);
        tabMain->setElideMode(Qt::ElideNone);
        tabHome = new QWidget();
        tabHome->setObjectName(QString::fromUtf8("tabHome"));
        verticalLayout_3 = new QVBoxLayout(tabHome);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        tableWidget_2 = new QTableWidget(tabHome);
        if (tableWidget_2->columnCount() < 5)
            tableWidget_2->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));

        horizontalLayout_5->addWidget(tableWidget_2);

        groupBox_5 = new QGroupBox(tabHome);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        verticalLayout_4 = new QVBoxLayout(groupBox_5);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        btnAdd_Cart = new QPushButton(groupBox_5);
        btnAdd_Cart->setObjectName(QString::fromUtf8("btnAdd_Cart"));

        verticalLayout_4->addWidget(btnAdd_Cart);

        btnRemove_Cart = new QPushButton(groupBox_5);
        btnRemove_Cart->setObjectName(QString::fromUtf8("btnRemove_Cart"));

        verticalLayout_4->addWidget(btnRemove_Cart);

        formLayout_5 = new QFormLayout();
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        label_4 = new QLabel(groupBox_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, label_4);

        comboBox_2 = new QComboBox(groupBox_5);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        formLayout_5->setWidget(0, QFormLayout::FieldRole, comboBox_2);


        verticalLayout_4->addLayout(formLayout_5);

        btnDone_Cart = new QPushButton(groupBox_5);
        btnDone_Cart->setObjectName(QString::fromUtf8("btnDone_Cart"));

        verticalLayout_4->addWidget(btnDone_Cart);


        horizontalLayout_5->addWidget(groupBox_5);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        groupBox_6 = new QGroupBox(tabHome);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        horizontalLayout_7 = new QHBoxLayout(groupBox_6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        lblItem_Count = new QLabel(groupBox_6);
        lblItem_Count->setObjectName(QString::fromUtf8("lblItem_Count"));

        horizontalLayout_7->addWidget(lblItem_Count);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        lblTotal = new QLabel(groupBox_6);
        lblTotal->setObjectName(QString::fromUtf8("lblTotal"));

        horizontalLayout_7->addWidget(lblTotal);


        horizontalLayout_6->addWidget(groupBox_6);


        verticalLayout_3->addLayout(horizontalLayout_6);

        tabMain->addTab(tabHome, QString());
        tabSales = new QWidget();
        tabSales->setObjectName(QString::fromUtf8("tabSales"));
        horizontalLayout_2 = new QHBoxLayout(tabSales);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tableWidget = new QTableWidget(tabSales);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem11);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        horizontalLayout_2->addWidget(tableWidget);

        groupBox = new QGroupBox(tabSales);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(16777215, 27));

        formLayout->setWidget(0, QFormLayout::SpanningRole, label_3);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        dateSales = new QDateEdit(groupBox);
        dateSales->setObjectName(QString::fromUtf8("dateSales"));

        formLayout->setWidget(1, QFormLayout::FieldRole, dateSales);

        btnRefreshSales = new QPushButton(groupBox);
        btnRefreshSales->setObjectName(QString::fromUtf8("btnRefreshSales"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/icons/clockwise.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnRefreshSales->setIcon(icon13);

        formLayout->setWidget(2, QFormLayout::FieldRole, btnRefreshSales);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(3, QFormLayout::SpanningRole, verticalSpacer);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout->setWidget(4, QFormLayout::SpanningRole, label_12);


        horizontalLayout_2->addWidget(groupBox);

        tabMain->addTab(tabSales, QString());
        tabStock = new QWidget();
        tabStock->setObjectName(QString::fromUtf8("tabStock"));
        horizontalLayout = new QHBoxLayout(tabStock);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tblStock = new QTableWidget(tabStock);
        if (tblStock->columnCount() < 5)
            tblStock->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tblStock->setHorizontalHeaderItem(0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tblStock->setHorizontalHeaderItem(1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tblStock->setHorizontalHeaderItem(2, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tblStock->setHorizontalHeaderItem(3, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tblStock->setHorizontalHeaderItem(4, __qtablewidgetitem16);
        tblStock->setObjectName(QString::fromUtf8("tblStock"));

        horizontalLayout->addWidget(tblStock);

        toolBox = new QToolBox(tabStock);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setMinimumSize(QSize(0, 0));
        toolBox->setMaximumSize(QSize(240, 16777215));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 240, 260));
        verticalLayout = new QVBoxLayout(page);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnSellItem = new QPushButton(page);
        btnSellItem->setObjectName(QString::fromUtf8("btnSellItem"));
        btnSellItem->setMaximumSize(QSize(16777215, 50));

        verticalLayout->addWidget(btnSellItem);

        btnAddItem = new QPushButton(page);
        btnAddItem->setObjectName(QString::fromUtf8("btnAddItem"));
        btnAddItem->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(btnAddItem);

        btnRefresh = new QPushButton(page);
        btnRefresh->setObjectName(QString::fromUtf8("btnRefresh"));
        btnRefresh->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(btnRefresh);

        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        toolBox->addItem(page, QString::fromUtf8("Options"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 94, 24));
        toolBox->addItem(page_2, QString::fromUtf8("Stats"));

        horizontalLayout->addWidget(toolBox);

        tabMain->addTab(tabStock, QString());
        tabSettings = new QWidget();
        tabSettings->setObjectName(QString::fromUtf8("tabSettings"));
        gridLayout_2 = new QGridLayout(tabSettings);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        pushButton_3 = new QPushButton(tabSettings);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMaximumSize(QSize(100, 16777215));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/icons/time-reverse.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon14);

        horizontalLayout_4->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(tabSettings);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(111, 16777215));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/icons/checkmark.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon15);

        horizontalLayout_4->addWidget(pushButton_2);


        gridLayout_2->addLayout(horizontalLayout_4, 2, 1, 1, 1);

        groupBox_3 = new QGroupBox(tabSettings);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        formLayout_3 = new QFormLayout(groupBox_3);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_5);

        comboBox = new QComboBox(groupBox_3);
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setEditable(false);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, comboBox);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_9);

        lineEdit = new QLineEdit(groupBox_3);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, lineEdit);

        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        QFont font;
        font.setItalic(true);
        label_10->setFont(font);

        formLayout_3->setWidget(2, QFormLayout::SpanningRole, label_10);


        gridLayout_2->addWidget(groupBox_3, 0, 1, 1, 1);

        grpPass = new QGroupBox(tabSettings);
        grpPass->setObjectName(QString::fromUtf8("grpPass"));
        grpPass->setEnabled(false);
        formLayout_2 = new QFormLayout(grpPass);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        txtOldPass = new QLineEdit(grpPass);
        txtOldPass->setObjectName(QString::fromUtf8("txtOldPass"));
        txtOldPass->setEnabled(false);
        txtOldPass->setMaximumSize(QSize(250, 16777215));
        txtOldPass->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText|Qt::ImhSensitiveData);
        txtOldPass->setEchoMode(QLineEdit::Password);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, txtOldPass);

        label_6 = new QLabel(grpPass);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_6);

        label_7 = new QLabel(grpPass);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_7);

        txtNewPass = new QLineEdit(grpPass);
        txtNewPass->setObjectName(QString::fromUtf8("txtNewPass"));
        txtNewPass->setMaximumSize(QSize(250, 16777215));
        txtNewPass->setEchoMode(QLineEdit::Password);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, txtNewPass);

        label_8 = new QLabel(grpPass);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_8);

        txtNewPass_Confirm = new QLineEdit(grpPass);
        txtNewPass_Confirm->setObjectName(QString::fromUtf8("txtNewPass_Confirm"));
        txtNewPass_Confirm->setMaximumSize(QSize(250, 16777215));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, txtNewPass_Confirm);


        gridLayout_2->addWidget(grpPass, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(tabSettings);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        checkBox = new QCheckBox(groupBox_2);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout_2->addWidget(checkBox);


        gridLayout_2->addWidget(groupBox_2, 1, 1, 1, 1);

        groupBox_4 = new QGroupBox(tabSettings);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        formLayout_4 = new QFormLayout(groupBox_4);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        lineEdit_2 = new QLineEdit(groupBox_4);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, lineEdit_2);

        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_11);


        gridLayout_2->addWidget(groupBox_4, 1, 0, 1, 1);

        tabMain->addTab(tabSettings, QString());

        gridLayout->addWidget(tabMain, 0, 1, 1, 1);

        stock_manager->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(stock_manager);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 759, 27));
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
        menuFile->addAction(actionHome);
        menuFile->addAction(actionSettings);
        menuFile->addAction(actionSales);
        menuFile->addAction(actionStock);
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
        comboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(stock_manager);
    } // setupUi

    void retranslateUi(QMainWindow *stock_manager)
    {
        stock_manager->setWindowTitle(QCoreApplication::translate("stock_manager", "Dashboard", nullptr));
        actQuit->setText(QCoreApplication::translate("stock_manager", "Quit", nullptr));
#if QT_CONFIG(shortcut)
        actQuit->setShortcut(QCoreApplication::translate("stock_manager", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actQt_About->setText(QCoreApplication::translate("stock_manager", "Qt About", nullptr));
        actAbout->setText(QCoreApplication::translate("stock_manager", "About", nullptr));
        actCheck_For_Updates->setText(QCoreApplication::translate("stock_manager", "Check For Updates", nullptr));
        actAdd_Item->setText(QCoreApplication::translate("stock_manager", "Add New Item", nullptr));
#if QT_CONFIG(shortcut)
        actAdd_Item->setShortcut(QCoreApplication::translate("stock_manager", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSell_Items->setText(QCoreApplication::translate("stock_manager", "Sell Items", nullptr));
        actionCopy->setText(QCoreApplication::translate("stock_manager", "&Copy", nullptr));
#if QT_CONFIG(shortcut)
        actionCopy->setShortcut(QCoreApplication::translate("stock_manager", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPaste->setText(QCoreApplication::translate("stock_manager", "Paste", nullptr));
#if QT_CONFIG(shortcut)
        actionPaste->setShortcut(QCoreApplication::translate("stock_manager", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCut->setText(QCoreApplication::translate("stock_manager", "Cut", nullptr));
#if QT_CONFIG(shortcut)
        actionCut->setShortcut(QCoreApplication::translate("stock_manager", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actionHome->setText(QCoreApplication::translate("stock_manager", "Home", nullptr));
        actionSales->setText(QCoreApplication::translate("stock_manager", "Sales", nullptr));
        actionStock->setText(QCoreApplication::translate("stock_manager", "Stock", nullptr));
        actionSettings->setText(QCoreApplication::translate("stock_manager", "Settings", nullptr));
#if QT_CONFIG(statustip)
        tabMain->setStatusTip(QCoreApplication::translate("stock_manager", "View items on stock", nullptr));
#endif // QT_CONFIG(statustip)
        QTableWidgetItem *___qtablewidgetitem = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("stock_manager", "Item Number", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("stock_manager", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("stock_manager", "Weight / Capacity", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("stock_manager", "Quantity", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_2->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("stock_manager", "Price", nullptr));
        groupBox_5->setTitle(QString());
        btnAdd_Cart->setText(QCoreApplication::translate("stock_manager", "Add Item", nullptr));
        btnRemove_Cart->setText(QCoreApplication::translate("stock_manager", "Remove Item", nullptr));
        label_4->setText(QCoreApplication::translate("stock_manager", "Payment Method:", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("stock_manager", "Cash", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("stock_manager", "Mpesa", nullptr));

        btnDone_Cart->setText(QCoreApplication::translate("stock_manager", "Done", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("stock_manager", "Stats", nullptr));
        lblItem_Count->setText(QCoreApplication::translate("stock_manager", "<html><head/><body><p><span style=\" font-size:12pt;\">Items On Cart: 8</span></p></body></html>", nullptr));
        lblTotal->setText(QCoreApplication::translate("stock_manager", "<html><head/><body><p><span style=\" font-size:16pt;\">Total: Kshs. 2,030</span></p></body></html>", nullptr));
        tabMain->setTabText(tabMain->indexOf(tabHome), QCoreApplication::translate("stock_manager", "Home", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("stock_manager", "Item Number / Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("stock_manager", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("stock_manager", "Quantity", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("stock_manager", "Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("stock_manager", "Total Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("stock_manager", "Payment Method", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("stock_manager", "Sale Date", nullptr));
        groupBox->setTitle(QCoreApplication::translate("stock_manager", "Options", nullptr));
        label_3->setText(QCoreApplication::translate("stock_manager", "Select the date you want to view sales", nullptr));
        label_2->setText(QCoreApplication::translate("stock_manager", "Enter Date:", nullptr));
        btnRefreshSales->setText(QCoreApplication::translate("stock_manager", "Refresh", nullptr));
        label_12->setText(QCoreApplication::translate("stock_manager", "<html><head/><body><p><span style=\" font-size:12pt;\">Sales Made on </span><span style=\" font-size:12pt; font-weight:600;\">Wed 15 July 2021</span></p><p><span style=\" font-size:12pt;\">Items Sold: </span><span style=\" font-size:12pt; font-weight:600;\">244</span></p><p><span style=\" font-size:12pt;\">Sales Made: </span><span style=\" font-size:12pt; font-weight:600;\">Ksh. 3,245</span></p></body></html>", nullptr));
        tabMain->setTabText(tabMain->indexOf(tabSales), QCoreApplication::translate("stock_manager", "Sales", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tblStock->horizontalHeaderItem(0);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("stock_manager", "Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tblStock->horizontalHeaderItem(1);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("stock_manager", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tblStock->horizontalHeaderItem(2);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("stock_manager", "Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tblStock->horizontalHeaderItem(3);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("stock_manager", "Weight / Capacity", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tblStock->horizontalHeaderItem(4);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("stock_manager", "Quantity", nullptr));
#if QT_CONFIG(statustip)
        btnSellItem->setStatusTip(QCoreApplication::translate("stock_manager", "Record sold items", nullptr));
#endif // QT_CONFIG(statustip)
        btnSellItem->setText(QCoreApplication::translate("stock_manager", "Sell Items", nullptr));
#if QT_CONFIG(statustip)
        btnAddItem->setStatusTip(QCoreApplication::translate("stock_manager", "Add new item into stock", nullptr));
#endif // QT_CONFIG(statustip)
        btnAddItem->setText(QCoreApplication::translate("stock_manager", "Add Item", nullptr));
#if QT_CONFIG(statustip)
        btnRefresh->setStatusTip(QCoreApplication::translate("stock_manager", "Display sales statistics", nullptr));
#endif // QT_CONFIG(statustip)
        btnRefresh->setText(QCoreApplication::translate("stock_manager", "Refresh", nullptr));
        label->setText(QCoreApplication::translate("stock_manager", "<html><head/><body><p>Stock: 244</p><p>Sales Today: 23 for Ksh. 2,244</p><p><span style=\" font-weight:600;\">Items Out of Stock:</span></p><p>1. Milk<br/>2. TipTop<br/>3. Oreo</p></body></html>", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("stock_manager", "Options", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("stock_manager", "Stats", nullptr));
        tabMain->setTabText(tabMain->indexOf(tabStock), QCoreApplication::translate("stock_manager", "Stock", nullptr));
        pushButton_3->setText(QCoreApplication::translate("stock_manager", "Reset", nullptr));
        pushButton_2->setText(QCoreApplication::translate("stock_manager", "Save", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("stock_manager", "Other", nullptr));
        label_5->setText(QCoreApplication::translate("stock_manager", "Change Theme:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("stock_manager", "Default", nullptr));

        comboBox->setCurrentText(QCoreApplication::translate("stock_manager", "Default", nullptr));
        comboBox->setPlaceholderText(QCoreApplication::translate("stock_manager", "Select Theme...", nullptr));
        label_9->setText(QCoreApplication::translate("stock_manager", "Date Format:", nullptr));
        lineEdit->setText(QString());
        label_10->setText(QCoreApplication::translate("stock_manager", "DD for Date, MM for month, YY for year", nullptr));
        grpPass->setTitle(QCoreApplication::translate("stock_manager", "Change Password", nullptr));
        label_6->setText(QCoreApplication::translate("stock_manager", "Old Password:", nullptr));
        label_7->setText(QCoreApplication::translate("stock_manager", "New Password:", nullptr));
        label_8->setText(QCoreApplication::translate("stock_manager", "Confirm Password:", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("stock_manager", "Advance", nullptr));
        checkBox->setText(QCoreApplication::translate("stock_manager", "Dev Mode", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("stock_manager", "Shop", nullptr));
        label_11->setText(QCoreApplication::translate("stock_manager", "Shop Name:", nullptr));
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

#endif // STOCK_MANAGERAFADKR_H
