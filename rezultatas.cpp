#include "rezultatas.h"
#include <iomanip>
#include <sstream>
#include <iostream>

using namespace std;

// Funkcija, skirta atspausdinti studentų duomenis
void spausdinti(const list<Studentas>& studentai, bool choice) {
    string pasirinkimas_pav;

    // Nustatomas stulpelio pavadinimas priklausomai nuo pasirinkimo: vidurkis arba mediana
    if (choice == 0) {
        pasirinkimas_pav = "(Vid.)";  // Pasirinkta naudoti vidurkį
    } else {
        pasirinkimas_pav = "(Med.)";  // Pasirinkta naudoti medianą
    }

    stringstream buffer;  // Naudojamas stringstream, kad būtų galima surinkti visus duomenis prieš spausdinimą

    // Generuojamas lentelės antraštės formatas
    buffer << "\n-----------------------------------------------------------------------------------------------------------------------------------------\n";
    buffer << left << setw(10) << "Pavardė" // Pirmosios stulpelio antraštė
           << setw(10) << "" << "Vardas"   // Antrosios stulpelio antraštė
           << setw(10) << "" << "Galutinis " << pasirinkimas_pav << endl; // Galutinio pažymio stulpelio antraštė
    buffer << "-----------------------------------------------------------------------------------------------------------------------------------------\n";

    // Ciklas per kiekvieną studentų sąrašo elementą
    for (const auto& studentas : studentai) {
        buffer << left << setw(10) << studentas.getPavarde()  // Atspausdinama pavardė
               << setw(10) << "" << studentas.getVardas()    // Atspausdinamas vardas
               << setw(15) << "" << fixed << setprecision(2) << studentas.getGalutinis() << endl;  // Atspausdinamas galutinis pažymys su dviem dešimtainėmis tikslumu
    }

    // Išvedami visi surinkti duomenys į ekraną vienu kartu
    cout << buffer.str() << flush;
}
