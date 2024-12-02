#include "pracownik.h"
#include "RandomNameGenerator.hpp"
#include <iostream>

// Konstruktor klasy bazowej Pracownik
Pracownik::Pracownik() : imie(getRandomName()){}



double Pracownik::getWynagrodzenie() const {
    return 0;
}
void Pracownik::wyswietlInformacje() const {}

// Konstruktor klasy Inzynier
Inzynier::Inzynier() : wydzial(getWydzial()), wynagrodzenie(9000.0) {}

void Inzynier::wyswietlInformacje() const {
    std::cout << "Inżynier: " << imie
              << ", Wynagrodzenie: " << wynagrodzenie
              << " PLN, Wydział: " << wydzial << "\n";
}

double Inzynier::getWynagrodzenie() const {
        return wynagrodzenie;
}

// Konstruktor klasy Magazynier
Magazynier::Magazynier() :  wozek_widlowy(getWozek()), wynagrodzenie(6000.0) {}

void Magazynier::wyswietlInformacje() const {
    std::cout << "Magazynier: " << imie
              << ", Wynagrodzenie: " << wynagrodzenie
              << " PLN, Obsługuje wózek: " << (wozek_widlowy ? "Tak" : "Nie") << "\n";
}
double Magazynier::getWynagrodzenie() const {
        return wynagrodzenie;
}
// Konstruktor klasy Marketer
Marketer::Marketer() : followers(getFollow()), wynagrodzenie(5000.0) {}

void Marketer::wyswietlInformacje() const {
    std::cout << "Marketer: " << imie 
              << ", Wynagrodzenie: " << wynagrodzenie
              << " PLN, Obserwujący: " << followers << "\n";
}
double Marketer::getWynagrodzenie() const {
        return wynagrodzenie;
    }
// Konstruktor klasy Robotnik
Robotnik::Robotnik() : shoe_size(getBut()), wynagrodzenie(7000.0) {}

void Robotnik::wyswietlInformacje() const {
    std::cout << "Robotnik: " << imie 
              << ", Wynagrodzenie: " << wynagrodzenie
              << " PLN, Rozmiar buta: " << shoe_size << "\n";
}
double Robotnik::getWynagrodzenie() const {
        return wynagrodzenie;
}