/********************************************************************************
** Form generated from reading UI file 'register2.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER2_H
#define UI_REGISTER2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_register2
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_title;
    QFormLayout *formLayout;
    QLabel *label_firstName;
    QLineEdit *lineEdit_firstName;
    QLabel *label_lastName;
    QLineEdit *lineEdit_lastName;
    QLabel *label_age;
    QSpinBox *spinBox_age;
    QLabel *label_email;
    QLineEdit *lineEdit_email;
    QLabel *label_login;
    QLineEdit *lineEdit_login;
    QLabel *label_password;
    QLineEdit *lineEdit_password;
    QLabel *label_confirmPassword;
    QLineEdit *lineEdit_confirmPassword;
    QPushButton *pushButton_2;

    void setupUi(QDialog *register2)
    {
        if (register2->objectName().isEmpty())
            register2->setObjectName("register2");
        register2->resize(600, 700);
        verticalLayout = new QVBoxLayout(register2);
        verticalLayout->setObjectName("verticalLayout");
        label_title = new QLabel(register2);
        label_title->setObjectName("label_title");
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label_title->setFont(font);
        label_title->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_title);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_firstName = new QLabel(register2);
        label_firstName->setObjectName("label_firstName");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_firstName);

        lineEdit_firstName = new QLineEdit(register2);
        lineEdit_firstName->setObjectName("lineEdit_firstName");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_firstName);

        label_lastName = new QLabel(register2);
        label_lastName->setObjectName("label_lastName");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_lastName);

        lineEdit_lastName = new QLineEdit(register2);
        lineEdit_lastName->setObjectName("lineEdit_lastName");

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_lastName);

        label_age = new QLabel(register2);
        label_age->setObjectName("label_age");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_age);

        spinBox_age = new QSpinBox(register2);
        spinBox_age->setObjectName("spinBox_age");
        spinBox_age->setMinimum(18);
        spinBox_age->setMaximum(120);

        formLayout->setWidget(2, QFormLayout::FieldRole, spinBox_age);

        label_email = new QLabel(register2);
        label_email->setObjectName("label_email");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_email);

        lineEdit_email = new QLineEdit(register2);
        lineEdit_email->setObjectName("lineEdit_email");

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_email);

        label_login = new QLabel(register2);
        label_login->setObjectName("label_login");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_login);

        lineEdit_login = new QLineEdit(register2);
        lineEdit_login->setObjectName("lineEdit_login");

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_login);

        label_password = new QLabel(register2);
        label_password->setObjectName("label_password");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_password);

        lineEdit_password = new QLineEdit(register2);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEdit_password);

        label_confirmPassword = new QLabel(register2);
        label_confirmPassword->setObjectName("label_confirmPassword");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_confirmPassword);

        lineEdit_confirmPassword = new QLineEdit(register2);
        lineEdit_confirmPassword->setObjectName("lineEdit_confirmPassword");
        lineEdit_confirmPassword->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(6, QFormLayout::FieldRole, lineEdit_confirmPassword);


        verticalLayout->addLayout(formLayout);

        pushButton_2 = new QPushButton(register2);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout->addWidget(pushButton_2);


        retranslateUi(register2);

        QMetaObject::connectSlotsByName(register2);
    } // setupUi

    void retranslateUi(QDialog *register2)
    {
        register2->setWindowTitle(QCoreApplication::translate("register2", "Rejestracja", nullptr));
        label_title->setText(QCoreApplication::translate("register2", "Rejestracja nowego u\305\274ytkownika", nullptr));
        label_firstName->setText(QCoreApplication::translate("register2", "Imi\304\231:", nullptr));
        label_lastName->setText(QCoreApplication::translate("register2", "Nazwisko:", nullptr));
        label_age->setText(QCoreApplication::translate("register2", "Wiek:", nullptr));
        label_email->setText(QCoreApplication::translate("register2", "Email:", nullptr));
        label_login->setText(QCoreApplication::translate("register2", "Login:", nullptr));
        label_password->setText(QCoreApplication::translate("register2", "Has\305\202o:", nullptr));
        label_confirmPassword->setText(QCoreApplication::translate("register2", "Potwierd\305\272 has\305\202o:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("register2", "Zarejestruj si\304\231", nullptr));
    } // retranslateUi

};

namespace Ui {
    class register2: public Ui_register2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER2_H
