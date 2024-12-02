#include "firma.h"
#include <iostream>
#include <algorithm>



Firma::Firma() : stanKonta(poczatkowyStanKonta), maxMagazyn(0), aktMagazyn(0),  zadluzenie(0), przychod(0), dochod(0), CI(ci), CMag(cmag), CMkt(cmkt), CR(cr), X(x), M(m) 
{
    
    //domyslni pracownicy na start
    pracownicy.push_back(std::make_unique<Inzynier>());
    pracownicy.push_back(std::make_unique<Magazynier>());
    pracownicy.push_back(std::make_unique<Marketer>());
    pracownicy.push_back(std::make_unique<Robotnik>());

}

void Firma::wyswietlStanFirmy() const {
    std::cout << "Stan konta: " << stanKonta << " PLN\n";
    std::cout << "Magazyn: " << aktMagazyn << "/" << maxMagazyn << " produktów\n";
    std::cout << "Zadłużenie: " << zadluzenie << " PLN\n";
    std::cout << "Ostatni przychód: " << przychod << " PLN\n";
    std::cout << "Ostatni dochód: " << dochod << " PLN\n";
    std::cout << "Liczba aktywnych kredytów: " << kredyty.size() << "\n";
}

void Firma::zatrudnijPracownika(const std::string& typ) {
    if (typ == "inz") {
        pracownicy.push_back(std::make_unique<Inzynier>());
    } else if (typ == "mag") {
        pracownicy.push_back(std::make_unique<Magazynier>());
    } else if (typ == "mkt") {
        pracownicy.push_back(std::make_unique<Marketer>());
    } else if (typ == "rob") {
        pracownicy.push_back(std::make_unique<Robotnik>());
    } else {
        std::cout << "Nieznany typ pracownika!\n";
    }
}


void Firma::wezKredyt(double kwota, int czasSplaty) {
    if (czasSplaty > X) {
        std::cout << "Nie można wziąć kredytu na dłużej niż " << X << " miesięcy.\n";
        return;
    }
    if (zadluzenie + kwota > M * stanKonta) {
        std::cout << "Nie możesz zadłużyć się bardziej niż " << M << "-krotność wartości firmy.\n";
        return;
    }
    double oprocentowanie = 0.01 * czasSplaty;
    kredyty.push_back(Kredyt(kwota, czasSplaty, oprocentowanie)); // Dodaj kredyt z odsetkami
    zadluzenie += kwota * (1 + oprocentowanie);
    stanKonta += kwota;
    std::cout << "Wzięto kredyt na " << kwota << " PLN. Zadłużenie: " << zadluzenie << " PLN.\n";
}

void Firma::zakonczMiesiac() {
    // Oblicz pojemność magazynu
    maxMagazyn = 0;
    for (const auto& pracownik : pracownicy) {
        if (auto mag = dynamic_cast<Magazynier*>(pracownik.get())) {
            maxMagazyn += CMag;
        }
    }

    // Oblicz liczbę produktów w magazynie
    int produkcja = 0;
    for (const auto& pracownik : pracownicy) {
        if (auto rob = dynamic_cast<Robotnik*>(pracownik.get())) {
            produkcja += CR;
        }
    }
    aktMagazyn = std::min(produkcja, maxMagazyn);

    // Oblicz popyt
    int popyt = 0;
    for (const auto& pracownik : pracownicy) {
        if (auto mkt = dynamic_cast<Marketer*>(pracownik.get())) {
            popyt += CMkt;
        }
    }

    // Oblicz sprzedaż i przychód
    int sprzedaneProdukty = std::min(aktMagazyn, popyt);
    przychod = sprzedaneProdukty * CI;

    // Oblicz wynagrodzenia
    //dynamiczne wiazanie
    double wynagrodzenia = 0;
    for (const auto& pracownik : pracownicy) {
        wynagrodzenia += pracownik->getWynagrodzenie();
    }


    //splata kredytow
    double sumaRat = 0;
    for (auto it = kredyty.begin(); it != kredyty.end(); ) {
        sumaRat += it->getRata();
        it->zmniejszMiesiace();

        if (it->czyPrzeterminowany()) {
            std::cout << "Kredyt nie został spłacony na czas! Firma bankrutuje!\n";
            exit(0);
        }

        if (it->getPozostaleMiesiace() == 0) {
            zadluzenie -= it->getRata() * it->getPozostaleMiesiace();
            it = kredyty.erase(it);
        } else {
            ++it;
        }
    }

    // Oblicz dochód
    dochod = przychod - wynagrodzenia - zadluzenie / kredyty.size();
    stanKonta += dochod;

    // Wyświetl wynik
    std::cout << "Miesiąc zakończony! Dochód: " << dochod << " PLN.\n";
}

void Firma::wyswietlPracownikow() const {
    for (const auto& pracownik : pracownicy) {
        pracownik->wyswietlInformacje();
    }
}

double Firma::getStanKonta() const {
    return stanKonta;
}

double Firma::getWartoscFirmy() const {
    // Wartość firmy = średni przychód z ostatnich miesięcy
    return przychod; // Możesz dodać bardziej zaawansowaną logikę, np. uśrednienie z N miesięcy
}