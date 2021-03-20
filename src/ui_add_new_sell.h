/********************************************************************************
** Form generated from reading UI file 'add_new_sellZMdlkO.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ADD_NEW_SELLZMDLKO_H
#define ADD_NEW_SELLZMDLKO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_dlgAddNew
{
public:
    QPushButton *btnCancel;
    QPushButton *btnAdd;
    QSpinBox *spbQuantity;
    QLineEdit *txtId;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *dlgAddNew)
    {
        if (dlgAddNew->objectName().isEmpty())
            dlgAddNew->setObjectName(QString::fromUtf8("dlgAddNew"));
        dlgAddNew->setWindowModality(Qt::WindowModal);
        dlgAddNew->resize(318, 180);
        dlgAddNew->setModal(true);
        btnCancel = new QPushButton(dlgAddNew);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(20, 140, 88, 26));
        btnAdd = new QPushButton(dlgAddNew);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        btnAdd->setGeometry(QRect(210, 140, 88, 26));
        spbQuantity = new QSpinBox(dlgAddNew);
        spbQuantity->setObjectName(QString::fromUtf8("spbQuantity"));
        spbQuantity->setGeometry(QRect(130, 80, 71, 26));
        txtId = new QLineEdit(dlgAddNew);
        txtId->setObjectName(QString::fromUtf8("txtId"));
        txtId->setGeometry(QRect(120, 30, 141, 26));
        label = new QLabel(dlgAddNew);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 30, 58, 18));
        label_2 = new QLabel(dlgAddNew);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 80, 71, 18));

        retranslateUi(dlgAddNew);
        QObject::connect(btnCancel, SIGNAL(clicked()), dlgAddNew, SLOT(reject()));

        QMetaObject::connectSlotsByName(dlgAddNew);
    } // setupUi

    void retranslateUi(QDialog *dlgAddNew)
    {
        dlgAddNew->setWindowTitle(QCoreApplication::translate("dlgAddNew", "Add Item", nullptr));
        btnCancel->setText(QCoreApplication::translate("dlgAddNew", "Cancel", nullptr));
        btnAdd->setText(QCoreApplication::translate("dlgAddNew", "Add", nullptr));
        label->setText(QCoreApplication::translate("dlgAddNew", "Item Id:", nullptr));
        label_2->setText(QCoreApplication::translate("dlgAddNew", "Quantity:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dlgAddNew: public Ui_dlgAddNew {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ADD_NEW_SELLZMDLKO_H
