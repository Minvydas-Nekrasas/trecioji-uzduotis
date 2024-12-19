#include "ivedimas.h"

using namespace std;

// Funkcija patikrina, ar įvestas vardas/pavardė atitinka taisykles
// Leidžiami tik raidiniai simboliai, tekstas negali būti tuščias ar ilgesnis nei 10 simbolių
bool arTeisinga(const string& name) {
    if (name.empty() || name.length() > 10) return false; // Patikrina ilgį
    for (char ch : name) {
        if (!isalpha(ch)) return false; // Patikrina, ar yra tik raidiniai simboliai
    }
    return true;
}

// Funkcija, kuri nuskaito studentų duomenis
void nuskaitymas(list<Studentas>& studentai) {
    string input; // Laikinas kintamasis įvedimui
    int pazymys;  // Laikinas kintamasis pažymiams
    cout << "Ar norite nuskaityti duomenis is failo? (1 - Taip, 0 - Ne): ";
    int readFromFile; // Kintamasis vartotojo pasirinkimui saugoti
    cin >> readFromFile;

    // Jei pasirinkta nuskaityti duomenis iš failo
    if (readFromFile == 1) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Išvalome buvusią eilutę po įvesties
        string failo_adresas;

        // Prašome vartotojo įvesti tinkamą failo adresą
        while (true) {
            cout << "Iveskite failo adresa: ";
            getline(cin, failo_adresas);

            // Bandome atidaryti failą
            ifstream file(failo_adresas);
            if (file.is_open()) {
                file.close(); // Jei failas sėkmingai atidarytas, uždarome
                skaitytiIsFailo(failo_adresas, studentai); // Nuskaitome duomenis iš failo
                break; // Baigiame ciklą po sėkmingo nuskaitymo
            } else {
                cout << "Nepavyko atidaryti failo! Bandykite dar karta.\n"; // Jei klaida, pranešame vartotojui
            }
        }
    } else { // Jei nuskaitymas iš failo nepasirinktas, įvedame duomenis rankiniu būdu
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Išvalome buvusią eilutę po įvesties
        cout << "Noredami baigti ivesti studentus, paspauskite ENTER du kartus.\n";

        while (true) {
            Studentas x; // Kuriame naują studento objektą

            // Naudojame operatorių >>, kad įvestume studento duomenis
            cout << "\nIveskite studento duomenis:\n";
            cin >> x; // Operatorius >> apdoroja visą reikalingą įvestį studentui

            if (cin.eof()) break; // Jei vartotojas paspaudžia ENTER du kartus, baigiame įvedimą

            // Pridėti studentą į sąrašą
            studentai.push_back(x);

            // Paklausiame, ar vartotojas nori pridėti kitą studentą
            cout << "Ar norite prideti kita studenta? (y/n): ";
            getline(cin, input);
            if (input == "n" || input == "N") {
                break; // Jei "n", sustabdome ciklą
            }
        }
    }
}
