#include "duomenys.h"

using namespace std;
using namespace std::chrono;

// Funkcija generuoja atsitiktinius studentų duomenis ir išsaugo juos faile
void generuotiDuomenis(int studentuSk, const string &failoPavadinimas) {

    auto start = high_resolution_clock::now(); // Fiksuojame laiką (pradžia)
    ofstream file(failoPavadinimas);
    file << "Pavarde Vardas ND1 ND2 ND3 ND4 ND5 Egzaminas\n"; // Pirma failo eilutė

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 10);  // Generuojame pažymius nuo 1 iki 10

    // Generuojame studentų duomenis
    for (int i = 0; i < studentuSk; ++i) {
        string pavarde = "Pavarde" + to_string(i + 1);
        string vardas = "Vardas" + to_string(i + 1);

        // Generuojame 5 namų darbų pažymius
        int nd1 = dist(gen), nd2 = dist(gen), nd3 = dist(gen), nd4 = dist(gen), nd5 = dist(gen);

        // Generuojame egzamino pažymį
        int egzaminas = dist(gen);

        // Įrašome duomenis į failą
        file << pavarde << " " << vardas << " "
             << nd1 << " " << nd2 << " " << nd3 << " " << nd4 << " " << nd5 << " "
             << egzaminas << "\n";
    }

    file.close();

    auto end = high_resolution_clock::now(); // Fiksuojame laiką (pabaiga)
    auto duration_ms = duration_cast<milliseconds>(end - start);
    double duration_sec = duration_ms.count() / 1000.0; // Milisekundes konvertuojame į sekundes

    cout << "Sugeneruotas failas: " << failoPavadinimas << " su " << studentuSk << " studentais.\n";
    cout << "Sugeneravimo laikas: " << fixed << setprecision(3) << duration_sec << " sekundes\n";
}

// Funkcija apskaičiuoja galutinius rezultatus (pagal vidurkį arba medianą)
void skaiciavimai(list<Studentas>& studentai, int choice) {
    for (auto& studentas : studentai) {
        vector<int> nd = studentas.getNd(); // Paimame namų darbų pažymius
        int egz = studentas.getEgz();       // Paimame egzamino pažymį

        if (choice == 0) { 
            studentas.setNd(nd);  // Galutinis skaičiuojamas pagal vidurkį
            studentas.setEgz(egz);
        } else {
            studentas.setNd(nd);  // Medianai naudojamas ND sąrašas ir egzaminas
            double medGalutinis = mediana(nd, egz);
            // Nustatyti galima tik informaciniais tikslais (nėra tiesioginio metodo keisti galutinį pažymį)
        }
    }
}

// Funkcija dalija studentus į "kietiakus" ir "vargšiukus"
void padalintiStudentus(list<Studentas>& studentai, list<Studentas>& vargsiukai) {
    auto start = high_resolution_clock::now();

    auto it = partition(studentai.begin(), studentai.end(), [](const Studentas& s) {
        return s.getGalutinis() >= 5.0; // Vargšiukai yra tie, kurių galutinis pažymys mažesnis nei 5.0
    });

    vargsiukai.splice(vargsiukai.begin(), studentai, it, studentai.end());

    auto end = high_resolution_clock::now();
    auto duration_ms = duration_cast<milliseconds>(end - start);
    cout << "Padalinimo laikas: " << fixed << setprecision(3) << (duration_ms.count() / 1000.0) << " sekundės\n";
}

// Funkcija išveda "kietiakų" ir "vargšiukų" duomenis į atskirus failus
void isvestiIFailus(list<Studentas>& studentai, list<Studentas>& vargsiukai, int sort_choice) {
    auto start = high_resolution_clock::now();

    ofstream vargsiukaiFile("vargsiukai.txt");
    ofstream kietiakaiFile("kietiakai.txt");

    rikiuotiStudentus(studentai, sort_choice);
    rikiuotiStudentus(vargsiukai, sort_choice);

    // Įrašome vargšiukų duomenis
    vargsiukaiFile << "Pavarde Vardas Galutinis Balas\n";
    for (const auto& studentas : vargsiukai) {
        vargsiukaiFile << studentas.getPavarde() << " " 
                       << studentas.getVardas() << " " 
                       << fixed << setprecision(2) << studentas.getGalutinis() << "\n";
    }
    vargsiukaiFile.close();

    // Įrašome kietiakų duomenis
    kietiakaiFile << "Pavarde Vardas Galutinis Balas\n";
    for (const auto& studentas : studentai) {
        kietiakaiFile << studentas.getPavarde() << " " 
                      << studentas.getVardas() << " " 
                      << fixed << setprecision(2) << studentas.getGalutinis() << "\n";
    }
    kietiakaiFile.close();

    auto end = high_resolution_clock::now();
    auto duration_ms = duration_cast<milliseconds>(end - start);
    cout << "Failų išvedimo laikas: " << fixed << setprecision(3) << (duration_ms.count() / 1000.0) << " sekundės\n";
}

// Funkcija sugeneruoja atsitiktinius studento pažymius
void generuotiRandom(Studentas& x, int nd_kiekis) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 10);

    cout << "Atsitiktinai sugeneruoti namų darbų pažymiai: ";
    for (int i = 0; i < nd_kiekis; i++) {
        int random_pazymys = dist(gen);
        x.addNd(random_pazymys); // Pridedame ND į sąrašą ir perskaičiuojame galutinį pažymį
        cout << random_pazymys << " ";
    }

    int egzaminas = dist(gen);
    x.setEgz(egzaminas); // Nustatome egzamino pažymį
    cout << "\nSugeneruotas egzamino pažymys: " << egzaminas << "\n";
}

// Funkcija skaito studentų duomenis iš failo
void skaitytiIsFailo(const string& failo_adresas, list<Studentas>& studentai) {
    auto start = high_resolution_clock::now();

    ifstream file(failo_adresas);
    string eilute;
    getline(file, eilute); // Praleidžiame antraštę

    while (getline(file, eilute)) {
        stringstream ss(eilute);
        string vardas, pavarde;
        vector<int> nd;
        int egzaminas;

        // Nuskaitome vardą ir pavardę
        ss >> vardas >> pavarde;

        // Nuskaitome namų darbų pažymius
        int grade;
        while (ss >> grade) {
            nd.push_back(grade);
        }

        if (!nd.empty()) {
            egzaminas = nd.back(); // Paskutinis pažymys yra egzamino
            nd.pop_back();         // Jį pašaliname iš namų darbų sąrašo
        }

        Studentas studentas(vardas, pavarde, nd, egzaminas); // Sukuriame studento objektą
        studentai.push_back(studentas);
    }

    file.close();

    auto end = high_resolution_clock::now();
    auto duration_ms = duration_cast<milliseconds>(end - start);
    cout << "Failo nuskaitymo laikas: " << fixed << setprecision(3) << (duration_ms.count() / 1000.0) << " sekundės\n";
}