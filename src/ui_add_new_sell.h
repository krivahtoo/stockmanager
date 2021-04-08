/********************************************************************************
** Form generated from reading UI file 'add_new_sellmWEPWO.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ADD_NEW_SELLMWEPWO_H
#define ADD_NEW_SELLMWEPWO_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dlgAddNew
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *grpItem;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *txtId;
    QLabel *label_2;
    QSpinBox *spbQuantity;
    QLabel *label_3;
    QLineEdit *txtName;
    QGroupBox *grpSearch;
    QVBoxLayout *verticalLayout;
    QLineEdit *txtSearch;
    QListWidget *lstSearch;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnAdd;

    void setupUi(QDialog *dlgAddNew)
    {
        if (dlgAddNew->objectName().isEmpty())
            dlgAddNew->setObjectName(QString::fromUtf8("dlgAddNew"));
        dlgAddNew->setWindowModality(Qt::WindowModal);
        dlgAddNew->resize(485, 322);
        dlgAddNew->setModal(true);
        verticalLayout_2 = new QVBoxLayout(dlgAddNew);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        grpItem = new QGroupBox(dlgAddNew);
        grpItem->setObjectName(QString::fromUtf8("grpItem"));
        formLayout = new QFormLayout(grpItem);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(grpItem);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        txtId = new QLineEdit(grpItem);
        txtId->setObjectName(QString::fromUtf8("txtId"));
        txtId->setMaximumSize(QSize(226, 16777215));

        formLayout->setWidget(0, QFormLayout::FieldRole, txtId);

        label_2 = new QLabel(grpItem);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        spbQuantity = new QSpinBox(grpItem);
        spbQuantity->setObjectName(QString::fromUtf8("spbQuantity"));
        spbQuantity->setMaximumSize(QSize(75, 16777215));

        formLayout->setWidget(1, QFormLayout::FieldRole, spbQuantity);

        label_3 = new QLabel(grpItem);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        txtName = new QLineEdit(grpItem);
        txtName->setObjectName(QString::fromUtf8("txtName"));
        txtName->setEnabled(false);

        formLayout->setWidget(2, QFormLayout::FieldRole, txtName);

        grpSearch = new QGroupBox(grpItem);
        grpSearch->setObjectName(QString::fromUtf8("grpSearch"));
        verticalLayout = new QVBoxLayout(grpSearch);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        txtSearch = new QLineEdit(grpSearch);
        txtSearch->setObjectName(QString::fromUtf8("txtSearch"));

        verticalLayout->addWidget(txtSearch);

        lstSearch = new QListWidget(grpSearch);
        lstSearch->setObjectName(QString::fromUtf8("lstSearch"));

        verticalLayout->addWidget(lstSearch);


        formLayout->setWidget(3, QFormLayout::SpanningRole, grpSearch);


        verticalLayout_2->addWidget(grpItem);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        btnCancel = new QPushButton(dlgAddNew);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setMinimumSize(QSize(88, 26));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/cross.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnCancel->setIcon(icon);

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnAdd = new QPushButton(dlgAddNew);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        btnAdd->setMinimumSize(QSize(88, 26));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/cart.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnAdd->setIcon(icon1);

        horizontalLayout->addWidget(btnAdd);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(dlgAddNew);
        QObject::connect(btnCancel, SIGNAL(clicked()), dlgAddNew, SLOT(reject()));

        QMetaObject::connectSlotsByName(dlgAddNew);
    } // setupUi

    void retranslateUi(QDialog *dlgAddNew)
    {
        dlgAddNew->setWindowTitle(QCoreApplication::translate("dlgAddNew", "Add Item to Cart", nullptr));
        grpItem->setTitle(QCoreApplication::translate("dlgAddNew", "Item", nullptr));
        label->setText(QCoreApplication::translate("dlgAddNew", "Item Id:", nullptr));
        label_2->setText(QCoreApplication::translate("dlgAddNew", "Quantity:", nullptr));
        label_3->setText(QCoreApplication::translate("dlgAddNew", "Name:", nullptr));
        txtName->setText(QCoreApplication::translate("dlgAddNew", "No id entered...", nullptr));
        grpSearch->setTitle(QCoreApplication::translate("dlgAddNew", "Search", nullptr));
        txtSearch->setPlaceholderText(QCoreApplication::translate("dlgAddNew", "Search...", nullptr));
        btnCancel->setText(QCoreApplication::translate("dlgAddNew", "Cancel", nullptr));
        btnAdd->setText(QCoreApplication::translate("dlgAddNew", "Add to Cart", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dlgAddNew: public Ui_dlgAddNew {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ADD_NEW_SELLMWEPWO_H
