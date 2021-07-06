/********************************************************************************
** Form generated from reading UI file 'loginXGRWaj.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef LOGINXGRWAJ_H
#define LOGINXGRWAJ_H

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
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dlgLogin
{
public:
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *txtUsername;
    QLabel *label_2;
    QLineEdit *txtPassword;
    QLabel *lblInfo;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnCancel;
    QPushButton *btnLogin;

    void setupUi(QDialog *dlgLogin)
    {
        if (dlgLogin->objectName().isEmpty())
            dlgLogin->setObjectName(QString::fromUtf8("dlgLogin"));
        dlgLogin->resize(485, 238);
        horizontalLayout_2 = new QHBoxLayout(dlgLogin);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(dlgLogin);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        groupBox = new QGroupBox(dlgLogin);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(16777215, 22));

        verticalLayout->addWidget(label_3);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        txtUsername = new QLineEdit(groupBox);
        txtUsername->setObjectName(QString::fromUtf8("txtUsername"));

        formLayout->setWidget(0, QFormLayout::FieldRole, txtUsername);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        txtPassword = new QLineEdit(groupBox);
        txtPassword->setObjectName(QString::fromUtf8("txtPassword"));
        txtPassword->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, txtPassword);


        verticalLayout->addLayout(formLayout);

        lblInfo = new QLabel(groupBox);
        lblInfo->setObjectName(QString::fromUtf8("lblInfo"));

        verticalLayout->addWidget(lblInfo);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnCancel = new QPushButton(groupBox);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(btnCancel);

        btnLogin = new QPushButton(groupBox);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));
        btnLogin->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(btnLogin);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout_2->addWidget(groupBox);


        retranslateUi(dlgLogin);
        QObject::connect(btnCancel, SIGNAL(clicked()), dlgLogin, SLOT(reject()));

        btnLogin->setDefault(true);


        QMetaObject::connectSlotsByName(dlgLogin);
    } // setupUi

    void retranslateUi(QDialog *dlgLogin)
    {
        dlgLogin->setWindowTitle(QCoreApplication::translate("dlgLogin", "Login", nullptr));
        label_4->setText(QCoreApplication::translate("dlgLogin", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">Stock Manager</span></p><p><img src=\":/images/logo-small.svg\" width=\"150\" height=\"150\"/></p></body></html>", nullptr));
        groupBox->setTitle(QCoreApplication::translate("dlgLogin", "Login", nullptr));
        label_3->setText(QCoreApplication::translate("dlgLogin", "Please login to access the system", nullptr));
        label->setText(QCoreApplication::translate("dlgLogin", "Username:", nullptr));
        label_2->setText(QCoreApplication::translate("dlgLogin", "Password:", nullptr));
        lblInfo->setText(QString());
        btnCancel->setText(QCoreApplication::translate("dlgLogin", "Cancel", nullptr));
        btnLogin->setText(QCoreApplication::translate("dlgLogin", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dlgLogin: public Ui_dlgLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // LOGINXGRWAJ_H
