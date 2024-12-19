#include "Studentas.h"
#include <iostream>
#include <iomanip>
#include <numeric>
#include "ivedimas.h"
#include <algorithm> // for std::copy
#include <limits>

Studentas::Studentas() : Zmogus(), egz(0), galutinis(0.0) {}

Studentas::Studentas(const string& v, const string& p, const vector<int>& n, int e)
    : Zmogus(v, p), nd(n), egz(e) {
    calculateGalutinis();
}

Studentas::Studentas(const Studentas& other)
    : Zmogus(other.vardas, other.pavarde), nd(other.nd), egz(other.egz), galutinis(other.galutinis) {}

// Copy assignment operator (deep copy)
Studentas& Studentas::operator=(const Studentas& other) {
    if (this != &other) { // Avoid self-assignment
        vardas = other.vardas;
        pavarde = other.pavarde;
        nd = other.nd; // Vektorius
        egz = other.egz;
        galutinis = other.galutinis;
    }
    return *this;
}

// Destruktorius
Studentas::~Studentas() {
    nd.clear();
}

// Įvesties operatorius
istream& operator>>(istream& in, Studentas& s) {
    string input;

    // Input for first name
    cout << "Irasykite studento varda (ne daugiau nei 10 simboliu) arba paspauskite ENTER, kad baigtumete: ";
    getline(in, input);
    if (input.empty()) return in; // If user presses ENTER, stop input
    if (!arTeisinga(input)) {
        cout << "Netinkamas vardas. Bandykite dar karta.\n";
        return in;
    }
    s.setVardas(input);

    // Input for last name
    cout << "Irasykite studento pavarde (ne daugiau nei 10 simboliu): ";
    getline(in, input);
    if (input.empty()) return in; // If user presses ENTER, stop input
    if (!arTeisinga(input)) {
        cout << "Netinkama pavarde. Bandykite dar karta.\n";
        return in;
    }
    s.setPavarde(input);

    // Ask if random grades should be generated
    int choice;
    cout << "Ar norite atsitiktinai sugeneruoti namu darbu ir egzamino pazymius?\n";
    cout << "0 - Ne, ivesiu ranka\n";
    cout << "1 - Taip, sugeneruok atsitiktinai\n";     
    while (true) {
        cout << "Iveskite pasirinkima (1 arba 0): ";
        if (!(in >> choice) || (choice != 0 && choice != 1)) {
            cout << "Neteisingas pasirinkimas. Bandykite dar karta.\n";
            in.clear(); // Clear error state
            in.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear invalid input
        } else {
            in.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear newline after input
            break;
        }
    }
    
    if (choice == 1) {
        // Generate random grades for homework and exam
        int nd_kiekis;
        cout << "Kiek norite sugeneruoti namu darbu pazymiu? (Ne daugiau nei 10 000): ";
        while (!(in >> nd_kiekis) || nd_kiekis < 0 || nd_kiekis > 10000) {
            cout << "Iveskite teisinga skaiciu: ";
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear invalid input
        }

        generuotiRandom(s, nd_kiekis);  // Generate random grades for the student

        in.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the buffer
    } else {
        // Manually enter homework grades
        cout << "Irasykite namu darbu pazymius (nuo 0 iki 10). Noredami baigti ivesti pazymius, paspauskite ENTER:\n";
        int pazymys;
        while (true) {
            cout << "Irasykite pazymi: ";
            getline(in, input);
            if (input.empty()) break;

            try {
                pazymys = stoi(input);
                if (pazymys < 0 || pazymys > 10) {
                    throw out_of_range("Pazymys turi buti tarp 0 ir 10.");
                }
                s.addNd(pazymys);  // Add grade using the setter method
            } catch (invalid_argument&) {
                cout << "Iveskite teisinga pazymi (skaiciu nuo 0 iki 10).\n";
            } catch (out_of_range& e) {
                cout << e.what() << endl;
            }
        }
        
        cout << "Irasykite egzamino pazymi: ";
        while (true) {
            getline(in, input);
            try {
                pazymys = stoi(input);
                if (pazymys < 0 || pazymys > 10) {
                    throw out_of_range("Egzamino pazymys turi buti tarp 0 ir 10.");
                }
                s.setEgz(pazymys);
                break;
            } catch (invalid_argument&) {
                cout << "Iveskite teisinga egzamino pazymi (skaiciu nuo 0 iki 10).\n";
            } catch (out_of_range& e) {
                cout << e.what() << endl;
            }
        }
    }

    return in;
}


// Išvesties operatorius
ostream& operator<<(ostream& out, const Studentas& s) {
    out << setw(15) << left << s.vardas
        << setw(15) << left << s.pavarde
        << setw(10) << left << fixed << setprecision(2) << s.galutinis;
    return out;
}


vector<int> Studentas::getNd() const {
    return nd;
}

void Studentas::setNd(const vector<int>& n) {
    nd = n;
    calculateGalutinis();
}


int Studentas::getEgz() const {
    return egz;
}

void Studentas::setEgz(int e) {
    egz = e;
    calculateGalutinis();
}


double& Studentas::getGalutinis() {
    return galutinis;
}

const double& Studentas::getGalutinis() const {
    return galutinis;
}

// Privatus metodas galutinio pažymio skaičiavimui
void Studentas::calculateGalutinis() {
    if (!nd.empty()) {
        double nd_avg = accumulate(nd.begin(), nd.end(), 0.0) / nd.size();
        galutinis = 0.4 * nd_avg + 0.6 * egz;
    } else {
        galutinis = 0.6 * egz;
    }
}

void Studentas::addNd(int grade) {
    nd.push_back(grade);
    calculateGalutinis();
}
string Studentas::toString() const {
    stringstream ss;
    ss << "Vardas: " << vardas << ", Pavarde: " << pavarde << ", Galutinis: " << fixed << setprecision(2) << galutinis;
    return ss.str();
}