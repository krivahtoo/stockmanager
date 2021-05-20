/********************************************************************************
** Form generated from reading UI file 'edit_saleFfFKQi.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef EDIT_SALEFFFKQI_H
#define EDIT_SALEFFFKQI_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
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

class Ui_dlgEdit_Sale
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *txtId;
    QLabel *label_2;
    QSpinBox *spnQuantity;
    QLabel *label_3;
    QComboBox *cmbPayment_Method;
    QLabel *label_4;
    QDateTimeEdit *dateTimeSale;
    QLabel *label_5;
    QSpinBox *spnSale_Price;
    QLabel *label_6;
    QLabel *lblId;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnUpdate;

    void setupUi(QDialog *dlgEdit_Sale)
    {
        if (dlgEdit_Sale->objectName().isEmpty())
            dlgEdit_Sale->setObjectName(QString::fromUtf8("dlgEdit_Sale"));
        dlgEdit_Sale->setWindowModality(Qt::WindowModal);
        dlgEdit_Sale->resize(335, 234);
        verticalLayout = new QVBoxLayout(dlgEdit_Sale);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(dlgEdit_Sale);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        txtId = new QLineEdit(groupBox);
        txtId->setObjectName(QString::fromUtf8("txtId"));

        formLayout->setWidget(1, QFormLayout::FieldRole, txtId);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        spnQuantity = new QSpinBox(groupBox);
        spnQuantity->setObjectName(QString::fromUtf8("spnQuantity"));
        spnQuantity->setMaximumSize(QSize(84, 16777215));
        spnQuantity->setMinimum(1);
        spnQuantity->setMaximum(9999);

        formLayout->setWidget(2, QFormLayout::FieldRole, spnQuantity);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        cmbPayment_Method = new QComboBox(groupBox);
        cmbPayment_Method->addItem(QString());
        cmbPayment_Method->addItem(QString());
        cmbPayment_Method->setObjectName(QString::fromUtf8("cmbPayment_Method"));
        cmbPayment_Method->setMaximumSize(QSize(100, 16777215));

        formLayout->setWidget(3, QFormLayout::FieldRole, cmbPayment_Method);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_4);

        dateTimeSale = new QDateTimeEdit(groupBox);
        dateTimeSale->setObjectName(QString::fromUtf8("dateTimeSale"));

        formLayout->setWidget(5, QFormLayout::FieldRole, dateTimeSale);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        spnSale_Price = new QSpinBox(groupBox);
        spnSale_Price->setObjectName(QString::fromUtf8("spnSale_Price"));
        spnSale_Price->setMaximum(99999);

        formLayout->setWidget(4, QFormLayout::FieldRole, spnSale_Price);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_6);

        lblId = new QLabel(groupBox);
        lblId->setObjectName(QString::fromUtf8("lblId"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lblId);


        verticalLayout->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnCancel = new QPushButton(dlgEdit_Sale);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/cross.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnCancel->setIcon(icon);

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnUpdate = new QPushButton(dlgEdit_Sale);
        btnUpdate->setObjectName(QString::fromUtf8("btnUpdate"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/clockwise.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnUpdate->setIcon(icon1);

        horizontalLayout->addWidget(btnUpdate);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(dlgEdit_Sale);
        QObject::connect(btnCancel, SIGNAL(clicked()), dlgEdit_Sale, SLOT(reject()));

        QMetaObject::connectSlotsByName(dlgEdit_Sale);
    } // setupUi

    void retranslateUi(QDialog *dlgEdit_Sale)
    {
        dlgEdit_Sale->setWindowTitle(QCoreApplication::translate("dlgEdit_Sale", "Edit Sale", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("dlgEdit_Sale", "Item Id:", nullptr));
        txtId->setPlaceholderText(QCoreApplication::translate("dlgEdit_Sale", "Enter item id...", nullptr));
        label_2->setText(QCoreApplication::translate("dlgEdit_Sale", "Quantity:", nullptr));
        label_3->setText(QCoreApplication::translate("dlgEdit_Sale", "Payment Method:", nullptr));
        cmbPayment_Method->setItemText(0, QCoreApplication::translate("dlgEdit_Sale", "Cash", nullptr));
        cmbPayment_Method->setItemText(1, QCoreApplication::translate("dlgEdit_Sale", "Mpesa", nullptr));

        cmbPayment_Method->setCurrentText(QCoreApplication::translate("dlgEdit_Sale", "Cash", nullptr));
        cmbPayment_Method->setPlaceholderText(QString());
        label_4->setText(QCoreApplication::translate("dlgEdit_Sale", "Sale Date:", nullptr));
        label_5->setText(QCoreApplication::translate("dlgEdit_Sale", "Sell Price:", nullptr));
        spnSale_Price->setSuffix(QCoreApplication::translate("dlgEdit_Sale", ".00", nullptr));
        spnSale_Price->setPrefix(QCoreApplication::translate("dlgEdit_Sale", "Ksh. ", nullptr));
        label_6->setText(QCoreApplication::translate("dlgEdit_Sale", "Id:", nullptr));
        lblId->setText(QString());
        btnCancel->setText(QCoreApplication::translate("dlgEdit_Sale", "Cancel", nullptr));
        btnUpdate->setText(QCoreApplication::translate("dlgEdit_Sale", "Update", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dlgEdit_Sale: public Ui_dlgEdit_Sale {};
} // namespace Ui

QT_END_NAMESPACE

#endif // EDIT_SALEFFFKQI_H
