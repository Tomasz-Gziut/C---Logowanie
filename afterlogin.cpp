#include "afterlogin.h"
#include "ui_afterlogin.h"

afterLogin::afterLogin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::afterLogin)
    , isAdmin(false)
    , dbManager(nullptr)
{
    ui->setupUi(this);
    ui->frame_adminPanel->setVisible(false);
}

afterLogin::~afterLogin()
{
    delete ui;
}

void afterLogin::setLogin(const QString& login)
{
    currentLogin = login;
    ui->label_2->setText(login);
}

void afterLogin::setIsAdmin(bool admin)
{
    isAdmin = admin;
    ui->frame_adminPanel->setVisible(admin);
    if (admin) {
        updateUserList();
    }
}

void afterLogin::setDatabaseManager(DatabaseManager *manager)
{
    dbManager = manager;
    if (isAdmin) {
        updateUserList();
    }
}

void afterLogin::updateUserList()
{
    if (!dbManager || !isAdmin) return;

    ui->listWidget_users->clear();
    QList<QPair<QString, bool>> users = dbManager->getAllUsers();

    for (const auto &user : users) {
        if (user.first != currentLogin) { // Don't show current user
            QString displayText = user.first + (user.second ? " (Admin)" : "");
            QListWidgetItem *item = new QListWidgetItem(displayText);
            item->setData(Qt::UserRole, user.first); // Store actual login
            item->setData(Qt::UserRole + 1, user.second); // Store admin status
            ui->listWidget_users->addItem(item);
        }
    }
}

void afterLogin::on_pushButton_grantAdmin_clicked()
{
    QListWidgetItem *currentItem = ui->listWidget_users->currentItem();
    if (!currentItem) {
        QMessageBox::warning(this, "Błąd", "Proszę wybrać użytkownika z listy!");
        return;
    }

    QString targetLogin = currentItem->data(Qt::UserRole).toString();
    bool isCurrentlyAdmin = currentItem->data(Qt::UserRole + 1).toBool();

    if (isCurrentlyAdmin) {
        QMessageBox::information(this, "Informacja", "Ten użytkownik już ma uprawnienia administratora!");
        return;
    }

    if (dbManager->setUserAdmin(targetLogin, true)) {
        QMessageBox::information(this, "Sukces", "Nadano uprawnienia administratora!");
        updateUserList();
    } else {
        QMessageBox::warning(this, "Błąd", "Nie udało się nadać uprawnień administratora!");
    }
}

void afterLogin::on_pushButton_revokeAdmin_clicked()
{
    QListWidgetItem *currentItem = ui->listWidget_users->currentItem();
    if (!currentItem) {
        QMessageBox::warning(this, "Błąd", "Proszę wybrać użytkownika z listy!");
        return;
    }

    QString targetLogin = currentItem->data(Qt::UserRole).toString();
    bool isCurrentlyAdmin = currentItem->data(Qt::UserRole + 1).toBool();

    if (!isCurrentlyAdmin) {
        QMessageBox::information(this, "Informacja", "Ten użytkownik nie ma uprawnień administratora!");
        return;
    }

    if (dbManager->setUserAdmin(targetLogin, false)) {
        QMessageBox::information(this, "Sukces", "Odebrano uprawnienia administratora!");
        updateUserList();
    } else {
        QMessageBox::warning(this, "Błąd", "Nie udało się odebrać uprawnień administratora!");
    }
}
