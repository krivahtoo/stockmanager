/********************************************************************************
** Form generated from reading UI file 'edit_itemAxFtJc.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef EDIT_ITEMAXFTJC_H
#define EDIT_ITEMAXFTJC_H

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
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QSpinBox *spinBox;
    QLabel *label_4;
    QSpinBox *spinBox_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnUpdate;

    void setupUi(QDialog *dlgEdit)
    {
        if (dlgEdit->objectName().isEmpty())
            dlgEdit->setObjectName(QString::fromUtf8("dlgEdit"));
        dlgEdit->resize(389, 224);
        verticalLayout = new QVBoxLayout(dlgEdit);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formGroupBox = new QGroupBox(dlgEdit);
        formGroupBox->setObjectName(QString::fromUtf8("formGroupBox"));
        formLayout = new QFormLayout(formGroupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(formGroupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit = new QLineEdit(formGroupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMaximumSize(QSize(178, 16777215));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        label_2 = new QLabel(formGroupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        lineEdit_2 = new QLineEdit(formGroupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_2);

        label_3 = new QLabel(formGroupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        spinBox = new QSpinBox(formGroupBox);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximumSize(QSize(136, 16777215));

        formLayout->setWidget(2, QFormLayout::FieldRole, spinBox);

        label_4 = new QLabel(formGroupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        spinBox_2 = new QSpinBox(formGroupBox);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setMaximumSize(QSize(136, 16777215));

        formLayout->setWidget(3, QFormLayout::FieldRole, spinBox_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(4, QFormLayout::SpanningRole, verticalSpacer);


        verticalLayout->addWidget(formGroupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(dlgEdit);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/cross.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);

        horizontalLayout->addWidget(pushButton);

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
        QObject::connect(pushButton, SIGNAL(clicked()), dlgEdit, SLOT(reject()));

        QMetaObject::connectSlotsByName(dlgEdit);
    } // setupUi

    void retranslateUi(QDialog *dlgEdit)
    {
        dlgEdit->setWindowTitle(QCoreApplication::translate("dlgEdit", "Edit Item", nullptr));
        formGroupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("dlgEdit", "Item Id:", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("dlgEdit", "Enter Item's Id...", nullptr));
        label_2->setText(QCoreApplication::translate("dlgEdit", "Name:", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("dlgEdit", "Enter Item's Name", nullptr));
        label_3->setText(QCoreApplication::translate("dlgEdit", "Buing Price:", nullptr));
        label_4->setText(QCoreApplication::translate("dlgEdit", "Selling Price:", nullptr));
        pushButton->setText(QCoreApplication::translate("dlgEdit", "Cancel", nullptr));
        btnUpdate->setText(QCoreApplication::translate("dlgEdit", "Update", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dlgEdit: public Ui_dlgEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // EDIT_ITEMAXFTJC_H
