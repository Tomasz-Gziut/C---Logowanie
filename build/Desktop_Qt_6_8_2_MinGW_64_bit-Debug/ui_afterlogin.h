/********************************************************************************
** Form generated from reading UI file 'afterlogin.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AFTERLOGIN_H
#define UI_AFTERLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_afterLogin
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QFrame *frame_adminPanel;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QListWidget *listWidget_users;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_grantAdmin;
    QPushButton *pushButton_revokeAdmin;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *afterLogin)
    {
        if (afterLogin->objectName().isEmpty())
            afterLogin->setObjectName("afterLogin");
        afterLogin->resize(800, 600);
        afterLogin->setMinimumSize(QSize(800, 600));
        centralwidget = new QWidget(afterLogin);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(16);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        horizontalLayout->addWidget(label_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        frame_adminPanel = new QFrame(centralwidget);
        frame_adminPanel->setObjectName("frame_adminPanel");
        frame_adminPanel->setFrameShape(QFrame::StyledPanel);
        frame_adminPanel->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_adminPanel);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_4 = new QLabel(frame_adminPanel);
        label_4->setObjectName("label_4");
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        label_4->setFont(font1);

        verticalLayout_2->addWidget(label_4);

        listWidget_users = new QListWidget(frame_adminPanel);
        listWidget_users->setObjectName("listWidget_users");

        verticalLayout_2->addWidget(listWidget_users);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pushButton_grantAdmin = new QPushButton(frame_adminPanel);
        pushButton_grantAdmin->setObjectName("pushButton_grantAdmin");

        horizontalLayout_2->addWidget(pushButton_grantAdmin);

        pushButton_revokeAdmin = new QPushButton(frame_adminPanel);
        pushButton_revokeAdmin->setObjectName("pushButton_revokeAdmin");

        horizontalLayout_2->addWidget(pushButton_revokeAdmin);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout->addWidget(frame_adminPanel);

        afterLogin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(afterLogin);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        afterLogin->setMenuBar(menubar);
        statusbar = new QStatusBar(afterLogin);
        statusbar->setObjectName("statusbar");
        afterLogin->setStatusBar(statusbar);

        retranslateUi(afterLogin);

        QMetaObject::connectSlotsByName(afterLogin);
    } // setupUi

    void retranslateUi(QMainWindow *afterLogin)
    {
        afterLogin->setWindowTitle(QCoreApplication::translate("afterLogin", "Panel u\305\274ytkownika", nullptr));
        label->setText(QCoreApplication::translate("afterLogin", "Witaj", nullptr));
        label_2->setText(QCoreApplication::translate("afterLogin", "u\305\274ytkowniku", nullptr));
        label_3->setText(QCoreApplication::translate("afterLogin", "!", nullptr));
        label_4->setText(QCoreApplication::translate("afterLogin", "Panel administratora", nullptr));
        pushButton_grantAdmin->setText(QCoreApplication::translate("afterLogin", "Nadaj uprawnienia administratora", nullptr));
        pushButton_revokeAdmin->setText(QCoreApplication::translate("afterLogin", "Odbierz uprawnienia administratora", nullptr));
    } // retranslateUi

};

namespace Ui {
    class afterLogin: public Ui_afterLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AFTERLOGIN_H
