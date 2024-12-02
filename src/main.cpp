#include "firma.h"

#include <iostream>
#include <string>

// Wyświetla menu dla gracza
void wyswietlMenu() {
    std::cout << "\n=== MENU ===\n";
    std::cout << "1. Wyświetl stan firmy\n";
    std::cout << "2. Wyświetl pracowników\n";
    std::cout << "3. Zatrudnij pracownika\n";
    std::cout << "4. Weź kredyt\n";
    std::cout << "5. Zakończ miesiąc\n";
    std::cout << "0. Wyjdź z gry\n";
    std::cout << "Wybierz opcję: ";
}

// Sprawdza warunki zwycięstwa lub przegranej
bool sprawdzStanGry(const Firma& firma) {
    // Warunek zwycięstwa: wartość firmy (np. > 50 000 PLN)
    const double CEL_WARTOSCI_FIRMY = 50000;

    // Warunek przegranej: stan konta poniżej 0
    if (firma.getStanKonta() < 0) {
        std::cout << "\n=== KONIEC GRY ===\n";
        std::cout << "Twoja firma zbankrutowała! Stan konta wynosi: " << firma.getStanKonta() << " PLN.\n";
        return true;
    }

    // Warunek zwycięstwa
    if (firma.getWartoscFirmy() >= CEL_WARTOSCI_FIRMY) {
        std::cout << "\n=== KONIEC GRY ===\n";
        std::cout << "Gratulacje! Osiągnąłeś wartość firmy wynoszącą " << firma.getWartoscFirmy() << " PLN!\n";
        std::cout << "Twoja firma jest teraz liderem rynku.\n";
        return true;
    }

    return false; // Gra trwa dalej
}

int main() {
    // Inicjalizacja firmy z przykładowymi parametrami
    Firma firma;

    int opcja;
    bool graTrwa = true;

    while (graTrwa) {
        wyswietlMenu();
        std::cin >> opcja;

        switch (opcja) {
            case 1: {
                firma.wyswietlStanFirmy();
                break;
            }
            case 2: {
                firma.wyswietlPracownikow();
                break;
            }
            case 3: {
                std::cout << "Wybierz typ pracownika do zatrudnienia (inz, mag, mkt, rob): ";
                std::string typ;
                std::cin >> typ;

                firma.zatrudnijPracownika(typ);
                break;
            }
            case 4: {
                std::cout << "Podaj kwotę kredytu: ";
                double kwota;
                std::cin >> kwota;

                std::cout << "Podaj czas spłaty w miesiącach (maksymalnie 12): ";
                int czasSplaty;
                std::cin >> czasSplaty;

                firma.wezKredyt(kwota, czasSplaty);
                break;
            }
            case 5: {
                firma.zakonczMiesiac();

                // Sprawdzenie warunków gry po zakończeniu miesiąca
                if (sprawdzStanGry(firma)) {
                    graTrwa = false; // Zakończ pętlę gry
                }
                break;
            }
            case 0: {
                std::cout << "Dziękujemy za grę! Do zobaczenia!\n";
                graTrwa = false;
                break;
            }
            default: {
                std::cout << "Nieznana opcja. Spróbuj ponownie.\n";
                break;
            }
        }
    }

    return 0;
}