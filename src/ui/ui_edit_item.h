/********************************************************************************
** Form generated from reading UI file 'edit_itemMyxhFt.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef EDIT_ITEMMYXHFT_H
#define EDIT_ITEMMYXHFT_H

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

class Ui_dlgEdit
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *formGroupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *txtId;
    QLabel *label_2;
    QLineEdit *txtName;
    QLabel *label_3;
    QSpinBox *spnBuyingPrice;
    QLabel *label_4;
    QSpinBox *spnSellingPrice;
    QLabel *label_5;
    QSpinBox *spnMinimumSellingPrice;
    QSpacerItem *verticalSpacer;
    QSpinBox *spnQuantity;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnUpdate;

    void setupUi(QDialog *dlgEdit)
    {
        if (dlgEdit->objectName().isEmpty())
            dlgEdit->setObjectName(QString::fromUtf8("dlgEdit"));
        dlgEdit->resize(388, 226);
        verticalLayout = new QVBoxLayout(dlgEdit);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formGroupBox = new QGroupBox(dlgEdit);
        formGroupBox->setObjectName(QString::fromUtf8("formGroupBox"));
        formLayout = new QFormLayout(formGroupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(formGroupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        txtId = new QLineEdit(formGroupBox);
        txtId->setObjectName(QString::fromUtf8("txtId"));
        txtId->setMaximumSize(QSize(178, 16777215));

        formLayout->setWidget(0, QFormLayout::FieldRole, txtId);

        label_2 = new QLabel(formGroupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        txtName = new QLineEdit(formGroupBox);
        txtName->setObjectName(QString::fromUtf8("txtName"));

        formLayout->setWidget(1, QFormLayout::FieldRole, txtName);

        label_3 = new QLabel(formGroupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        spnBuyingPrice = new QSpinBox(formGroupBox);
        spnBuyingPrice->setObjectName(QString::fromUtf8("spnBuyingPrice"));
        spnBuyingPrice->setMaximumSize(QSize(130, 16777215));
        spnBuyingPrice->setMaximum(9999);

        formLayout->setWidget(3, QFormLayout::FieldRole, spnBuyingPrice);

        label_4 = new QLabel(formGroupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        spnSellingPrice = new QSpinBox(formGroupBox);
        spnSellingPrice->setObjectName(QString::fromUtf8("spnSellingPrice"));
        spnSellingPrice->setMaximumSize(QSize(130, 16777215));
        spnSellingPrice->setMaximum(9999);

        formLayout->setWidget(4, QFormLayout::FieldRole, spnSellingPrice);

        label_5 = new QLabel(formGroupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        spnMinimumSellingPrice = new QSpinBox(formGroupBox);
        spnMinimumSellingPrice->setObjectName(QString::fromUtf8("spnMinimumSellingPrice"));
        spnMinimumSellingPrice->setMaximumSize(QSize(130, 16777215));
        spnMinimumSellingPrice->setMaximum(9999);

        formLayout->setWidget(5, QFormLayout::FieldRole, spnMinimumSellingPrice);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(8, QFormLayout::SpanningRole, verticalSpacer);

        spnQuantity = new QSpinBox(formGroupBox);
        spnQuantity->setObjectName(QString::fromUtf8("spnQuantity"));
        spnQuantity->setMaximumSize(QSize(90, 16777215));
        spnQuantity->setMaximum(9999);

        formLayout->setWidget(2, QFormLayout::FieldRole, spnQuantity);

        label_6 = new QLabel(formGroupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_6);


        verticalLayout->addWidget(formGroupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnCancel = new QPushButton(dlgEdit);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/cross.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnCancel->setIcon(icon);

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnUpdate = new QPushButton(dlgEdit);
        btnUpdate->setObjectName(QString::fromUtf8("btnUpdate"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/clockwise.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnUpdate->setIcon(icon1);

        horizontalLayout->addWidget(btnUpdate);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(dlgEdit);
        QObject::connect(btnCancel, SIGNAL(clicked()), dlgEdit, SLOT(reject()));

        QMetaObject::connectSlotsByName(dlgEdit);
    } // setupUi

    void retranslateUi(QDialog *dlgEdit)
    {
        dlgEdit->setWindowTitle(QCoreApplication::translate("dlgEdit", "Edit Item", nullptr));
        formGroupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("dlgEdit", "Item Id:", nullptr));
        txtId->setPlaceholderText(QCoreApplication::translate("dlgEdit", "Enter Item's Id...", nullptr));
        label_2->setText(QCoreApplication::translate("dlgEdit", "Name:", nullptr));
        txtName->setPlaceholderText(QCoreApplication::translate("dlgEdit", "Enter Item's Name", nullptr));
        label_3->setText(QCoreApplication::translate("dlgEdit", "Buying Price:", nullptr));
        spnBuyingPrice->setSuffix(QCoreApplication::translate("dlgEdit", ".00", nullptr));
        spnBuyingPrice->setPrefix(QCoreApplication::translate("dlgEdit", "Ksh ", nullptr));
        label_4->setText(QCoreApplication::translate("dlgEdit", "Selling Price:", nullptr));
        spnSellingPrice->setSuffix(QCoreApplication::translate("dlgEdit", ".00", nullptr));
        spnSellingPrice->setPrefix(QCoreApplication::translate("dlgEdit", "Ksh ", nullptr));
        label_5->setText(QCoreApplication::translate("dlgEdit", "Minimum Selling Price:", nullptr));
        spnMinimumSellingPrice->setSuffix(QCoreApplication::translate("dlgEdit", ".00", nullptr));
        spnMinimumSellingPrice->setPrefix(QCoreApplication::translate("dlgEdit", "Ksh ", nullptr));
        label_6->setText(QCoreApplication::translate("dlgEdit", "Quantity:", nullptr));
        btnCancel->setText(QCoreApplication::translate("dlgEdit", "Cancel", nullptr));
        btnUpdate->setText(QCoreApplication::translate("dlgEdit", "Update", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dlgEdit: public Ui_dlgEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // EDIT_ITEMMYXHFT_H
