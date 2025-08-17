#ifndef AFTERLOGIN_H
#define AFTERLOGIN_H

#include <QMainWindow>
#include <QListWidget>
#include <QMessageBox>
#include "databasemanager.h"

namespace Ui {
class afterLogin;
}

class afterLogin : public QMainWindow
{
    Q_OBJECT

public:
    explicit afterLogin(QWidget *parent = nullptr);
    ~afterLogin();

    void setLogin(const QString& login);
    void setIsAdmin(bool isAdmin);
    void setDatabaseManager(DatabaseManager *manager);
    void updateUserList();

private slots:
    void on_pushButton_grantAdmin_clicked();
    void on_pushButton_revokeAdmin_clicked();

private:
    Ui::afterLogin *ui;
    QString currentLogin;
    bool isAdmin;
    DatabaseManager *dbManager;
};

#endif // AFTERLOGIN_H
