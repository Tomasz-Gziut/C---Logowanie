#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDir>
#include <QFileInfo>

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseManager(QObject *parent = nullptr);
    ~DatabaseManager();

    bool initializeDatabase();
    bool addUser(const QString &firstName, const QString &lastName, int age,
                const QString &email, const QString &login, const QString &password,
                bool isAdmin = false);
    bool validateUser(const QString &login, const QString &password);
    bool isAdmin(const QString &login);
    QList<QPair<QString, bool>> getAllUsers();
    bool setUserAdmin(const QString &login, bool isAdmin);

private:
    QSqlDatabase db;
    bool createTables();
    bool addDefaultAdmin();
    bool resetAdmin();
};

#endif // DATABASEMANAGER_H 