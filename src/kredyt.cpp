#include "kredyt.h"

Kredyt::Kredyt(double kwota, int czasSplaty, double oprocentowanie) 
    : kwota(kwota), pozostaleMiesiaceSplaty(czasSplaty) {
    rataMiesieczna = (kwota * (1 + oprocentowanie)) / czasSplaty;
}

double Kredyt::getRata() const {
    return rataMiesieczna;
}

int Kredyt::getPozostaleMiesiace() const {
    return pozostaleMiesiaceSplaty;
}

void Kredyt::zmniejszMiesiace() {
    pozostaleMiesiaceSplaty--;
}

bool Kredyt::czyPrzeterminowany() const {
    return pozostaleMiesiaceSplaty < 0;
}