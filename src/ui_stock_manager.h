/********************************************************************************
** Form generated from reading UI file 'stock_managerkRBGsX.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef STOCK_MANAGERKRBGSX_H
#define STOCK_MANAGERKRBGSX_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
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
    QAction *actSell_Items;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionCut;
    QAction *actHome;
    QAction *actSales;
    QAction *actStock;
    QAction *actSettings;
    QAction *actSettings_2;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabMain;
    QWidget *tabHome;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QTableWidget *tblCart;
    QGroupBox *grpCart;
    QVBoxLayout *verticalLayout_4;
    QPushButton *btnAdd_Cart;
    QPushButton *btnRemove_Cart;
    QPushButton *btnClear_Cart;
    QFormLayout *formLayout_5;
    QLabel *lblPayment_Method;
    QComboBox *cmbPayment_Method;
    QPushButton *btnSell_Cart;
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *grbCart_Stats;
    QHBoxLayout *horizontalLayout_7;
    QLabel *lblItem_Count;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lblTotal;
    QWidget *tabSales;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *tblSales;
    QGroupBox *grpSales;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *grpOptions;
    QFormLayout *formLayout_6;
    QPushButton *btnRefreshSales;
    QLabel *label_2;
    QDateEdit *dateSales;
    QLabel *label_3;
    QGroupBox *grpStats;
    QVBoxLayout *verticalLayout_6;
    QLabel *lblSalesStats;
    QGroupBox *grpSalesStats;
    QVBoxLayout *verticalLayout_2;
    QLabel *lblSalesStats_2;
    QWidget *tabStock;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tblStock;
    QGroupBox *grpStock;
    QVBoxLayout *verticalLayout;
    QPushButton *btnSellItem;
    QPushButton *btnAddItem;
    QPushButton *btnRefresh;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_5;
    QLabel *lblStats;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuEdit;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *stock_manager)
    {
        if (stock_manager->objectName().isEmpty())
            stock_manager->setObjectName(QString::fromUtf8("stock_manager"));
        stock_manager->resize(799, 492);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/logo.svg"), QSize(), QIcon::Normal, QIcon::Off);
        stock_manager->setWindowIcon(icon);
        stock_manager->setStyleSheet(QString::fromUtf8(""));
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
        actSell_Items = new QAction(stock_manager);
        actSell_Items->setObjectName(QString::fromUtf8("actSell_Items"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/shopping-bag.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actSell_Items->setIcon(icon5);
        actionCopy = new QAction(stock_manager);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/copy.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon6);
        actionCopy->setMenuRole(QAction::TextHeuristicRole);
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
        actHome = new QAction(stock_manager);
        actHome->setObjectName(QString::fromUtf8("actHome"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icons/cart.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actHome->setIcon(icon9);
        actSales = new QAction(stock_manager);
        actSales->setObjectName(QString::fromUtf8("actSales"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icons/to-do.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actSales->setIcon(icon10);
        actStock = new QAction(stock_manager);
        actStock->setObjectName(QString::fromUtf8("actStock"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/icons/archive.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actStock->setIcon(icon11);
        actSettings = new QAction(stock_manager);
        actSettings->setObjectName(QString::fromUtf8("actSettings"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/icons/gear.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actSettings->setIcon(icon12);
        actSettings_2 = new QAction(stock_manager);
        actSettings_2->setObjectName(QString::fromUtf8("actSettings_2"));
        actSettings_2->setIcon(icon12);
        centralWidget = new QWidget(stock_manager);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabMain = new QTabWidget(centralWidget);
        tabMain->setObjectName(QString::fromUtf8("tabMain"));
        tabMain->setAutoFillBackground(false);
        tabMain->setTabPosition(QTabWidget::North);
        tabMain->setTabShape(QTabWidget::Rounded);
        tabMain->setElideMode(Qt::ElideNone);
        tabMain->setDocumentMode(false);
        tabHome = new QWidget();
        tabHome->setObjectName(QString::fromUtf8("tabHome"));
        verticalLayout_3 = new QVBoxLayout(tabHome);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        tblCart = new QTableWidget(tabHome);
        if (tblCart->columnCount() < 5)
            tblCart->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblCart->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblCart->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblCart->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblCart->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblCart->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tblCart->setObjectName(QString::fromUtf8("tblCart"));
        tblCart->setStyleSheet(QString::fromUtf8(""));
        tblCart->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        tblCart->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tblCart->setSelectionBehavior(QAbstractItemView::SelectRows);
        tblCart->setSortingEnabled(false);
        tblCart->horizontalHeader()->setCascadingSectionResizes(true);
        tblCart->horizontalHeader()->setStretchLastSection(true);
        tblCart->verticalHeader()->setProperty("showSortIndicator", QVariant(true));

        horizontalLayout_5->addWidget(tblCart);

        grpCart = new QGroupBox(tabHome);
        grpCart->setObjectName(QString::fromUtf8("grpCart"));
        verticalLayout_4 = new QVBoxLayout(grpCart);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        btnAdd_Cart = new QPushButton(grpCart);
        btnAdd_Cart->setObjectName(QString::fromUtf8("btnAdd_Cart"));
        btnAdd_Cart->setMinimumSize(QSize(0, 30));
        btnAdd_Cart->setMaximumSize(QSize(16777215, 16777215));
        btnAdd_Cart->setIcon(icon9);

        verticalLayout_4->addWidget(btnAdd_Cart);

        btnRemove_Cart = new QPushButton(grpCart);
        btnRemove_Cart->setObjectName(QString::fromUtf8("btnRemove_Cart"));
        btnRemove_Cart->setEnabled(false);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/icons/cross.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnRemove_Cart->setIcon(icon13);

        verticalLayout_4->addWidget(btnRemove_Cart);

        btnClear_Cart = new QPushButton(grpCart);
        btnClear_Cart->setObjectName(QString::fromUtf8("btnClear_Cart"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/icons/trash.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnClear_Cart->setIcon(icon14);

        verticalLayout_4->addWidget(btnClear_Cart);

        formLayout_5 = new QFormLayout();
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        lblPayment_Method = new QLabel(grpCart);
        lblPayment_Method->setObjectName(QString::fromUtf8("lblPayment_Method"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, lblPayment_Method);

        cmbPayment_Method = new QComboBox(grpCart);
        cmbPayment_Method->addItem(QString());
        cmbPayment_Method->addItem(QString());
        cmbPayment_Method->setObjectName(QString::fromUtf8("cmbPayment_Method"));
        cmbPayment_Method->setCurrentText(QString::fromUtf8("Cash"));

        formLayout_5->setWidget(0, QFormLayout::FieldRole, cmbPayment_Method);


        verticalLayout_4->addLayout(formLayout_5);

        btnSell_Cart = new QPushButton(grpCart);
        btnSell_Cart->setObjectName(QString::fromUtf8("btnSell_Cart"));
        btnSell_Cart->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        btnSell_Cart->setFont(font);
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/icons/basket.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnSell_Cart->setIcon(icon15);
        btnSell_Cart->setAutoDefault(true);

        verticalLayout_4->addWidget(btnSell_Cart);


        horizontalLayout_5->addWidget(grpCart);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        grbCart_Stats = new QGroupBox(tabHome);
        grbCart_Stats->setObjectName(QString::fromUtf8("grbCart_Stats"));
        horizontalLayout_7 = new QHBoxLayout(grbCart_Stats);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        lblItem_Count = new QLabel(grbCart_Stats);
        lblItem_Count->setObjectName(QString::fromUtf8("lblItem_Count"));

        horizontalLayout_7->addWidget(lblItem_Count);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        lblTotal = new QLabel(grbCart_Stats);
        lblTotal->setObjectName(QString::fromUtf8("lblTotal"));

        horizontalLayout_7->addWidget(lblTotal);


        horizontalLayout_6->addWidget(grbCart_Stats);


        verticalLayout_3->addLayout(horizontalLayout_6);

        tabMain->addTab(tabHome, QString());
        tabSales = new QWidget();
        tabSales->setObjectName(QString::fromUtf8("tabSales"));
        horizontalLayout_2 = new QHBoxLayout(tabSales);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tblSales = new QTableWidget(tabSales);
        if (tblSales->columnCount() < 7)
            tblSales->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tblSales->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tblSales->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tblSales->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tblSales->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tblSales->setHorizontalHeaderItem(4, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tblSales->setHorizontalHeaderItem(5, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tblSales->setHorizontalHeaderItem(6, __qtablewidgetitem11);
        tblSales->setObjectName(QString::fromUtf8("tblSales"));
        tblSales->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tblSales->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        tblSales->setSelectionBehavior(QAbstractItemView::SelectRows);
        tblSales->setRowCount(0);
        tblSales->horizontalHeader()->setCascadingSectionResizes(true);
        tblSales->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tblSales->horizontalHeader()->setStretchLastSection(true);

        horizontalLayout_2->addWidget(tblSales);

        grpSales = new QGroupBox(tabSales);
        grpSales->setObjectName(QString::fromUtf8("grpSales"));
        grpSales->setFlat(false);
        grpSales->setCheckable(false);
        verticalLayout_7 = new QVBoxLayout(grpSales);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        grpOptions = new QGroupBox(grpSales);
        grpOptions->setObjectName(QString::fromUtf8("grpOptions"));
        formLayout_6 = new QFormLayout(grpOptions);
        formLayout_6->setObjectName(QString::fromUtf8("formLayout_6"));
        btnRefreshSales = new QPushButton(grpOptions);
        btnRefreshSales->setObjectName(QString::fromUtf8("btnRefreshSales"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/icons/clockwise.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnRefreshSales->setIcon(icon16);

        formLayout_6->setWidget(7, QFormLayout::FieldRole, btnRefreshSales);

        label_2 = new QLabel(grpOptions);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout_6->setWidget(2, QFormLayout::LabelRole, label_2);

        dateSales = new QDateEdit(grpOptions);
        dateSales->setObjectName(QString::fromUtf8("dateSales"));

        formLayout_6->setWidget(2, QFormLayout::FieldRole, dateSales);

        label_3 = new QLabel(grpOptions);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(16777215, 27));

        formLayout_6->setWidget(0, QFormLayout::SpanningRole, label_3);


        verticalLayout_7->addWidget(grpOptions);

        grpStats = new QGroupBox(grpSales);
        grpStats->setObjectName(QString::fromUtf8("grpStats"));
        verticalLayout_6 = new QVBoxLayout(grpStats);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        lblSalesStats = new QLabel(grpStats);
        lblSalesStats->setObjectName(QString::fromUtf8("lblSalesStats"));

        verticalLayout_6->addWidget(lblSalesStats);

        grpSalesStats = new QGroupBox(grpStats);
        grpSalesStats->setObjectName(QString::fromUtf8("grpSalesStats"));
        verticalLayout_2 = new QVBoxLayout(grpSalesStats);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lblSalesStats_2 = new QLabel(grpSalesStats);
        lblSalesStats_2->setObjectName(QString::fromUtf8("lblSalesStats_2"));

        verticalLayout_2->addWidget(lblSalesStats_2);


        verticalLayout_6->addWidget(grpSalesStats);


        verticalLayout_7->addWidget(grpStats);


        horizontalLayout_2->addWidget(grpSales);

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
        tblStock->setSelectionBehavior(QAbstractItemView::SelectRows);
        tblStock->horizontalHeader()->setCascadingSectionResizes(true);
        tblStock->horizontalHeader()->setStretchLastSection(true);

        horizontalLayout->addWidget(tblStock);

        grpStock = new QGroupBox(tabStock);
        grpStock->setObjectName(QString::fromUtf8("grpStock"));
        grpStock->setMinimumSize(QSize(0, 0));
        grpStock->setMaximumSize(QSize(240, 16777215));
        verticalLayout = new QVBoxLayout(grpStock);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnSellItem = new QPushButton(grpStock);
        btnSellItem->setObjectName(QString::fromUtf8("btnSellItem"));
        btnSellItem->setMaximumSize(QSize(16777215, 16777215));
        btnSellItem->setIcon(icon9);

        verticalLayout->addWidget(btnSellItem);

        btnAddItem = new QPushButton(grpStock);
        btnAddItem->setObjectName(QString::fromUtf8("btnAddItem"));
        btnAddItem->setMaximumSize(QSize(16777215, 16777215));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/icons/plus.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnAddItem->setIcon(icon17);

        verticalLayout->addWidget(btnAddItem);

        btnRefresh = new QPushButton(grpStock);
        btnRefresh->setObjectName(QString::fromUtf8("btnRefresh"));
        btnRefresh->setMaximumSize(QSize(16777215, 16777215));
        btnRefresh->setIcon(icon16);

        verticalLayout->addWidget(btnRefresh);

        groupBox_7 = new QGroupBox(grpStock);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        verticalLayout_5 = new QVBoxLayout(groupBox_7);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        lblStats = new QLabel(groupBox_7);
        lblStats->setObjectName(QString::fromUtf8("lblStats"));

        verticalLayout_5->addWidget(lblStats);


        verticalLayout->addWidget(groupBox_7);


        horizontalLayout->addWidget(grpStock);

        tabMain->addTab(tabStock, QString());

        gridLayout->addWidget(tabMain, 0, 0, 1, 1);

        stock_manager->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(stock_manager);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 799, 27));
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
        QWidget::setTabOrder(btnAdd_Cart, btnRemove_Cart);
        QWidget::setTabOrder(btnRemove_Cart, cmbPayment_Method);
        QWidget::setTabOrder(cmbPayment_Method, btnSell_Cart);
        QWidget::setTabOrder(btnSell_Cart, dateSales);
        QWidget::setTabOrder(dateSales, btnRefreshSales);
        QWidget::setTabOrder(btnRefreshSales, btnAddItem);
        QWidget::setTabOrder(btnAddItem, btnSellItem);
        QWidget::setTabOrder(btnSellItem, tabMain);
        QWidget::setTabOrder(tabMain, tblStock);
        QWidget::setTabOrder(tblStock, tblCart);
        QWidget::setTabOrder(tblCart, tblSales);
        QWidget::setTabOrder(tblSales, btnRefresh);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actAdd_Item);
        menuFile->addAction(actSell_Items);
        menuFile->addSeparator();
        menuFile->addAction(actHome);
        menuFile->addAction(actSales);
        menuFile->addAction(actStock);
        menuFile->addSeparator();
        menuFile->addAction(actQuit);
        menuHelp->addAction(actQt_About);
        menuHelp->addAction(actAbout);
        menuHelp->addSeparator();
        menuHelp->addAction(actCheck_For_Updates);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addAction(actionCut);
        menuEdit->addSeparator();
        menuEdit->addAction(actSettings_2);

        retranslateUi(stock_manager);

        tabMain->setCurrentIndex(0);
        btnSell_Cart->setDefault(true);


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
        actSell_Items->setText(QCoreApplication::translate("stock_manager", "Sell Items", nullptr));
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
        actHome->setText(QCoreApplication::translate("stock_manager", "Cart", nullptr));
        actSales->setText(QCoreApplication::translate("stock_manager", "Sales", nullptr));
        actStock->setText(QCoreApplication::translate("stock_manager", "Stock", nullptr));
        actSettings->setText(QCoreApplication::translate("stock_manager", "Settings", nullptr));
        actSettings_2->setText(QCoreApplication::translate("stock_manager", "Settings", nullptr));
#if QT_CONFIG(statustip)
        tabMain->setStatusTip(QCoreApplication::translate("stock_manager", "View items on stock", nullptr));
#endif // QT_CONFIG(statustip)
        QTableWidgetItem *___qtablewidgetitem = tblCart->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("stock_manager", "Item Number", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblCart->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("stock_manager", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblCart->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("stock_manager", "Quantity", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblCart->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("stock_manager", "Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblCart->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("stock_manager", "Total Price", nullptr));
        grpCart->setTitle(QString());
        btnAdd_Cart->setText(QCoreApplication::translate("stock_manager", "Add Item to Cart", nullptr));
#if QT_CONFIG(shortcut)
        btnAdd_Cart->setShortcut(QCoreApplication::translate("stock_manager", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        btnRemove_Cart->setText(QCoreApplication::translate("stock_manager", "Remove Item", nullptr));
#if QT_CONFIG(shortcut)
        btnRemove_Cart->setShortcut(QCoreApplication::translate("stock_manager", "Ctrl+D", nullptr));
#endif // QT_CONFIG(shortcut)
        btnClear_Cart->setText(QCoreApplication::translate("stock_manager", "Clear Cart", nullptr));
        lblPayment_Method->setText(QCoreApplication::translate("stock_manager", "Payment Method:", nullptr));
        cmbPayment_Method->setItemText(0, QCoreApplication::translate("stock_manager", "Cash", nullptr));
        cmbPayment_Method->setItemText(1, QCoreApplication::translate("stock_manager", "Mpesa", nullptr));

        btnSell_Cart->setText(QCoreApplication::translate("stock_manager", "Sell", nullptr));
#if QT_CONFIG(shortcut)
        btnSell_Cart->setShortcut(QCoreApplication::translate("stock_manager", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        grbCart_Stats->setTitle(QString());
        lblItem_Count->setText(QCoreApplication::translate("stock_manager", "<html><head/><body><p><span style=\" font-size:12pt;\">Items On Cart: 0</span></p></body></html>", nullptr));
        lblTotal->setText(QCoreApplication::translate("stock_manager", "<html><head/><body><p><span style=\" font-size:16pt;\">Total: Kshs. 0.00</span></p></body></html>", nullptr));
        tabMain->setTabText(tabMain->indexOf(tabHome), QCoreApplication::translate("stock_manager", "Cart", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tblSales->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("stock_manager", "Item Number", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tblSales->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("stock_manager", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tblSales->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("stock_manager", "Quantity", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tblSales->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("stock_manager", "Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tblSales->horizontalHeaderItem(4);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("stock_manager", "Total Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tblSales->horizontalHeaderItem(5);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("stock_manager", "Payment Method", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tblSales->horizontalHeaderItem(6);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("stock_manager", "Sale Date", nullptr));
        grpSales->setTitle(QString());
        grpOptions->setTitle(QCoreApplication::translate("stock_manager", "Options", nullptr));
        btnRefreshSales->setText(QCoreApplication::translate("stock_manager", "Refresh", nullptr));
#if QT_CONFIG(shortcut)
        btnRefreshSales->setShortcut(QCoreApplication::translate("stock_manager", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        label_2->setText(QCoreApplication::translate("stock_manager", "Enter Date:", nullptr));
        dateSales->setDisplayFormat(QCoreApplication::translate("stock_manager", "dd-MM-yyyy", nullptr));
        label_3->setText(QCoreApplication::translate("stock_manager", "Select the date you want to view sales", nullptr));
        grpStats->setTitle(QCoreApplication::translate("stock_manager", "Stats", nullptr));
        lblSalesStats->setText(QCoreApplication::translate("stock_manager", "<html><head/><body><p><span style=\" font-size:12pt;\">Sales Made on </span><span style=\" font-size:12pt; font-weight:600;\">Wed 15 July 2021</span></p><p><span style=\" font-size:12pt;\">Items Sold: </span><span style=\" font-size:12pt; font-weight:600;\">244</span></p><p><span style=\" font-size:12pt;\">Sales Made: </span><span style=\" font-size:12pt; font-weight:600;\">Ksh. 3,245</span></p></body></html>", nullptr));
        grpSalesStats->setTitle(QCoreApplication::translate("stock_manager", "Week and Month", nullptr));
        lblSalesStats_2->setText(QCoreApplication::translate("stock_manager", "<html><head/><body><p><span style=\" font-weight:600;\">Sales this week:</span><br/>0 items for <span style=\" font-weight:600;\">Ksh. 0.00</span></p><p><span style=\" font-weight:600;\">Sales this Month:</span><br/>0 items for <span style=\" font-weight:600;\">Ksh. 0.00</span></p></body></html>", nullptr));
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
#if QT_CONFIG(shortcut)
        btnSellItem->setShortcut(QCoreApplication::translate("stock_manager", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(statustip)
        btnAddItem->setStatusTip(QCoreApplication::translate("stock_manager", "Add new item into stock", nullptr));
#endif // QT_CONFIG(statustip)
        btnAddItem->setText(QCoreApplication::translate("stock_manager", "Add Item", nullptr));
#if QT_CONFIG(shortcut)
        btnAddItem->setShortcut(QCoreApplication::translate("stock_manager", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(statustip)
        btnRefresh->setStatusTip(QCoreApplication::translate("stock_manager", "Display sales statistics", nullptr));
#endif // QT_CONFIG(statustip)
        btnRefresh->setText(QCoreApplication::translate("stock_manager", "Refresh", nullptr));
#if QT_CONFIG(shortcut)
        btnRefresh->setShortcut(QCoreApplication::translate("stock_manager", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        groupBox_7->setTitle(QString());
        lblStats->setText(QCoreApplication::translate("stock_manager", "<html><head/><body><p>Stock: 244</p><p>Sales Today: 23 for Ksh. 2,244</p><p><span style=\" font-weight:600;\">Items Out of Stock:</span></p><p>1. Milk<br/>2. TipTop<br/>3. Oreo</p></body></html>", nullptr));
        tabMain->setTabText(tabMain->indexOf(tabStock), QCoreApplication::translate("stock_manager", "Stock", nullptr));
        menuFile->setTitle(QCoreApplication::translate("stock_manager", "File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("stock_manager", "Help", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("stock_manager", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class stock_manager: public Ui_stock_manager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // STOCK_MANAGERKRBGSX_H
