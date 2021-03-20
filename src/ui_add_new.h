/********************************************************************************
** Form generated from reading UI file 'add_newfiqWNI.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ADD_NEWFIQWNI_H
#define ADD_NEWFIQWNI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_dlgAdd
{
public:
    QLineEdit *txtId;
    QLabel *lblId;
    QLabel *lblName;
    QLineEdit *txtName;
    QSpinBox *spbQuantity;
    QLabel *lblQuantity;
    QLabel *lblPrice;
    QPushButton *btnSave;
    QPushButton *btnCancel;
    QSpinBox *spbPrice;

    void setupUi(QDialog *dlgAdd)
    {
        if (dlgAdd->objectName().isEmpty())
            dlgAdd->setObjectName(QString::fromUtf8("dlgAdd"));
        dlgAdd->setWindowModality(Qt::WindowModal);
        dlgAdd->resize(400, 254);
        dlgAdd->setMinimumSize(QSize(400, 254));
        dlgAdd->setMaximumSize(QSize(400, 254));
        dlgAdd->setModal(true);
        txtId = new QLineEdit(dlgAdd);
        txtId->setObjectName(QString::fromUtf8("txtId"));
        txtId->setGeometry(QRect(160, 30, 181, 26));
        lblId = new QLabel(dlgAdd);
        lblId->setObjectName(QString::fromUtf8("lblId"));
        lblId->setGeometry(QRect(40, 30, 121, 20));
        lblName = new QLabel(dlgAdd);
        lblName->setObjectName(QString::fromUtf8("lblName"));
        lblName->setGeometry(QRect(40, 80, 58, 18));
        txtName = new QLineEdit(dlgAdd);
        txtName->setObjectName(QString::fromUtf8("txtName"));
        txtName->setGeometry(QRect(100, 70, 281, 31));
        spbQuantity = new QSpinBox(dlgAdd);
        spbQuantity->setObjectName(QString::fromUtf8("spbQuantity"));
        spbQuantity->setGeometry(QRect(110, 120, 101, 26));
        spbQuantity->setMinimum(1);
        lblQuantity = new QLabel(dlgAdd);
        lblQuantity->setObjectName(QString::fromUtf8("lblQuantity"));
        lblQuantity->setGeometry(QRect(40, 120, 61, 20));
        lblPrice = new QLabel(dlgAdd);
        lblPrice->setObjectName(QString::fromUtf8("lblPrice"));
        lblPrice->setGeometry(QRect(40, 160, 58, 18));
        btnSave = new QPushButton(dlgAdd);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setGeometry(QRect(290, 220, 88, 26));
        btnCancel = new QPushButton(dlgAdd);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(20, 220, 88, 26));
        spbPrice = new QSpinBox(dlgAdd);
        spbPrice->setObjectName(QString::fromUtf8("spbPrice"));
        spbPrice->setGeometry(QRect(100, 160, 141, 26));
        spbPrice->setMaximum(999999);
        spbPrice->setValue(0);

        retranslateUi(dlgAdd);
        QObject::connect(btnCancel, SIGNAL(clicked()), dlgAdd, SLOT(reject()));

        btnSave->setDefault(true);


        QMetaObject::connectSlotsByName(dlgAdd);
    } // setupUi

    void retranslateUi(QDialog *dlgAdd)
    {
        dlgAdd->setWindowTitle(QCoreApplication::translate("dlgAdd", "Add New Item", nullptr));
        lblId->setText(QCoreApplication::translate("dlgAdd", "Item Number / Id:", nullptr));
        lblName->setText(QCoreApplication::translate("dlgAdd", "Name:", nullptr));
        lblQuantity->setText(QCoreApplication::translate("dlgAdd", "Quantity:", nullptr));
        lblPrice->setText(QCoreApplication::translate("dlgAdd", "Price:", nullptr));
        btnSave->setText(QCoreApplication::translate("dlgAdd", "Save", nullptr));
        btnCancel->setText(QCoreApplication::translate("dlgAdd", "Cancel", nullptr));
        spbPrice->setSuffix(QCoreApplication::translate("dlgAdd", ".00", nullptr));
        spbPrice->setPrefix(QCoreApplication::translate("dlgAdd", "Ksh. ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dlgAdd: public Ui_dlgAdd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ADD_NEWFIQWNI_H
