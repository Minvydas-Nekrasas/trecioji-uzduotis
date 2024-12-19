#include "ivedimas.h"

using namespace std;

bool arTeisinga(const string& name) {
    if (name.empty() || name.length() > 10) return false;
    for (char ch : name) {
        if (!isalpha(ch)) return false; // Tik leidžiami skaičiai
    }
    return true;
}

void nuskaitymas(list<Studentas>& studentai) {
    string input;
    int pazymys;
    cout << "Ar norite nuskaityti duomenis is failo? (1 - Taip, 0 - Ne): ";
    int readFromFile;
    cin >> readFromFile;

    if (readFromFile == 1) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear newline after input
        string failo_adresas;
        while (true) {
            cout << "Iveskite failo adresa: ";
            getline(cin, failo_adresas);

            ifstream file(failo_adresas);  // Try opening the file
            if (file.is_open()) {
                file.close();  // If successful, close the file
                skaitytiIsFailo(failo_adresas, studentai); // Load data from the file
                break;  // Exit loop after successful loading
            } else {
                cout << "Nepavyko atidaryti failo! Bandykite dar karta.\n";
            }
        }
    } else {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear newline after input
        cout << "Noredami baigti ivesti studentus, paspauskite ENTER du kartus.\n";

        while (true) {
            Studentas x;

            // Use operator>> to input student data
            cout << "\nIveskite studento duomenis:\n";
            cin >> x;  // Use the operator>> to collect all input for the student

            if (cin.eof()) break;  // If user presses ENTER twice, stop input

            // Add student to the list after collecting data
            studentai.push_back(x);

            // Ask if the user wants to add another student
            cout << "Ar norite prideti kita studenta? (y/n): ";
            getline(cin, input);
            if (input == "n" || input == "N") {
                break;
            }
        }
    }
}
