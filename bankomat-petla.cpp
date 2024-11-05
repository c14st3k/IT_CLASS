#include <iostream>
#include <sqlite3.h>
//gg
// Funkcja obsługująca komendę WPŁATA
void wpłata(sqlite3 *db, double kwota, int użytkownik_id) {
    // Tutaj implementuj logikę dodawania kwoty do konta użytkownika w bazie danych
}

// Funkcja obsługująca komendę WYPŁATA
void wypłata(sqlite3 *db, double kwota, int użytkownik_id) {
    // Tutaj implementuj logikę odejmowania kwoty z konta użytkownika w bazie danych
}

// Funkcja obsługująca komendę BALANS
void balans(sqlite3 *db, int użytkownik_id) {
    // Tutaj implementuj logikę wyświetlania stanu konta użytkownika z bazy danych
}

int main() {
    // Parametry logowania do bazy danych
    const char *host = "localhost";
    const char *username = "root";
    const char *password = "";
    const char *database = "bankomat";

    sqlite3 *db;
    int rc = sqlite3_open("baza_danych.db", &db);

    if (rc) {
        std::cerr << "Nie można otworzyć bazy danych: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }

    // Logowanie do bazy danych
    rc = sqlite3_exec(db, "ATTACH DATABASE 'bankomat' AS bankomat", 0, 0, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "Błąd podczas logowania do bazy danych: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 1;
    }

    // Pętla obsługująca interakcję z użytkownikiem
    std::string komenda;
    while (true) {
        std::cout << "Wpisz komendę (WPŁATA, WYPŁATA, BALANS lub EXIT): ";
        std::cin >> komenda;

        if (komenda == "WPŁATA") {
            double kwota;
            std::cout << "Podaj kwotę do wpłaty: ";
            std::cin >> kwota;
            // Pobierz użytkownika (np. na podstawie loginu) i jego id, a następnie przekaż do funkcji wpłata
        } else if (komenda == "WYPŁATA") {
            double kwota;
            std::cout << "Podaj kwotę do wypłaty: ";
            std::cin >> kwota;
            // Pobierz użytkownika (np. na podstawie loginu) i jego id, a następnie przekaż do funkcji wypłata
        } else if (komenda == "BALANS") {
            // Pobierz użytkownika (np. na podstawie loginu) i jego id, a następnie przekaż do funkcji balans
        } else if (komenda == "EXIT") {
            break;
        } else {
            std::cout << "Niepoprawna komenda, spróbuj ponownie." << std::endl;
        }
    }

    sqlite3_close(db);
    return 0;
}
