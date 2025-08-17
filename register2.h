#ifndef REGISTER2_H
#define REGISTER2_H

#include <QDialog>
#include <QMessageBox>
#include "databasemanager.h"

namespace Ui {
class register2;
}

class register2 : public QDialog
{
    Q_OBJECT

public:
    explicit register2(QWidget *parent = nullptr);
    ~register2();

    void setDatabaseManager(DatabaseManager *manager) { dbManager = manager; }

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::register2 *ui;
    DatabaseManager *dbManager;
};

#endif // REGISTER2_H
