/********************************************************************************
** Form generated from reading UI file 'sell_itemspDAiKr.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SELL_ITEMSPDAIKR_H
#define SELL_ITEMSPDAIKR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dlgSell
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tblItems;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblTotal;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnNew;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnDone;

    void setupUi(QDialog *dlgSell)
    {
        if (dlgSell->objectName().isEmpty())
            dlgSell->setObjectName(QString::fromUtf8("dlgSell"));
        dlgSell->setWindowModality(Qt::WindowModal);
        dlgSell->resize(618, 320);
        dlgSell->setModal(true);
        verticalLayout = new QVBoxLayout(dlgSell);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tblItems = new QTableWidget(dlgSell);
        if (tblItems->columnCount() < 4)
            tblItems->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setText(QString::fromUtf8("Item Id"));
        tblItems->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblItems->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblItems->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblItems->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tblItems->setObjectName(QString::fromUtf8("tblItems"));

        verticalLayout->addWidget(tblItems);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lblTotal = new QLabel(dlgSell);
        lblTotal->setObjectName(QString::fromUtf8("lblTotal"));
        lblTotal->setText(QString::fromUtf8("Total: Ksh. 28904"));

        horizontalLayout_2->addWidget(lblTotal);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        btnNew = new QPushButton(dlgSell);
        btnNew->setObjectName(QString::fromUtf8("btnNew"));
        btnNew->setMinimumSize(QSize(88, 26));
        btnNew->setMaximumSize(QSize(88, 26));

        horizontalLayout_2->addWidget(btnNew);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnCancel = new QPushButton(dlgSell);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setMinimumSize(QSize(101, 31));
        btnCancel->setMaximumSize(QSize(101, 31));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnDone = new QPushButton(dlgSell);
        btnDone->setObjectName(QString::fromUtf8("btnDone"));
        btnDone->setMinimumSize(QSize(101, 31));
        btnDone->setMaximumSize(QSize(101, 31));

        horizontalLayout->addWidget(btnDone);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(dlgSell);
        QObject::connect(btnCancel, SIGNAL(clicked()), dlgSell, SLOT(reject()));

        QMetaObject::connectSlotsByName(dlgSell);
    } // setupUi

    void retranslateUi(QDialog *dlgSell)
    {
        dlgSell->setWindowTitle(QCoreApplication::translate("dlgSell", "Sell Items", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblItems->horizontalHeaderItem(1);
        ___qtablewidgetitem->setText(QCoreApplication::translate("dlgSell", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblItems->horizontalHeaderItem(2);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("dlgSell", "Quantity", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblItems->horizontalHeaderItem(3);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("dlgSell", "Price", nullptr));
        btnNew->setText(QCoreApplication::translate("dlgSell", "Add Item", nullptr));
        btnCancel->setText(QCoreApplication::translate("dlgSell", "Cancel", nullptr));
        btnDone->setText(QCoreApplication::translate("dlgSell", "Done", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dlgSell: public Ui_dlgSell {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SELL_ITEMSPDAIKR_H
