/********************************************************************************
** Form generated from reading UI file 'searchxGDBZn.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SEARCHXGDBZN_H
#define SEARCHXGDBZN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dlgSearch
{
public:
    QVBoxLayout *vtlSearch;
    QHBoxLayout *horizontalLayout;
    QLineEdit *txtSearch;
    QLabel *lblSearch;

    void setupUi(QDialog *dlgSearch)
    {
        if (dlgSearch->objectName().isEmpty())
            dlgSearch->setObjectName(QString::fromUtf8("dlgSearch"));
        dlgSearch->resize(578, 36);
        dlgSearch->setContextMenuPolicy(Qt::DefaultContextMenu);
        dlgSearch->setWindowOpacity(1.000000000000000);
        vtlSearch = new QVBoxLayout(dlgSearch);
        vtlSearch->setObjectName(QString::fromUtf8("vtlSearch"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        txtSearch = new QLineEdit(dlgSearch);
        txtSearch->setObjectName(QString::fromUtf8("txtSearch"));

        horizontalLayout->addWidget(txtSearch);

        lblSearch = new QLabel(dlgSearch);
        lblSearch->setObjectName(QString::fromUtf8("lblSearch"));

        horizontalLayout->addWidget(lblSearch);


        vtlSearch->addLayout(horizontalLayout);


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

#endif // SEARCHXGDBZN_H
