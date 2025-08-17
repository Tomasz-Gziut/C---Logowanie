#include "login.h"
#include "ui_login.h"
#include "afterLogin.h"
#include "QMessageBox"
#include <QDebug>

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
    , reg(nullptr)
    , afterLoginWindow(nullptr)
{
    ui->setupUi(this);
    dbManager = new DatabaseManager(this);
    
    qDebug() << "Initializing application";
    
    if (!dbManager->initializeDatabase()) {
        QMessageBox::critical(this, "Błąd", "Nie można połączyć się z bazą danych!");
        qDebug() << "Failed to initialize database";
    } else {
        qDebug() << "Database initialized successfully";
    }
}

login::~login()
{
    delete reg;
    delete ui;
    delete afterLoginWindow;
}

void login::on_pushButton_2_clicked()
{
    if (!reg) {
        reg = new register2(this);
    }
    reg->setDatabaseManager(dbManager);
    reg->setWindowModality(Qt::WindowModal);
    reg->show();
}

void login::on_pushButton_3_clicked()
{
    QString loginText = ui->lineEdit->text();
    QString passwordText = ui->lineEdit_2->text();

    qDebug() << "Attempting login with:" << loginText;

    if (loginText.isEmpty() || passwordText.isEmpty()) {
        QMessageBox::warning(this, "Błąd", "Proszę wypełnić wszystkie pola!");
        return;
    }

    qDebug() << "Validating user credentials...";
    if (dbManager->validateUser(loginText, passwordText)) {
        qDebug() << "Login successful for user:" << loginText;
        if (!afterLoginWindow) {
            afterLoginWindow = new class afterLogin(this);
        }
        
        bool userIsAdmin = dbManager->isAdmin(loginText);
        qDebug() << "User is admin:" << userIsAdmin;
        
        afterLoginWindow->setLogin(loginText);
        afterLoginWindow->setIsAdmin(userIsAdmin);
        afterLoginWindow->setDatabaseManager(dbManager);
        afterLoginWindow->setWindowModality(Qt::WindowModal);
        afterLoginWindow->show();
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
    } else {
        qDebug() << "Login failed for user:" << loginText;
        QMessageBox::warning(this, "Błąd logowania", "Nieprawidłowy login lub hasło!");
    }
}
