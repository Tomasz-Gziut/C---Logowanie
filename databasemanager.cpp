#include "databasemanager.h"

DatabaseManager::DatabaseManager(QObject *parent)
    : QObject(parent)
{
    qDebug() << "Initializing database manager";
    
    // Dodajemy informację o ścieżce do pliku bazy danych
    QString dbPath = QDir::currentPath() + "/FinalUsers.db";
    qDebug() << "Database path:" << dbPath;
    
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);
    
    // Sprawdźmy dostępne sterowniki
    qDebug() << "Available drivers:" << QSqlDatabase::drivers();
}

DatabaseManager::~DatabaseManager()
{
    if (db.isOpen()) {
        db.close();
    }
}

bool DatabaseManager::initializeDatabase()
{
    if (!db.open()) {
        qDebug() << "Error: connection with database failed";
        return false;
    }

    // Sprawdź czy plik bazy danych istnieje
    QFileInfo dbFile(db.databaseName());
    qDebug() << "Database absolute path:" << dbFile.absoluteFilePath();
    qDebug() << "Database exists:" << dbFile.exists();
    qDebug() << "Current directory:" << QDir::currentPath();

    if (!createTables()) {
        qDebug() << "Error: creating tables failed";
        return false;
    }

    // Add default admin if the users table is empty
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM users");
    if (query.exec()) {
        if (query.next()) {
            int count = query.value(0).toInt();
            qDebug() << "Database has" << count << "users";
            if (count == 0) {
                bool adminAdded = addDefaultAdmin();
                qDebug() << "Default admin added:" << adminAdded;
                return adminAdded;
            } else {
                // Reset admin password to non-hashed version
                bool adminReset = resetAdmin();
                qDebug() << "Admin password reset:" << adminReset;
            }
        } else {
            qDebug() << "Error: couldn't get user count";
            return false;
        }
    } else {
        qDebug() << "Error executing query:" << query.lastError().text();
        return false;
    }

    return true;
}

bool DatabaseManager::resetAdmin()
{
    QSqlQuery query;
    query.prepare("UPDATE users SET password = ?, isAdmin = 1 WHERE login = ?");
    query.addBindValue("admin123");
    query.addBindValue("admin");
    
    bool success = query.exec();
    if (!success) {
        qDebug() << "Error resetting admin password:" << query.lastError().text();
    } else {
        qDebug() << "Admin password has been reset to plain text and admin privileges restored";
    }
    
    return success;
}

bool DatabaseManager::createTables()
{
    QSqlQuery query;
    bool success = query.exec("CREATE TABLE IF NOT EXISTS users ("
                     "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                     "firstName TEXT NOT NULL,"
                     "lastName TEXT NOT NULL,"
                     "age INTEGER NOT NULL,"
                     "email TEXT NOT NULL UNIQUE,"
                     "login TEXT NOT NULL UNIQUE,"
                     "password TEXT NOT NULL,"
                     "isAdmin BOOLEAN NOT NULL DEFAULT 0)");
    
    if (!success) {
        qDebug() << "Error creating tables:" << query.lastError().text();
    }
    
    return success;
}

bool DatabaseManager::addDefaultAdmin()
{
    qDebug() << "Attempting to add default admin";
    return addUser("Admin", "Admin", 30, "admin@example.com", "admin",
                  "admin123", true);
}

bool DatabaseManager::addUser(const QString &firstName, const QString &lastName,
                            int age, const QString &email, const QString &login,
                            const QString &password, bool isAdmin)
{
    QSqlQuery query;
    query.prepare("INSERT INTO users (firstName, lastName, age, email, login, "
                 "password, isAdmin) VALUES (?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(firstName);
    query.addBindValue(lastName);
    query.addBindValue(age);
    query.addBindValue(email);
    query.addBindValue(login);
    query.addBindValue(password);
    query.addBindValue(isAdmin);

    bool success = query.exec();
    if (!success) {
        qDebug() << "Error adding user:" << query.lastError().text();
    }
    
    return success;
}

bool DatabaseManager::validateUser(const QString &login, const QString &password)
{
    QSqlQuery query;
    query.prepare("SELECT password FROM users WHERE login = ?");
    query.addBindValue(login);

    if (query.exec()) {
        if (query.next()) {
            QString storedPassword = query.value(0).toString();
            qDebug() << "Validating user:" << login;
            qDebug() << "Entered password:" << password;
            qDebug() << "Stored password:" << storedPassword;
            return storedPassword == password;
        } else {
            qDebug() << "No user found with login:" << login;
            return false;
        }
    } else {
        qDebug() << "Error validating user:" << query.lastError().text();
        return false;
    }
}

bool DatabaseManager::isAdmin(const QString &login)
{
    QSqlQuery query;
    query.prepare("SELECT isAdmin FROM users WHERE login = ?");
    query.addBindValue(login);

    if (query.exec() && query.next()) {
        return query.value(0).toBool();
    }
    return false;
}

QList<QPair<QString, bool>> DatabaseManager::getAllUsers()
{
    QList<QPair<QString, bool>> users;
    QSqlQuery query("SELECT login, isAdmin FROM users");

    while (query.next()) {
        users.append(qMakePair(query.value(0).toString(),
                             query.value(1).toBool()));
    }

    return users;
}

bool DatabaseManager::setUserAdmin(const QString &login, bool isAdmin)
{
    QSqlQuery query;
    query.prepare("UPDATE users SET isAdmin = ? WHERE login = ?");
    query.addBindValue(isAdmin);
    query.addBindValue(login);

    return query.exec();
} 