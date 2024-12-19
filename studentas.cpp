#include "Studentas.h"
#include <iostream>
#include <iomanip>
#include <numeric>
#include "ivedimas.h"
#include <algorithm> // for std::copy
#include <limits>

// Konstruktorius be parametrų
Studentas::Studentas() : Zmogus(), egz(0), galutinis(0.0) {}

// Konstruktorius su parametrais
Studentas::Studentas(const string& v, const string& p, const vector<int>& n, int e)
    : Zmogus(v, p), nd(n), egz(e) {
    calculateGalutinis(); // Apskaičiuoja galutinį balą
}

// Kopijavimo konstruktorius
Studentas::Studentas(const Studentas& other)
    : Zmogus(other.vardas, other.pavarde), nd(other.nd), egz(other.egz), galutinis(other.galutinis) {}

// Kopijavimo priskyrimo operatorius (užtikrina gilų kopijavimą)
Studentas& Studentas::operator=(const Studentas& other) {
    if (this != &other) { // Apsauga nuo priskyrimo sau pačiam
        vardas = other.vardas;
        pavarde = other.pavarde;
        nd = other.nd; // Kopijuojamas vektorius
        egz = other.egz;
        galutinis = other.galutinis;
    }
    return *this;
}

// Destruktorius
Studentas::~Studentas() {
    nd.clear(); // Atlaisvina atmintį, kurią užima namų darbų pažymiai
}

// Įvesties operatorius
istream& operator>>(istream& in, Studentas& s) {
    string input;

    // Įveda vardą
    cout << "Irasykite studento varda (ne daugiau nei 10 simboliu) arba paspauskite ENTER, kad baigtumete: ";
    getline(in, input);
    if (input.empty()) return in; // Jei vartotojas paspaudžia ENTER, sustabdomas įvedimas
    if (!arTeisinga(input)) { // Tikrinama, ar vardas teisingas
        cout << "Netinkamas vardas. Bandykite dar karta.\n";
        return in;
    }
    s.setVardas(input);

    // Įveda pavardę
    cout << "Irasykite studento pavarde (ne daugiau nei 10 simboliu): ";
    getline(in, input);
    if (input.empty()) return in; // Jei vartotojas paspaudžia ENTER, sustabdomas įvedimas
    if (!arTeisinga(input)) { // Tikrinama, ar pavardė teisinga
        cout << "Netinkama pavarde. Bandykite dar karta.\n";
        return in;
    }
    s.setPavarde(input);

    // Pasirinkimas generuoti atsitiktinius pažymius ar įvesti ranka
    int choice;
    cout << "Ar norite atsitiktinai sugeneruoti namu darbu ir egzamino pazymius?\n";
    cout << "0 - Ne, ivesiu ranka\n";
    cout << "1 - Taip, sugeneruok atsitiktinai\n";     
    while (true) {
        cout << "Iveskite pasirinkima (1 arba 0): ";
        if (!(in >> choice) || (choice != 0 && choice != 1)) { // Netinkamas pasirinkimas
            cout << "Neteisingas pasirinkimas. Bandykite dar karta.\n";
            in.clear(); // Išvaloma klaida
            in.ignore(numeric_limits<streamsize>::max(), '\n'); // Išvalomas neteisingas įvestis
        } else {
            in.ignore(numeric_limits<streamsize>::max(), '\n'); // Išvalomas naujos eilutės simbolis
            break;
        }
    }
    
    if (choice == 1) {
        // Sugeneruojami atsitiktiniai pažymiai
        int nd_kiekis;
        cout << "Kiek norite sugeneruoti namu darbu pazymiu? (Ne daugiau nei 10 000): ";
        while (!(in >> nd_kiekis) || nd_kiekis < 0 || nd_kiekis > 10000) { // Patikrinamas skaičius
            cout << "Iveskite teisinga skaiciu: ";
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n'); // Išvalomas neteisingas įvestis
        }

        generuotiRandom(s, nd_kiekis);  // Sugeneruojami pažymiai

        in.ignore(numeric_limits<streamsize>::max(), '\n'); // Išvalomas buferis
    } else {
        // Rankinis namų darbų pažymių įvedimas
        cout << "Irasykite namu darbu pazymius (nuo 0 iki 10). Noredami baigti ivesti pazymius, paspauskite ENTER:\n";
        int pazymys;
        while (true) {
            cout << "Irasykite pazymi: ";
            getline(in, input);
            if (input.empty()) break; // Sustojama, jei įvesta tuščia eilutė

            try {
                pazymys = stoi(input);
                if (pazymys < 0 || pazymys > 10) { // Pažymys turi būti tarp 0 ir 10
                    throw out_of_range("Pazymys turi buti tarp 0 ir 10.");
                }
                s.addNd(pazymys);  // Pridedamas pažymys
            } catch (invalid_argument&) {
                cout << "Iveskite teisinga pazymi (skaiciu nuo 0 iki 10).\n";
            } catch (out_of_range& e) {
                cout << e.what() << endl;
            }
        }
        
        // Egzamino pažymio įvedimas
        cout << "Irasykite egzamino pazymi: ";
        while (true) {
            getline(in, input);
            try {
                pazymys = stoi(input);
                if (pazymys < 0 || pazymys > 10) { // Egzamino pažymys turi būti tarp 0 ir 10
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

// Gauk namų darbų pažymius
vector<int> Studentas::getNd() const {
    return nd;
}

// Nustato namų darbų pažymius ir perskaičiuoja galutinį balą
void Studentas::setNd(const vector<int>& n) {
    nd = n;
    calculateGalutinis();
}

// Gauk egzamino pažymį
int Studentas::getEgz() const {
    return egz;
}

// Nustato egzamino pažymį ir perskaičiuoja galutinį balą
void Studentas::setEgz(int e) {
    egz = e;
    calculateGalutinis();
}

// Gauk galutinį balą (modifikuojama versija)
double& Studentas::getGalutinis() {
    return galutinis;
}

// Gauk galutinį balą (tik skaitymui)
const double& Studentas::getGalutinis() const {
    return galutinis;
}

// Skaičiuoja galutinį pažymį (privati funkcija)
void Studentas::calculateGalutinis() {
    if (!nd.empty()) { // Jei yra namų darbų pažymių
        double nd_avg = accumulate(nd.begin(), nd.end(), 0.0) / nd.size();
        galutinis = 0.4 * nd_avg + 0.6 * egz;
    } else { // Jei nėra namų darbų pažymių
        galutinis = 0.6 * egz;
    }
}

// Prideda namų darbų pažymį ir perskaičiuoja galutinį balą
void Studentas::addNd(int grade) {
    nd.push_back(grade);
    calculateGalutinis();
}

// Pateikia studento informaciją kaip eilutę
string Studentas::toString() const {
    stringstream ss;
    ss << "Vardas: " << vardas << ", Pavarde: " << pavarde << ", Galutinis: " << fixed << setprecision(2) << galutinis;
    return ss.str();
}
