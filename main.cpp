#ifndef TESTING
#include <iostream>
#include <iomanip>
#include <limits> // numeric_limits
#include <vector>
#include "duomenys.h"
#include "ivedimas.h"
#include "rikiavimas.h"
#include "vertinimas.h"
#include "rezultatas.h"
#include <fstream>
#include <random>
#include <chrono>
#include <list>
#include "Zmogus.h"

using namespace std; // Kad būtų galima naudoti std be prefikso (pvz., std::string -> string)

int main(){
    // Pradinis studento objekto pavyzdys
    Studentas a;
    cin >> a; // Įvedame pirmą studentą
    Studentas b = a; // Sukuriame kopiją pirmojo studento
    cin >> b; // Įvedame antrą studentą

    // Spausdiname rezultatus
    cout << "\nRezultatai:\n";
    cout << "Studentas 1: " << a << endl;
    cout << "Studentas 2: " << b << endl;
    cout << a.toString() << endl;

    list<Studentas> studentai; // Sąrašas studentų duomenims saugoti
    int choice; // Kintamasis pasirinkimui išsaugoti

    // Pasirinkimas sugeneruoti failus su atsitiktiniais duomenimis
    cout << "\nPasirinkite ar norite sugeneruoti failus su atsitiktiniais duomenimis:\n";
    cout << "0 - Sugeneruoti failus\n";
    cout << "1 - Ne\n";
    while (true) {
        cout << "Iveskite pasirinkima (0 arba 1): ";
        if (!(cin >> choice) || (choice != 0 && choice != 1)) {
            cout << "Ivestas neteisingas simbolis. Bandykite dar karta.\n";
            cin.clear(); // Išvalome klaidos būseną
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Praleidžiame iki kitos eilutės
            continue;
        } else {
            break;
        }
    }

    // Jeigu pasirinkta sugeneruoti duomenis
    if (choice == 0) {
        // Generuojame failus su skirtingais studentų skaičiais
        generuotiDuomenis(1000, "studentai_1000.txt");
        generuotiDuomenis(10000, "studentai_10000.txt");
        generuotiDuomenis(100000, "studentai_100000.txt");
        generuotiDuomenis(1000000, "studentai_1000000.txt");
        generuotiDuomenis(10000000, "studentai_10000000.txt");
    }

    // Nuskaitome studentų duomenis iš failų
    nuskaitymas(studentai);

    // Pasirinkimas, pagal ką skaičiuoti galutinį pažymį
    cout << "\nPasirinkite, ka norite apskaiciuoti:\n";
    cout << "0 - Galutinis pazymys pagal vidurki\n";
    cout << "1 - Galutinis pazymys pagal mediana\n";

    while (true) {
        cout << "Iveskite pasirinkima (1 arba 0): ";
        if (!(cin >> choice) || (choice != 0 && choice != 1)) {
            cout << "Ivestas neteisingas simbolis. Bandykite dar karta.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else {
            break;
        }
    }

    // Skaičiuojame galutinius pažymius pagal pasirinktą metodą
    skaiciavimai(studentai, choice);

    // Padaliname studentus į "vargsiukus" ir kitus
    list<Studentas> vargsiukai;
    padalintiStudentus(studentai, vargsiukai);

    // Pasirinkimas, pagal ką rikiuoti studentus
    int sort_choice;
    cout << "\nPasirinkite, pagal ka norite surikiuoti studentus:\n";
    cout << "0 - Rikiuoti pagal pavarde\n";
    cout << "1 - Rikiuoti pagal varda\n";
    cout << "2 - Rikiuoti pagal galutini pazymi\n";

    while (true) {
        cout << "Iveskite pasirinkima (0, 1 arba 2): ";
        if (!(cin >> sort_choice) || (sort_choice < 0 || sort_choice > 2)) {
            cout << "Ivestas neteisingas simbolis. Bandykite dar karta.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        } else {
            break;
        }
    }

    // Rikiuojame studentus pagal pasirinktą kriterijų
    rikiuotiStudentus(studentai, sort_choice);
    
    // Išsaugome rezultatus į failus
    isvestiIFailus(studentai, vargsiukai, sort_choice);

    // Pasirinkimas spausdinti rezultatus terminale ar išeiti iš programos
    int final_choice;
    cout << "\nPasirinkite:\n";
    cout << "0 - Spausdinti rezultatus i terminala\n";
    cout << "1 - Iseiti is programos\n";

    while (true) {
        cout << "Iveskite pasirinkima (0 arba 1): ";
        if (!(cin >> final_choice) || (final_choice != 0 && final_choice != 1)) {
            cout << "Ivestas neteisingas simbolis. Bandykite dar karta.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        } else {
            break;
        }
    }

    // Jei pasirinkta spausdinti, spausdiname rezultatus
    if (final_choice == 0) {
        spausdinti(studentai, choice);
    } else {
        // Jei pasirinkta išeiti, informuojame vartotoją ir užbaigiame programą
        cout << "Programa baigta.\n";
    }

    return 0; // Programa baigta sėkmingai
}
#endif // End of TESTING