/********************************************************************************
** Form generated from reading UI file 'searchokwJdl.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SEARCHOKWJDL_H
#define SEARCHOKWJDL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dlgSearch
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *txtSearch;
    QLabel *lblSearch;
    QWidget *wdgList;
    QVBoxLayout *verticalLayout_2;
    QListWidget *lstSearch;

    void setupUi(QDialog *dlgSearch)
    {
        if (dlgSearch->objectName().isEmpty())
            dlgSearch->setObjectName(QString::fromUtf8("dlgSearch"));
        dlgSearch->resize(473, 138);
        dlgSearch->setContextMenuPolicy(Qt::DefaultContextMenu);
        dlgSearch->setWindowOpacity(1.000000000000000);
        verticalLayout = new QVBoxLayout(dlgSearch);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        txtSearch = new QLineEdit(dlgSearch);
        txtSearch->setObjectName(QString::fromUtf8("txtSearch"));

        horizontalLayout->addWidget(txtSearch);

        lblSearch = new QLabel(dlgSearch);
        lblSearch->setObjectName(QString::fromUtf8("lblSearch"));

        horizontalLayout->addWidget(lblSearch);


        verticalLayout->addLayout(horizontalLayout);

        wdgList = new QWidget(dlgSearch);
        wdgList->setObjectName(QString::fromUtf8("wdgList"));
        wdgList->setMinimumSize(QSize(0, 0));
        verticalLayout_2 = new QVBoxLayout(wdgList);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lstSearch = new QListWidget(wdgList);
        lstSearch->setObjectName(QString::fromUtf8("lstSearch"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lstSearch->sizePolicy().hasHeightForWidth());
        lstSearch->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(lstSearch);


        verticalLayout->addWidget(wdgList);


        retranslateUi(dlgSearch);

        QMetaObject::connectSlotsByName(dlgSearch);
    } // setupUi

    void retranslateUi(QDialog *dlgSearch)
    {
        dlgSearch->setWindowTitle(QCoreApplication::translate("dlgSearch", "Search", nullptr));
        txtSearch->setPlaceholderText(QCoreApplication::translate("dlgSearch", "Search...", nullptr));
        lblSearch->setText(QCoreApplication::translate("dlgSearch", "Type to Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dlgSearch: public Ui_dlgSearch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SEARCHOKWJDL_H
