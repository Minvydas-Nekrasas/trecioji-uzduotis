#include "rezultatas.h"
#include <iomanip>
#include <sstream>
#include <iostream>

using namespace std;

// Atspausdinam studentų duomenis
void spausdinti(const list<Studentas>& studentai, bool choice) {
    string pasirinkimas_pav;

    if (choice == 0) {
        pasirinkimas_pav = "(Vid.)";
    } else {
        pasirinkimas_pav = "(Med.)";
    }

    stringstream buffer;  // naudojam stringstream

    buffer << "\n-----------------------------------------------------------------------------------------------------------------------------------------\n";
    buffer << left << setw(10) << "Pavardė"
           << setw(10) << "" << "Vardas"
           << setw(10) << "" << "Galutinis "
           << pasirinkimas_pav << endl;
    buffer << "-----------------------------------------------------------------------------------------------------------------------------------------\n";

    for (const auto& studentas : studentai) {
        buffer << left << setw(10) << studentas.getPavarde()
               << setw(10) << "" << studentas.getVardas()
               << setw(15) << "" << fixed << setprecision(2) << studentas.getGalutinis()<< endl;
    }

    cout << buffer.str() << flush;  // viską atspausdinam vienu metu
}
