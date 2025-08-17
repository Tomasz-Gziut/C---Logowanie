#include "register2.h"
#include "ui_register2.h"
#include <QDebug>
#include <QMessageBox>
#include <QRegularExpression>

register2::register2(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::register2)
    , dbManager(nullptr)
{
    ui->setupUi(this);
}

register2::~register2()
{
    delete ui;
}

void register2::on_pushButton_2_clicked()
{
    if (!dbManager) {
        QMessageBox::critical(this, "Błąd", "Brak połączenia z bazą danych!");
        return;
    }

    QString firstName = ui->lineEdit_firstName->text();
    QString lastName = ui->lineEdit_lastName->text();
    QString email = ui->lineEdit_email->text();
    QString login = ui->lineEdit_login->text();
    QString password = ui->lineEdit_password->text();
    QString confirmPassword = ui->lineEdit_confirmPassword->text();
    int age = ui->spinBox_age->value();

    // Validate input
    if (firstName.isEmpty() || lastName.isEmpty() || email.isEmpty() ||
        login.isEmpty() || password.isEmpty() || confirmPassword.isEmpty()) {
        QMessageBox::warning(this, "Błąd", "Proszę wypełnić wszystkie pola!");
        return;
    }

    // Validate email format
    QRegularExpression emailRegex("^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$");
    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::warning(this, "Błąd", "Proszę podać prawidłowy adres email!");
        return;
    }

    // Check if passwords match
    if (password != confirmPassword) {
        QMessageBox::warning(this, "Błąd", "Hasła nie są identyczne!");
        return;
    }

    if (age < 18) {
        QMessageBox::warning(this, "Błąd", "Musisz mieć co najmniej 18 lat!");
        return;
    }

    // Try to add user to database
    if (dbManager->addUser(firstName, lastName, age, email, login, password)) {
        QMessageBox::information(this, "Sukces", "Rejestracja zakończona pomyślnie!");
        this->close();
    } else {
        QMessageBox::warning(this, "Błąd", "Nie można zarejestrować użytkownika. Login lub email już istnieje!");
    }
}
