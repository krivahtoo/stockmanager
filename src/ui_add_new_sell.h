/********************************************************************************
** Form generated from reading UI file 'add_new_sellzlQzrd.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ADD_NEW_SELLZLQZRD_H
#define ADD_NEW_SELLZLQZRD_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
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

class Ui_dlgAddNew
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *txtId;
    QLabel *label_2;
    QSpinBox *spbQuantity;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnAdd;

    void setupUi(QDialog *dlgAddNew)
    {
        if (dlgAddNew->objectName().isEmpty())
            dlgAddNew->setObjectName(QString::fromUtf8("dlgAddNew"));
        dlgAddNew->setWindowModality(Qt::WindowModal);
        dlgAddNew->resize(321, 145);
        dlgAddNew->setModal(true);
        verticalLayout = new QVBoxLayout(dlgAddNew);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(dlgAddNew);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        txtId = new QLineEdit(groupBox);
        txtId->setObjectName(QString::fromUtf8("txtId"));
        txtId->setMaximumSize(QSize(226, 16777215));

        formLayout->setWidget(0, QFormLayout::FieldRole, txtId);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        spbQuantity = new QSpinBox(groupBox);
        spbQuantity->setObjectName(QString::fromUtf8("spbQuantity"));
        spbQuantity->setMaximumSize(QSize(75, 16777215));

        formLayout->setWidget(1, QFormLayout::FieldRole, spbQuantity);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(2, QFormLayout::FieldRole, verticalSpacer);


        verticalLayout->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        btnCancel = new QPushButton(dlgAddNew);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setMinimumSize(QSize(88, 26));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/cross.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnCancel->setIcon(icon);

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnAdd = new QPushButton(dlgAddNew);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        btnAdd->setMinimumSize(QSize(88, 26));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/cart.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnAdd->setIcon(icon1);

        horizontalLayout->addWidget(btnAdd);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(dlgAddNew);
        QObject::connect(btnCancel, SIGNAL(clicked()), dlgAddNew, SLOT(reject()));

        QMetaObject::connectSlotsByName(dlgAddNew);
    } // setupUi

    void retranslateUi(QDialog *dlgAddNew)
    {
        dlgAddNew->setWindowTitle(QCoreApplication::translate("dlgAddNew", "Add Item to Cart", nullptr));
        groupBox->setTitle(QCoreApplication::translate("dlgAddNew", "Item", nullptr));
        label->setText(QCoreApplication::translate("dlgAddNew", "Item Id:", nullptr));
        label_2->setText(QCoreApplication::translate("dlgAddNew", "Quantity:", nullptr));
        btnCancel->setText(QCoreApplication::translate("dlgAddNew", "Cancel", nullptr));
        btnAdd->setText(QCoreApplication::translate("dlgAddNew", "Add to Cart", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dlgAddNew: public Ui_dlgAddNew {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ADD_NEW_SELLZLQZRD_H
