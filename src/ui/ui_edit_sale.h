/********************************************************************************
** Form generated from reading UI file 'edit_saleyWpAnY.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef EDIT_SALEYWPANY_H
#define EDIT_SALEYWPANY_H

#include <QtCore/QVariant>
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
    QLineEdit *lineEdit;
    QLabel *label_2;
    QSpinBox *spinBox;
    QLabel *label_3;
    QComboBox *comboBox;
    QLabel *label_4;
    QDateTimeEdit *dateTimeEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;

    void setupUi(QDialog *dlgEdit_Sale)
    {
        if (dlgEdit_Sale->objectName().isEmpty())
            dlgEdit_Sale->setObjectName(QString::fromUtf8("dlgEdit_Sale"));
        dlgEdit_Sale->resize(335, 166);
        verticalLayout = new QVBoxLayout(dlgEdit_Sale);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(dlgEdit_Sale);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximumSize(QSize(84, 16777215));

        formLayout->setWidget(1, QFormLayout::FieldRole, spinBox);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        comboBox = new QComboBox(groupBox);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMaximumSize(QSize(100, 16777215));

        formLayout->setWidget(2, QFormLayout::FieldRole, comboBox);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        dateTimeEdit = new QDateTimeEdit(groupBox);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, dateTimeEdit);


        verticalLayout->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(dlgEdit_Sale);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(dlgEdit_Sale);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(dlgEdit_Sale);

        QMetaObject::connectSlotsByName(dlgEdit_Sale);
    } // setupUi

    void retranslateUi(QDialog *dlgEdit_Sale)
    {
        dlgEdit_Sale->setWindowTitle(QCoreApplication::translate("dlgEdit_Sale", "Edit Sale", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("dlgEdit_Sale", "Item Id:", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("dlgEdit_Sale", "Enter item id...", nullptr));
        label_2->setText(QCoreApplication::translate("dlgEdit_Sale", "Quantity:", nullptr));
        label_3->setText(QCoreApplication::translate("dlgEdit_Sale", "Payment Method:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("dlgEdit_Sale", "Cash", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("dlgEdit_Sale", "Mpesa", nullptr));

        comboBox->setCurrentText(QCoreApplication::translate("dlgEdit_Sale", "Cash", nullptr));
        comboBox->setPlaceholderText(QString());
        label_4->setText(QCoreApplication::translate("dlgEdit_Sale", "Sale Date:", nullptr));
        pushButton->setText(QCoreApplication::translate("dlgEdit_Sale", "Cancel", nullptr));
        pushButton_2->setText(QCoreApplication::translate("dlgEdit_Sale", "Update", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dlgEdit_Sale: public Ui_dlgEdit_Sale {};
} // namespace Ui

QT_END_NAMESPACE

#endif // EDIT_SALEYWPANY_H
