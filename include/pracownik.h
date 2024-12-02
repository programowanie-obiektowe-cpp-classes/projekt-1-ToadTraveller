#ifndef PRACOWNIK_H
#define PRACOWNIK_H

#include <string>
#include <iostream>


class Pracownik {
public:
    std::string imie;
    
    Pracownik();
    virtual ~Pracownik() = default;
    virtual void wyswietlInformacje() const;
    virtual double getWynagrodzenie() const = 0;
    
};





class Inzynier : public Pracownik {
public:
    std::string wydzial;
    double wynagrodzenie;


    Inzynier();
    void wyswietlInformacje() const override;
    double getWynagrodzenie() const override;
    //zwieksza wartosc produktu
    

};




class Magazynier : public Pracownik {
public:
    bool wozek_widlowy;
    double wynagrodzenie;

    Magazynier();
    //zwieksza pojemnosc magazynu
    void wyswietlInformacje() const;
    double getWynagrodzenie() const override;

};
class Marketer : public Pracownik {
public:
    int followers;
    double wynagrodzenie;

    Marketer();    
    //zwieksza liczbe sprzedanych co miesiac produktow
    void wyswietlInformacje() const;
    double getWynagrodzenie() const override;

};
class Robotnik : public Pracownik {
public:
    float shoe_size;
    
    double wynagrodzenie;

    Robotnik();
    //produkuje produkty
    void wyswietlInformacje() const;
    double getWynagrodzenie() const override;

};

#endif //PRACOWNIK_H