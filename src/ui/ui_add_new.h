/********************************************************************************
** Form generated from reading UI file 'add_newMzdTNx.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ADD_NEWMZDTNX_H
#define ADD_NEWMZDTNX_H

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

class Ui_dlgAdd
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *grpItem;
    QFormLayout *formLayout;
    QLabel *lblId;
    QLineEdit *txtId;
    QLineEdit *txtName;
    QLabel *lblName;
    QLabel *lblQuantity;
    QSpinBox *spnQuantity;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QFormLayout *formLayout_2;
    QLabel *label;
    QSpinBox *spnBuyingPrice;
    QLabel *lblPrice;
    QSpinBox *spnPrice;
    QFormLayout *formLayout_4;
    QLabel *label_3;
    QSpinBox *spnMin;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QLineEdit *txtCapacity;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSave;

    void setupUi(QDialog *dlgAdd)
    {
        if (dlgAdd->objectName().isEmpty())
            dlgAdd->setObjectName(QString::fromUtf8("dlgAdd"));
        dlgAdd->setWindowModality(Qt::WindowModal);
        dlgAdd->resize(512, 272);
        dlgAdd->setMinimumSize(QSize(0, 0));
        dlgAdd->setMaximumSize(QSize(41055, 25455));
        dlgAdd->setModal(true);
        verticalLayout = new QVBoxLayout(dlgAdd);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        grpItem = new QGroupBox(dlgAdd);
        grpItem->setObjectName(QString::fromUtf8("grpItem"));
        formLayout = new QFormLayout(grpItem);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        lblId = new QLabel(grpItem);
        lblId->setObjectName(QString::fromUtf8("lblId"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lblId);

        txtId = new QLineEdit(grpItem);
        txtId->setObjectName(QString::fromUtf8("txtId"));
        txtId->setMaximumSize(QSize(181, 16777215));
        txtId->setInputMethodHints(Qt::ImhNone);

        formLayout->setWidget(0, QFormLayout::FieldRole, txtId);

        txtName = new QLineEdit(grpItem);
        txtName->setObjectName(QString::fromUtf8("txtName"));

        formLayout->setWidget(1, QFormLayout::FieldRole, txtName);

        lblName = new QLabel(grpItem);
        lblName->setObjectName(QString::fromUtf8("lblName"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lblName);

        lblQuantity = new QLabel(grpItem);
        lblQuantity->setObjectName(QString::fromUtf8("lblQuantity"));

        formLayout->setWidget(2, QFormLayout::LabelRole, lblQuantity);

        spnQuantity = new QSpinBox(grpItem);
        spnQuantity->setObjectName(QString::fromUtf8("spnQuantity"));
        spnQuantity->setMaximumSize(QSize(101, 16777215));
        spnQuantity->setMinimum(1);
        spnQuantity->setMaximum(99999);

        formLayout->setWidget(2, QFormLayout::FieldRole, spnQuantity);

        groupBox = new QGroupBox(grpItem);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        spnBuyingPrice = new QSpinBox(groupBox);
        spnBuyingPrice->setObjectName(QString::fromUtf8("spnBuyingPrice"));
        spnBuyingPrice->setMaximumSize(QSize(141, 16777215));
        spnBuyingPrice->setMaximum(999999);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, spnBuyingPrice);

        lblPrice = new QLabel(groupBox);
        lblPrice->setObjectName(QString::fromUtf8("lblPrice"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, lblPrice);

        spnPrice = new QSpinBox(groupBox);
        spnPrice->setObjectName(QString::fromUtf8("spnPrice"));
        spnPrice->setMaximumSize(QSize(141, 16777215));
        spnPrice->setMaximum(999999);
        spnPrice->setValue(0);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, spnPrice);


        horizontalLayout_2->addLayout(formLayout_2);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_3);

        spnMin = new QSpinBox(groupBox);
        spnMin->setObjectName(QString::fromUtf8("spnMin"));

        formLayout_4->setWidget(1, QFormLayout::FieldRole, spnMin);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_4->setItem(0, QFormLayout::LabelRole, verticalSpacer_2);


        horizontalLayout_2->addLayout(formLayout_4);


        formLayout->setWidget(4, QFormLayout::SpanningRole, groupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(5, QFormLayout::SpanningRole, verticalSpacer);

        label_2 = new QLabel(grpItem);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_2);

        txtCapacity = new QLineEdit(grpItem);
        txtCapacity->setObjectName(QString::fromUtf8("txtCapacity"));
        txtCapacity->setMaximumSize(QSize(181, 16777215));

        formLayout->setWidget(3, QFormLayout::FieldRole, txtCapacity);


        verticalLayout->addWidget(grpItem);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnCancel = new QPushButton(dlgAdd);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setMinimumSize(QSize(88, 26));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/cross.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnCancel->setIcon(icon);

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSave = new QPushButton(dlgAdd);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setMinimumSize(QSize(88, 26));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/checkmark.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnSave->setIcon(icon1);

        horizontalLayout->addWidget(btnSave);


        verticalLayout->addLayout(horizontalLayout);

        QWidget::setTabOrder(txtId, txtName);
        QWidget::setTabOrder(txtName, spnQuantity);
        QWidget::setTabOrder(spnQuantity, txtCapacity);
        QWidget::setTabOrder(txtCapacity, spnBuyingPrice);
        QWidget::setTabOrder(spnBuyingPrice, spnPrice);
        QWidget::setTabOrder(spnPrice, btnSave);
        QWidget::setTabOrder(btnSave, btnCancel);

        retranslateUi(dlgAdd);
        QObject::connect(btnCancel, SIGNAL(clicked()), dlgAdd, SLOT(reject()));

        btnSave->setDefault(true);


        QMetaObject::connectSlotsByName(dlgAdd);
    } // setupUi

    void retranslateUi(QDialog *dlgAdd)
    {
        dlgAdd->setWindowTitle(QCoreApplication::translate("dlgAdd", "Add New Item", nullptr));
        grpItem->setTitle(QCoreApplication::translate("dlgAdd", "Item", nullptr));
        lblId->setText(QCoreApplication::translate("dlgAdd", "Item Number / Id:", nullptr));
        txtId->setPlaceholderText(QCoreApplication::translate("dlgAdd", "Item id / Serial no..", nullptr));
        txtName->setPlaceholderText(QCoreApplication::translate("dlgAdd", "Item name..", nullptr));
        lblName->setText(QCoreApplication::translate("dlgAdd", "Name:", nullptr));
        lblQuantity->setText(QCoreApplication::translate("dlgAdd", "Quantity:", nullptr));
        groupBox->setTitle(QCoreApplication::translate("dlgAdd", "Prices per Item", nullptr));
        label->setText(QCoreApplication::translate("dlgAdd", "Buying Price:", nullptr));
        spnBuyingPrice->setSuffix(QCoreApplication::translate("dlgAdd", ".00", nullptr));
        spnBuyingPrice->setPrefix(QCoreApplication::translate("dlgAdd", "Ksh. ", nullptr));
        lblPrice->setText(QCoreApplication::translate("dlgAdd", "Selling Price:", nullptr));
        spnPrice->setSuffix(QCoreApplication::translate("dlgAdd", ".00", nullptr));
        spnPrice->setPrefix(QCoreApplication::translate("dlgAdd", "Ksh. ", nullptr));
        label_3->setText(QCoreApplication::translate("dlgAdd", "Minimum Price", nullptr));
        spnMin->setSuffix(QCoreApplication::translate("dlgAdd", ".00", nullptr));
        spnMin->setPrefix(QCoreApplication::translate("dlgAdd", "Ksh. ", nullptr));
        label_2->setText(QCoreApplication::translate("dlgAdd", "Capacity / Weight:", nullptr));
        txtCapacity->setPlaceholderText(QCoreApplication::translate("dlgAdd", "e.g. 500g, 100ml", nullptr));
        btnCancel->setText(QCoreApplication::translate("dlgAdd", "Cancel", nullptr));
        btnSave->setText(QCoreApplication::translate("dlgAdd", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dlgAdd: public Ui_dlgAdd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ADD_NEWMZDTNX_H
