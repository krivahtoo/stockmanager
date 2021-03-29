/********************************************************************************
** Form generated from reading UI file 'settingsxZbSef.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SETTINGSXZBSEF_H
#define SETTINGSXZBSEF_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dlgSettings
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QGroupBox *grpShop;
    QFormLayout *formLayout_2;
    QLabel *label_4;
    QLineEdit *txtName;
    QGroupBox *grpAdvance;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *chkDev_Mode;
    QGroupBox *grpPass;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *txtOld_Pass;
    QLabel *label_2;
    QLineEdit *txtNew_Pass;
    QLabel *label_3;
    QLineEdit *txtConfirm_Pass;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnChangePass;
    QLabel *label_8;
    QSpacerItem *verticalSpacer;
    QGroupBox *grpOther;
    QFormLayout *formLayout_3;
    QLabel *label_5;
    QComboBox *cmbTheme;
    QLabel *label_6;
    QLineEdit *txtDate_Format;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;

    void setupUi(QDialog *dlgSettings)
    {
        if (dlgSettings->objectName().isEmpty())
            dlgSettings->setObjectName(QString::fromUtf8("dlgSettings"));
        dlgSettings->resize(630, 303);
        verticalLayout = new QVBoxLayout(dlgSettings);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(dlgSettings);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        grpShop = new QGroupBox(groupBox);
        grpShop->setObjectName(QString::fromUtf8("grpShop"));
        formLayout_2 = new QFormLayout(grpShop);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_4 = new QLabel(grpShop);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_4);

        txtName = new QLineEdit(grpShop);
        txtName->setObjectName(QString::fromUtf8("txtName"));
        txtName->setMaximumSize(QSize(300, 16777215));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, txtName);


        gridLayout->addWidget(grpShop, 0, 0, 1, 1);

        grpAdvance = new QGroupBox(groupBox);
        grpAdvance->setObjectName(QString::fromUtf8("grpAdvance"));
        verticalLayout_2 = new QVBoxLayout(grpAdvance);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        chkDev_Mode = new QCheckBox(grpAdvance);
        chkDev_Mode->setObjectName(QString::fromUtf8("chkDev_Mode"));

        verticalLayout_2->addWidget(chkDev_Mode);


        gridLayout->addWidget(grpAdvance, 0, 1, 1, 1);

        grpPass = new QGroupBox(groupBox);
        grpPass->setObjectName(QString::fromUtf8("grpPass"));
        grpPass->setEnabled(false);
        formLayout = new QFormLayout(grpPass);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(grpPass);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        txtOld_Pass = new QLineEdit(grpPass);
        txtOld_Pass->setObjectName(QString::fromUtf8("txtOld_Pass"));
        txtOld_Pass->setMaximumSize(QSize(208, 16777215));
        txtOld_Pass->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(0, QFormLayout::FieldRole, txtOld_Pass);

        label_2 = new QLabel(grpPass);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        txtNew_Pass = new QLineEdit(grpPass);
        txtNew_Pass->setObjectName(QString::fromUtf8("txtNew_Pass"));
        txtNew_Pass->setMaximumSize(QSize(208, 16777215));
        txtNew_Pass->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, txtNew_Pass);

        label_3 = new QLabel(grpPass);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        txtConfirm_Pass = new QLineEdit(grpPass);
        txtConfirm_Pass->setObjectName(QString::fromUtf8("txtConfirm_Pass"));
        txtConfirm_Pass->setMaximumSize(QSize(208, 16777215));
        txtConfirm_Pass->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(2, QFormLayout::FieldRole, txtConfirm_Pass);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnChangePass = new QPushButton(grpPass);
        btnChangePass->setObjectName(QString::fromUtf8("btnChangePass"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/lock.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnChangePass->setIcon(icon);

        horizontalLayout->addWidget(btnChangePass);


        formLayout->setLayout(5, QFormLayout::SpanningRole, horizontalLayout);

        label_8 = new QLabel(grpPass);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout->setWidget(3, QFormLayout::SpanningRole, label_8);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(4, QFormLayout::LabelRole, verticalSpacer);


        gridLayout->addWidget(grpPass, 1, 0, 1, 1);

        grpOther = new QGroupBox(groupBox);
        grpOther->setObjectName(QString::fromUtf8("grpOther"));
        formLayout_3 = new QFormLayout(grpOther);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        label_5 = new QLabel(grpOther);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_5);

        cmbTheme = new QComboBox(grpOther);
        cmbTheme->addItem(QString());
        cmbTheme->setObjectName(QString::fromUtf8("cmbTheme"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, cmbTheme);

        label_6 = new QLabel(grpOther);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_6);

        txtDate_Format = new QLineEdit(grpOther);
        txtDate_Format->setObjectName(QString::fromUtf8("txtDate_Format"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, txtDate_Format);

        label_7 = new QLabel(grpOther);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout_3->setWidget(2, QFormLayout::SpanningRole, label_7);


        gridLayout->addWidget(grpOther, 1, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(30, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_3 = new QPushButton(dlgSettings);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMaximumSize(QSize(16777215, 30));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/cross.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon1);

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(dlgSettings);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/time-reverse.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon2);

        horizontalLayout_2->addWidget(pushButton_4);

        pushButton_2 = new QPushButton(dlgSettings);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(16777215, 30));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/gear.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon3);

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(dlgSettings);

        QMetaObject::connectSlotsByName(dlgSettings);
    } // setupUi

    void retranslateUi(QDialog *dlgSettings)
    {
        dlgSettings->setWindowTitle(QCoreApplication::translate("dlgSettings", "Settings", nullptr));
        groupBox->setTitle(QString());
        grpShop->setTitle(QCoreApplication::translate("dlgSettings", "Shop", nullptr));
        label_4->setText(QCoreApplication::translate("dlgSettings", "Shop Name:", nullptr));
        grpAdvance->setTitle(QCoreApplication::translate("dlgSettings", "Advance", nullptr));
        chkDev_Mode->setText(QCoreApplication::translate("dlgSettings", "Dev Mode", nullptr));
        grpPass->setTitle(QCoreApplication::translate("dlgSettings", "Change Password", nullptr));
        label->setText(QCoreApplication::translate("dlgSettings", "Old Password:", nullptr));
        label_2->setText(QCoreApplication::translate("dlgSettings", "New Password:", nullptr));
        label_3->setText(QCoreApplication::translate("dlgSettings", "Confirm Password:", nullptr));
        btnChangePass->setText(QCoreApplication::translate("dlgSettings", "Change Password", nullptr));
        label_8->setText(QCoreApplication::translate("dlgSettings", "Password used to encrypt the database", nullptr));
        grpOther->setTitle(QCoreApplication::translate("dlgSettings", "Other", nullptr));
        label_5->setText(QCoreApplication::translate("dlgSettings", "Change Theme:", nullptr));
        cmbTheme->setItemText(0, QCoreApplication::translate("dlgSettings", "Default", nullptr));

        label_6->setText(QCoreApplication::translate("dlgSettings", "Date Format:", nullptr));
        label_7->setText(QCoreApplication::translate("dlgSettings", "<html><head/><body><p>dd,DDD,dddd <span style=\" font-style:normal;\">for Date,</span><br/>MM, MMMM <span style=\" font-style:normal;\">for month,</span><br/>YY, yyyy <span style=\" font-style:normal;\">for year</span></p><p><span style=\" font-style:normal;\">Default </span>'ddd dd MMMM yyyy'</p></body></html>", nullptr));
        pushButton_3->setText(QCoreApplication::translate("dlgSettings", "Close", nullptr));
        pushButton_4->setText(QCoreApplication::translate("dlgSettings", "Reset", nullptr));
        pushButton_2->setText(QCoreApplication::translate("dlgSettings", "Save Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dlgSettings: public Ui_dlgSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SETTINGSXZBSEF_H
