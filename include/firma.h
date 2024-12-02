#ifndef FIRMA_H
#define FIRME_H


#include "pracownik.h"
#include "kredyt.h"
#include <vector>
#include <memory>
#include <string>
const double poczatkowyStanKonta = 1000;
const  double ci = 1.04;
const  double cmag = 2;
const  double cmkt = 1;
const  double cr = 0.7;
const  int x = 30;
const  double m = 1;


class Firma{
public:
    //lista pracownikow
    std::vector<std::unique_ptr<Pracownik>> pracownicy;
    //obecny stan konta
    double stanKonta;
    //maksymalna pojemnosc magazynu
    int maxMagazyn;
    //liczba produktow w magazynie
    int aktMagazyn;
    //lista aktywnych kredytow
    std::vector<Kredyt> kredyty;
    double przychod;
    double zadluzenie;
    double dochod;
    const float CI;
    const float CMag;
    const float CMkt;
    const float CR;
    //maksymalny czas splaty kredytu
    const int X;
    //max stosunek zadluzenia do wartosci spolki
    const double M;

    Firma();
    void wyswietlPracownikow() const;
    void wezKredyt(double kwota, int czasSplaty);
    void zatrudnijPracownika(const std::string& typ);
    void zakonczMiesiac();


    void wyswietlStanFirmy() const;

    double getStanKonta() const; // Zwraca stan konta
    double getWartoscFirmy() const; // Zwraca wartość firmy
    void obsluzKredyty();

};


#endif //FIRMA_H