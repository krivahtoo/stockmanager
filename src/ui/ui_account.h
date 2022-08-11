/********************************************************************************
** Form generated from reading UI file 'accountKBcbPI.ui'
**
** Created by: Qt User Interface Compiler version 5.15.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ACCOUNTKBCBPI_H
#define ACCOUNTKBCBPI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dlgAccount
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *lblName;
    QLabel *lblUsername;
    QLabel *lblRole;
    QLabel *label_8;
    QLabel *lblId;
    QLabel *label_10;
    QLabel *lblLastLogin;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QDialog *dlgAccount)
    {
        if (dlgAccount->objectName().isEmpty())
            dlgAccount->setObjectName(QString::fromUtf8("dlgAccount"));
        dlgAccount->resize(425, 179);
        verticalLayout = new QVBoxLayout(dlgAccount);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(dlgAccount);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(label);

        groupBox = new QGroupBox(dlgAccount);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        lblName = new QLabel(groupBox);
        lblName->setObjectName(QString::fromUtf8("lblName"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lblName);

        lblUsername = new QLabel(groupBox);
        lblUsername->setObjectName(QString::fromUtf8("lblUsername"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lblUsername);

        lblRole = new QLabel(groupBox);
        lblRole->setObjectName(QString::fromUtf8("lblRole"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lblRole);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_8);

        lblId = new QLabel(groupBox);
        lblId->setObjectName(QString::fromUtf8("lblId"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lblId);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_10);

        lblLastLogin = new QLabel(groupBox);
        lblLastLogin->setObjectName(QString::fromUtf8("lblLastLogin"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lblLastLogin);


        gridLayout->addLayout(formLayout, 0, 1, 1, 1);


        horizontalLayout->addWidget(groupBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton = new QPushButton(dlgAccount);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(dlgAccount);
        QObject::connect(pushButton, SIGNAL(clicked()), dlgAccount, SLOT(accept()));

        QMetaObject::connectSlotsByName(dlgAccount);
    } // setupUi

    void retranslateUi(QDialog *dlgAccount)
    {
        dlgAccount->setWindowTitle(QCoreApplication::translate("dlgAccount", "Account", nullptr));
        label->setText(QCoreApplication::translate("dlgAccount", "<html><head/><body><p><img src=\":/icons/user.svg\"/></p></body></html>", nullptr));
        groupBox->setTitle(QString());
        label_2->setText(QCoreApplication::translate("dlgAccount", "Name:", nullptr));
        label_3->setText(QCoreApplication::translate("dlgAccount", "Role:", nullptr));
        label_4->setText(QCoreApplication::translate("dlgAccount", "Username:", nullptr));
        lblName->setText(QCoreApplication::translate("dlgAccount", "-", nullptr));
        lblUsername->setText(QCoreApplication::translate("dlgAccount", "-", nullptr));
        lblRole->setText(QCoreApplication::translate("dlgAccount", "-", nullptr));
        label_8->setText(QCoreApplication::translate("dlgAccount", "Id:", nullptr));
        lblId->setText(QCoreApplication::translate("dlgAccount", "-", nullptr));
        label_10->setText(QCoreApplication::translate("dlgAccount", "Last Login:", nullptr));
        lblLastLogin->setText(QCoreApplication::translate("dlgAccount", "-", nullptr));
        pushButton->setText(QCoreApplication::translate("dlgAccount", "Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dlgAccount: public Ui_dlgAccount {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ACCOUNTKBCBPI_H
