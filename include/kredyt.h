#ifndef KREDYT_H
#define KREDYT_H

class Kredyt {
public:
    double kwota;                  // Kwota kredytu
    int pozostaleMiesiaceSplaty;   // Pozostały czas spłaty w miesiącach
    double rataMiesieczna;         // Miesięczna rata (z odsetkami)

    Kredyt(double kwota, int czasSplaty, double oprocentowanie);

    double getRata() const;        // Zwraca ratę miesięczną
    int getPozostaleMiesiace() const; // Zwraca liczbę miesięcy do spłaty
    void zmniejszMiesiace();       // Zmniejsza liczbę pozostałych miesięcy o 1
    bool czyPrzeterminowany() const; // Sprawdza, czy kredyt jest przeterminowany
};

#endif
