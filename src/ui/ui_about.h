/********************************************************************************
** Form generated from reading UI file 'aboutqjErIv.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ABOUTQJERIV_H
#define ABOUTQJERIV_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dlgAbout
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QDialog *dlgAbout)
    {
        if (dlgAbout->objectName().isEmpty())
            dlgAbout->setObjectName(QString::fromUtf8("dlgAbout"));
        dlgAbout->setWindowModality(Qt::WindowModal);
        dlgAbout->resize(399, 165);
        dlgAbout->setModal(true);
        verticalLayout = new QVBoxLayout(dlgAbout);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(dlgAbout);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(114, 16777215));

        horizontalLayout_2->addWidget(label_2);

        label = new QLabel(dlgAbout);
        label->setObjectName(QString::fromUtf8("label"));
        label->setTextFormat(Qt::RichText);
        label->setWordWrap(true);

        horizontalLayout_2->addWidget(label);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(dlgAbout);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(71, 26));
        pushButton->setMaximumSize(QSize(71, 26));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(dlgAbout);
        QObject::connect(pushButton, SIGNAL(clicked()), dlgAbout, SLOT(accept()));

        QMetaObject::connectSlotsByName(dlgAbout);
    } // setupUi

    void retranslateUi(QDialog *dlgAbout)
    {
        dlgAbout->setWindowTitle(QCoreApplication::translate("dlgAbout", "About", nullptr));
        label_2->setText(QCoreApplication::translate("dlgAbout", "<html>\n"
"<head/><body>\n"
"\n"
"<p><img src=\":/images/logo-small.svg\" height=\"100\" width=\"100\" /></p>\n"
"\n"
"</body></html>", nullptr));
        label->setText(QCoreApplication::translate("dlgAbout", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Stock Manager</span></p><p>Manage stock on your shop</p><p><span style=\" font-weight:600;\">Version:</span> 0.1.0</p><p><span style=\" font-style:italic;\">(C) Noah Too</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("dlgAbout", "Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dlgAbout: public Ui_dlgAbout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ABOUTQJERIV_H
