#include <iostream>
#include "sqlite3.h"

int main() {
    sqlite3* db = nullptr;
    char* errMessage = nullptr;

    // Открытие или создание базы данных (файл test.db)
    int exitCode = sqlite3_open("cafe-in.db", &db);

    if (exitCode != SQLITE_OK) {
        std::cerr << "Ошибка открытия БД: " << sqlite3_errmsg(db) << std::endl;
        return (1);
    } else {
        std::cout << "База данных успешно создана/открыта!" << std::endl;
    }

    // SQL-запрос для создания таблицы
    const char* sql = "CREATE TABLE IF NOT EXISTS Users ("
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "Name TEXT NOT NULL, "
                      "Age INT);";

    // Выполнение SQL-запроса
    exitCode = sqlite3_exec(db, sql, 0, 0, &errMessage);

    if (exitCode != SQLITE_OK) {
        std::cerr << "Ошибка создания таблицы: " << errMessage << std::endl;
        sqlite3_free(errMessage);
    } else {
        std::cout << "Таблица создана успешно!" << std::endl;
    }

    // Закрытие соединения
    sqlite3_close(db);
    return 0;
}
