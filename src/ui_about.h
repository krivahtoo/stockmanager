/********************************************************************************
** Form generated from reading UI file 'aboutqFMpQC.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ABOUTQFMPQC_H
#define ABOUTQFMPQC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_dlgAbout
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *dlgAbout)
    {
        if (dlgAbout->objectName().isEmpty())
            dlgAbout->setObjectName(QString::fromUtf8("dlgAbout"));
        dlgAbout->setWindowModality(Qt::WindowModal);
        dlgAbout->resize(336, 141);
        label = new QLabel(dlgAbout);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 10, 201, 91));
        label->setTextFormat(Qt::RichText);
        label->setWordWrap(true);
        pushButton = new QPushButton(dlgAbout);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(240, 100, 71, 26));

        retranslateUi(dlgAbout);
        QObject::connect(pushButton, SIGNAL(clicked()), dlgAbout, SLOT(accept()));

        QMetaObject::connectSlotsByName(dlgAbout);
    } // setupUi

    void retranslateUi(QDialog *dlgAbout)
    {
        dlgAbout->setWindowTitle(QCoreApplication::translate("dlgAbout", "About", nullptr));
        label->setText(QCoreApplication::translate("dlgAbout", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Stock Manager</span></p><p>Manage stock on your shop</p><p><span style=\" font-style:italic;\">(C) Noah Too</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("dlgAbout", "Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dlgAbout: public Ui_dlgAbout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ABOUTQFMPQC_H
