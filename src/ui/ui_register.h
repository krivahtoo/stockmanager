/********************************************************************************
** Form generated from reading UI file 'registerqRcRkJ.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef REGISTERQRCRKJ_H
#define REGISTERQRCRKJ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
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

class Ui_dlgRegister
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *lblAvatar;
    QPushButton *btnChangeAvatar;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *txtName;
    QLabel *label_2;
    QLineEdit *txtUsername;
    QLabel *label_3;
    QComboBox *cmbRole;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout_2;
    QLabel *label_6;
    QLabel *label_5;
    QLineEdit *txtPassword;
    QLineEdit *txtPasswordConfirm;
    QLabel *lblError;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnReset;
    QPushButton *btnRegister;

    void setupUi(QDialog *dlgRegister)
    {
        if (dlgRegister->objectName().isEmpty())
            dlgRegister->setObjectName(QString::fromUtf8("dlgRegister"));
        dlgRegister->resize(507, 299);
        verticalLayout_3 = new QVBoxLayout(dlgRegister);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox = new QGroupBox(dlgRegister);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lblAvatar = new QLabel(groupBox);
        lblAvatar->setObjectName(QString::fromUtf8("lblAvatar"));

        verticalLayout_2->addWidget(lblAvatar);

        btnChangeAvatar = new QPushButton(groupBox);
        btnChangeAvatar->setObjectName(QString::fromUtf8("btnChangeAvatar"));

        verticalLayout_2->addWidget(btnChangeAvatar);


        horizontalLayout_2->addLayout(verticalLayout_2);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        txtName = new QLineEdit(groupBox);
        txtName->setObjectName(QString::fromUtf8("txtName"));
        txtName->setMaximumSize(QSize(215, 16777215));

        formLayout->setWidget(0, QFormLayout::FieldRole, txtName);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        txtUsername = new QLineEdit(groupBox);
        txtUsername->setObjectName(QString::fromUtf8("txtUsername"));
        txtUsername->setMaximumSize(QSize(150, 16777215));

        formLayout->setWidget(1, QFormLayout::FieldRole, txtUsername);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        cmbRole = new QComboBox(groupBox);
        cmbRole->addItem(QString());
        cmbRole->addItem(QString());
        cmbRole->setObjectName(QString::fromUtf8("cmbRole"));
        cmbRole->setMaximumSize(QSize(130, 16777215));

        formLayout->setWidget(2, QFormLayout::FieldRole, cmbRole);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        formLayout_2 = new QFormLayout(groupBox_2);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_6);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_5);

        txtPassword = new QLineEdit(groupBox_2);
        txtPassword->setObjectName(QString::fromUtf8("txtPassword"));
        txtPassword->setMaximumSize(QSize(190, 16777215));
        txtPassword->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText|Qt::ImhSensitiveData);
        txtPassword->setEchoMode(QLineEdit::Password);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, txtPassword);

        txtPasswordConfirm = new QLineEdit(groupBox_2);
        txtPasswordConfirm->setObjectName(QString::fromUtf8("txtPasswordConfirm"));
        txtPasswordConfirm->setMaximumSize(QSize(190, 16777215));
        txtPasswordConfirm->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText|Qt::ImhSensitiveData);
        txtPasswordConfirm->setEchoMode(QLineEdit::Password);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, txtPasswordConfirm);


        formLayout->setWidget(3, QFormLayout::SpanningRole, groupBox_2);

        lblError = new QLabel(groupBox);
        lblError->setObjectName(QString::fromUtf8("lblError"));

        formLayout->setWidget(4, QFormLayout::SpanningRole, lblError);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(5, QFormLayout::SpanningRole, verticalSpacer);


        horizontalLayout_2->addLayout(formLayout);


        verticalLayout_3->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnCancel = new QPushButton(dlgRegister);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnReset = new QPushButton(dlgRegister);
        btnReset->setObjectName(QString::fromUtf8("btnReset"));

        horizontalLayout->addWidget(btnReset);

        btnRegister = new QPushButton(dlgRegister);
        btnRegister->setObjectName(QString::fromUtf8("btnRegister"));

        horizontalLayout->addWidget(btnRegister);


        verticalLayout_3->addLayout(horizontalLayout);


        retranslateUi(dlgRegister);
        QObject::connect(btnCancel, SIGNAL(clicked()), dlgRegister, SLOT(reject()));

        btnRegister->setDefault(true);


        QMetaObject::connectSlotsByName(dlgRegister);
    } // setupUi

    void retranslateUi(QDialog *dlgRegister)
    {
        dlgRegister->setWindowTitle(QCoreApplication::translate("dlgRegister", "Register", nullptr));
        groupBox->setTitle(QCoreApplication::translate("dlgRegister", "Register a new user", nullptr));
        lblAvatar->setText(QCoreApplication::translate("dlgRegister", "<html><head/><body><p><img src=\":/icons/user.svg\"/></p></body></html>", nullptr));
        btnChangeAvatar->setText(QCoreApplication::translate("dlgRegister", "Change Avatar", nullptr));
        label->setText(QCoreApplication::translate("dlgRegister", "Name", nullptr));
        txtName->setPlaceholderText(QCoreApplication::translate("dlgRegister", "e.g. John Doe", nullptr));
        label_2->setText(QCoreApplication::translate("dlgRegister", "Username", nullptr));
        txtUsername->setPlaceholderText(QCoreApplication::translate("dlgRegister", "e.g. jdoe", nullptr));
        label_3->setText(QCoreApplication::translate("dlgRegister", "Role", nullptr));
        cmbRole->setItemText(0, QCoreApplication::translate("dlgRegister", "User", nullptr));
        cmbRole->setItemText(1, QCoreApplication::translate("dlgRegister", "Admin", nullptr));

        cmbRole->setPlaceholderText(QCoreApplication::translate("dlgRegister", "Select role", nullptr));
        groupBox_2->setTitle(QString());
        label_6->setText(QCoreApplication::translate("dlgRegister", "Confirm Password", nullptr));
        label_5->setText(QCoreApplication::translate("dlgRegister", "Password", nullptr));
        txtPassword->setPlaceholderText(QCoreApplication::translate("dlgRegister", "Enter password...", nullptr));
        txtPasswordConfirm->setPlaceholderText(QCoreApplication::translate("dlgRegister", "Enter password...", nullptr));
        lblError->setText(QCoreApplication::translate("dlgRegister", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'JetBrainsMono Nerd Font'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; color:#ff0000;\">Password doesn't match</span></p></body></html>", nullptr));
        btnCancel->setText(QCoreApplication::translate("dlgRegister", "Cancel", nullptr));
        btnReset->setText(QCoreApplication::translate("dlgRegister", "Reset", nullptr));
        btnRegister->setText(QCoreApplication::translate("dlgRegister", "Register", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dlgRegister: public Ui_dlgRegister {};
} // namespace Ui

QT_END_NAMESPACE

#endif // REGISTERQRCRKJ_H
