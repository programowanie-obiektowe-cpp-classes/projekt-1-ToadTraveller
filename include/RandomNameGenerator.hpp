#ifndef RANDOM_NAME_GENERATOR_HPP
#define RANDOM_NAME_GENERATOR_HPP

#include <array>
#include <random>
#include <string>
#include <sstream>

inline constexpr std::array first_names{
    "Aric", "Elira", "Thalion", "Eldrin", "Lirael", "Gorim", "Aeliana", "Faelan",
    "Althea", "Korath", "Miriel", "Darian", "Seraphina", "Veldrin", "Keldor", 
    "Sylas", "Isolde", "Ronan", "Faeryn", "Thalindra", "Balen", "Gweneth", 
    "Cyril", "Nymeria"
};

inline constexpr std::array last_names{
    "Burzowędrowiec", "Żelaznopiętka", "Ciemnoskalny", "Ogniażłobek", "Księżycowycieka", 
    "Srebrnywiatr", "Wiatrowędrowiec", "Ciemnawoda", "Ciernosiła", "Szybkoostrze", 
    "Mrocznekserca", "Kruczoskrzydły", "Kamiennopięść", "Jastrzębimiecz", "Lodowawal", 
    "Czarnykrzew", "Dzikoskrzyp", "Świtanolotny", "Fiołkowekiść", "Nocnyszepcz", 
    "Gwiezdnyognień", "Żarowypiorun", "Jaskółkaliść", "Krwiokamień", "Kamiennychom"
};

inline constexpr std::array wydzial{
    "Magia i Technologia", "Inżynieria Runiczna", "Mechanika Żywiołów", 
    "Cybernetyka Wymiarowa", "Inżynieria Mocy Arcane", "Biotechnologia Magów", 
    "Inżynieria Powietrzna", "Technologie Czarodziejskie", "Inżynieria Maszyn Latania", 
    "Budownictwo Kosmiczne", "Robotyka Runiczna", "Nanotechnologia Eliksirów", 
    "Inżynieria Energetyczna", "Astronomia i Przestrzeń Wymiarowa", 
    "Inżynieria Warstw Rzeczywistości", "Projektowanie Broni Magicznych", 
    "Inżynieria Zrównoważonego Rozwoju", "Magiczne Materiały Inżynierskie", 
    "Konstrukcja Golemów", "Technologie Enklaw", "Inżynieria Portalowa", 
    "Inżynieria Zjawisk Czasoprzestrzennych", "Technologie Przemiany Metali", 
    "Transport Międzywymiarowy"
};

inline auto getRandomName() -> std::string {
    static auto prng = std::mt19937{std::random_device{}()};
    auto fnd = std::uniform_int_distribution<std::size_t>{0, first_names.size() - 1};
    auto lnd = std::uniform_int_distribution<std::size_t>{0, last_names.size() - 1};

    const auto first_name = first_names[fnd(prng)];
    const auto last_name = last_names[lnd(prng)];

    // Łączenie imienia i nazwiska w jeden ciąg znaków
    std::stringstream ss;
    ss << first_name << " " << last_name;
    return ss.str();
}

inline auto getWydzial() -> std::string {
    static auto prng = std::mt19937{std::random_device{}()};
    auto fnd = std::uniform_int_distribution<std::size_t>{0, wydzial.size() - 1};

    const auto department = wydzial[fnd(prng)];

    return department;
}

inline auto getBut() -> float {
    static auto prng = std::mt19937{std::random_device{}()};
    auto fnd = std::uniform_real_distribution<float>{35.0f, 50.0f};

    const auto shoe_size = fnd(prng);
    return shoe_size;
}

inline auto getFollow() -> int {
    static auto prng = std::mt19937{std::random_device{}()};
    auto fnd = std::uniform_int_distribution<int>{0, 1000000};

    const auto followers_count = fnd(prng);
    return followers_count;
}

inline auto getWozek() -> bool {
    static auto prng = std::mt19937{std::random_device{}()};
    auto fnd = std::uniform_int_distribution<int>{0, 1};

    const auto result = fnd(prng);
    return result == 1;
}
#endif // RANDOM_NAME_GENERATOR_HPP
