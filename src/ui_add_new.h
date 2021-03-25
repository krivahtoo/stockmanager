/********************************************************************************
** Form generated from reading UI file 'add_newpTObST.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ADD_NEWPTOBST_H
#define ADD_NEWPTOBST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dlgAdd
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *lblId;
    QLineEdit *txtId;
    QLineEdit *txtName;
    QLabel *lblName;
    QLabel *lblQuantity;
    QSpinBox *spbQuantity;
    QLabel *lblPrice;
    QSpinBox *spbPrice;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSave;

    void setupUi(QDialog *dlgAdd)
    {
        if (dlgAdd->objectName().isEmpty())
            dlgAdd->setObjectName(QString::fromUtf8("dlgAdd"));
        dlgAdd->setWindowModality(Qt::WindowModal);
        dlgAdd->resize(414, 190);
        dlgAdd->setMinimumSize(QSize(0, 0));
        dlgAdd->setMaximumSize(QSize(41055, 25455));
        dlgAdd->setModal(true);
        verticalLayout = new QVBoxLayout(dlgAdd);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(dlgAdd);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        lblId = new QLabel(groupBox);
        lblId->setObjectName(QString::fromUtf8("lblId"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lblId);

        txtId = new QLineEdit(groupBox);
        txtId->setObjectName(QString::fromUtf8("txtId"));
        txtId->setMaximumSize(QSize(181, 16777215));

        formLayout->setWidget(0, QFormLayout::FieldRole, txtId);

        txtName = new QLineEdit(groupBox);
        txtName->setObjectName(QString::fromUtf8("txtName"));

        formLayout->setWidget(1, QFormLayout::FieldRole, txtName);

        lblName = new QLabel(groupBox);
        lblName->setObjectName(QString::fromUtf8("lblName"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lblName);

        lblQuantity = new QLabel(groupBox);
        lblQuantity->setObjectName(QString::fromUtf8("lblQuantity"));

        formLayout->setWidget(2, QFormLayout::LabelRole, lblQuantity);

        spbQuantity = new QSpinBox(groupBox);
        spbQuantity->setObjectName(QString::fromUtf8("spbQuantity"));
        spbQuantity->setMaximumSize(QSize(101, 16777215));
        spbQuantity->setMinimum(1);

        formLayout->setWidget(2, QFormLayout::FieldRole, spbQuantity);

        lblPrice = new QLabel(groupBox);
        lblPrice->setObjectName(QString::fromUtf8("lblPrice"));

        formLayout->setWidget(3, QFormLayout::LabelRole, lblPrice);

        spbPrice = new QSpinBox(groupBox);
        spbPrice->setObjectName(QString::fromUtf8("spbPrice"));
        spbPrice->setMaximumSize(QSize(141, 16777215));
        spbPrice->setMaximum(999999);
        spbPrice->setValue(0);

        formLayout->setWidget(3, QFormLayout::FieldRole, spbPrice);


        verticalLayout->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnCancel = new QPushButton(dlgAdd);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setMinimumSize(QSize(88, 26));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSave = new QPushButton(dlgAdd);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setMinimumSize(QSize(88, 26));

        horizontalLayout->addWidget(btnSave);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(dlgAdd);
        QObject::connect(btnCancel, SIGNAL(clicked()), dlgAdd, SLOT(reject()));

        btnSave->setDefault(true);


        QMetaObject::connectSlotsByName(dlgAdd);
    } // setupUi

    void retranslateUi(QDialog *dlgAdd)
    {
        dlgAdd->setWindowTitle(QCoreApplication::translate("dlgAdd", "Add New Item", nullptr));
        groupBox->setTitle(QCoreApplication::translate("dlgAdd", "Item", nullptr));
        lblId->setText(QCoreApplication::translate("dlgAdd", "Item Number / Id:", nullptr));
        lblName->setText(QCoreApplication::translate("dlgAdd", "Name:", nullptr));
        lblQuantity->setText(QCoreApplication::translate("dlgAdd", "Quantity:", nullptr));
        lblPrice->setText(QCoreApplication::translate("dlgAdd", "Price:", nullptr));
        spbPrice->setSuffix(QCoreApplication::translate("dlgAdd", ".00", nullptr));
        spbPrice->setPrefix(QCoreApplication::translate("dlgAdd", "Ksh. ", nullptr));
        btnCancel->setText(QCoreApplication::translate("dlgAdd", "Cancel", nullptr));
        btnSave->setText(QCoreApplication::translate("dlgAdd", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dlgAdd: public Ui_dlgAdd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ADD_NEWPTOBST_H
