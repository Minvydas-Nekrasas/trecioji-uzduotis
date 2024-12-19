#include "duomenys.h"


using namespace std;
using namespace std::chrono;

void generuotiDuomenis(int studentuSk, const string &failoPavadinimas) {

    auto start = high_resolution_clock::now(); // fiksuojam laiką (pradžia)
    ofstream file(failoPavadinimas);
    file << "Pavarde Vardas ND1 ND2 ND3 ND4 ND5 Egzaminas\n"; // Pirma failo eilutė

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 10);  // Generuojam pažymius nuo 1 iki 10

    for (int i = 0; i < studentuSk; ++i) {
        string pavarde = "Pavarde" + to_string(i + 1);
        string vardas = "Vardas" + to_string(i + 1);

        // Generuojam 5 namų darbų pažymius
        int nd1 = dist(gen);
        int nd2 = dist(gen);
        int nd3 = dist(gen);
        int nd4 = dist(gen);
        int nd5 = dist(gen);

        // Generuojam egzamino pažymį
        int egzaminas = dist(gen);

        // Įrašom duomenis į failą
        file << pavarde << " " << vardas << " "
             << nd1 << " " << nd2 << " " << nd3 << " " << nd4 << " " << nd5 << " "
             << egzaminas << "\n";
    }

    file.close();

    // fiksuojam laiką (pabaiga)
    auto end = high_resolution_clock::now();
    
    // Paskaičiuojam trukmę
    auto duration_ms = duration_cast<milliseconds>(end - start);

    // Milisekundes paverčiam į sekundes
    double duration_sec = duration_ms.count() / 1000.0;


    cout << "Sugeneruotas failas: " << failoPavadinimas << " su " << studentuSk << " studentais.\n";
    cout << "Sugeneravimo laikas: " << fixed << setprecision(3) << duration_sec << " sekundes\n";
}
void skaiciavimai(list<Studentas>& studentai, int choice) {
    for (auto& studentas : studentai) {
        vector<int> nd = studentas.getNd(); // Get current homework scores
        int egz = studentas.getEgz();       // Get current exam score
        
        if (choice == 0) { 
            studentas.setNd(nd);  // Set ND (recalculates `galutinis` based on average)
            studentas.setEgz(egz); 
        } else {
            studentas.setNd(nd);  // Median-based calculation happens outside
            double medGalutinis = mediana(nd, egz);
            // Since we cannot directly set `galutinis`, use this for computation reference.
        }
    }
}
void padalintiStudentus(list<Studentas>& studentai, list<Studentas>& vargsiukai) {
    auto start = high_resolution_clock::now();
    
    // Partition students into "vargšiukai" and "kietiakai"
    auto it = partition(studentai.begin(), studentai.end(), [](const Studentas& s) {
        return s.getGalutinis() >= 5.0; // Use getter for galutinis
    });

    // Move "vargšiukai" into their own list
    vargsiukai.splice(vargsiukai.begin(), studentai, it, studentai.end());
    
    auto end = high_resolution_clock::now();
    auto duration_ms = duration_cast<milliseconds>(end - start);
    cout << "Padalinimo laikas: " << fixed << setprecision(3) << (duration_ms.count() / 1000.0) << " sekundės\n";
}


void isvestiIFailus(list<Studentas>& studentai, list<Studentas>& vargsiukai, int sort_choice) {
    auto start = high_resolution_clock::now();

    // Open files in text mode
    ofstream vargsiukaiFile("vargsiukai.txt");
    ofstream kietiakaiFile("kietiakai.txt");

    // Sort lists before writing
    rikiuotiStudentus(studentai, sort_choice);
    rikiuotiStudentus(vargsiukai, sort_choice);

    // Write vargšiukai data
    vargsiukaiFile << "Pavarde Vardas Galutinis Balas\n";
    for (const auto& studentas : vargsiukai) {
        vargsiukaiFile << studentas.getPavarde() << " " 
                       << studentas.getVardas() << " " 
                       << fixed << setprecision(2) << studentas.getGalutinis() << "\n";
    }
    vargsiukaiFile.close();

    // Write kietiakai data
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

// Funkcija atsitiktinių rezultatų generavimui
void generuotiRandom(Studentas& x, int nd_kiekis) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 10);

    cout << "Atsitiktinai sugeneruoti namų darbų pažymiai: ";
    for (int i = 0; i < nd_kiekis; i++) {
        int random_pazymys = dist(gen);
        x.addNd(random_pazymys); // Use addNd to add grades and recalculate
        cout << random_pazymys << " ";
    }

    int egzaminas = dist(gen);
    x.setEgz(egzaminas); // Use setter for exam score
    cout << "\nSugeneruotas egzamino pažymys: " << egzaminas << "\n";
}

// Funkcija skirta perskaityti studento duomenis iš failo
void skaitytiIsFailo(const string& failo_adresas, list<Studentas>& studentai) {
    auto start = high_resolution_clock::now();

    ifstream file(failo_adresas);
    string eilute;
    getline(file, eilute); // Skip the header

    while (getline(file, eilute)) {
        stringstream ss(eilute);
        string vardas, pavarde;
        vector<int> nd;
        int egzaminas;

        // Read name and surname
        ss >> vardas >> pavarde;

        // Read homework grades
        int grade;
        while (ss >> grade) {
            nd.push_back(grade);
        }

        if (!nd.empty()) {
            egzaminas = nd.back(); // Last grade is the exam score
            nd.pop_back();         // Remove it from homework grades
        }

        // Create a Studentas instance and set values
        Studentas studentas(vardas, pavarde, nd, egzaminas);
        studentai.push_back(studentas);
    }

    file.close();

    auto end = high_resolution_clock::now();
    auto duration_ms = duration_cast<milliseconds>(end - start);
    cout << "Failo nuskaitymo laikas: " << fixed << setprecision(3) << (duration_ms.count() / 1000.0) << " sekundės\n";
}
