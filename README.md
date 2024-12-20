# Studentų Rezultatų Skaičiavimo Sistema (v0.1)

Tai yra C++ programa, kuri apskaičiuoja studentų galutinius pažymius pagal namų darbų ir egzamino rezultatus.
Programa leidžia vartotojui įvesti studentų informaciją (vardą, pavardę, namų darbų ir egzamino pažymius) rankiniu būdu arba sugeneruoti juos atsitiktinai. Kodas gali apskaičiuoti galutinį pažymį pagal vidurkį arba medianą, atsižvelgiant į namų darbų pažymius ir egzaminą. Taip pat galima rūšiuoti studentus pagal vardą arba pavardę ir atspausdinti galutinius rezultatus lentelės formatu.
## Turinys
1. [Funkcionalumas](#funkcionalumas)
2. [Failų Struktūra](#failų-struktūra)
3. [Kompiliavimas ir Paleidimas](#kompiliavimas-ir-paleidimas)
4. [Naudojimas](#naudojimas)
## Funkcionalumas
- Įvesti studentų vardus, pavardes ir pažymius rankiniu būdu arba generuoti atsitiktinai.
- Apskaičiuoti galutinį pažymį pagal:
  - Vidurkį
  - Medianą
- Rūšiuoti studentus pagal vardą arba pavardę.
- Atspausdinti studentų duomenis ir jų galutinius pažymius lentelės formatu.
## Failų Struktūra
Projektas suskirstytas į kelis failus, kad būtų lengviau tvarkyti kodą:

- main.cpp – pagrindinis programos failas.
- studentas.h – studento struktūra.
- ivedimas.cpp ir ivedimas.h – funkcijos skirtos vartotojų įvestims.
- duomenys.cpp ir duomenys.h – unkcijos, skirtos darbui su duomenimis (duomenų nuskaitymas iš failo ir atsitiktinių duomenų generavimas).
- rikiavimas.cpp ir rikiavimas.h – funkcijos, skirtos duomenų rikiavimui pagal vardą arba pavardę.
- vertinimas.cpp ir vertinimas.h - funkcijos, skirtos duomenų susisteminimui (medianos ir vidurkio skaičiavimas).
- rezultatas.cpp ir rezultatas.h - funkcija skirta rezultato išvedimui.
## Kompiliavimas ir Paleidimas

### Naudojant kompiliatorių:
1. Nuklonuojame repozitoriją:

       git clone https://github.com/Minvydas-Nekrasas/pirmoji_uzduotis/
       cd "[direktorija]"
   
3. Sukompiliuojame kodą:

       g++ *.cpp -o vertinimas
   
5. Paleidžiame programą:

       ./vertinimas
### Naudojant cmake:
1. Terminale nurodome direktorija, kur egzistuoja projekto CMakeLists.txt failas, sukuriam build failams skirta direktorija :

       cd "[direktorija]"
       mkdir build
       cd build

2. Paleidžiame cmake, kad sugeneruoti build failus, nurodome jau minėta direktorija:
        
       cmake "[direktorija]"
   
4. Sukompiliuojame ir sukuriame .exe failą, taip pat galime pasirinkt konfigurijacija: Release arba Debug:

       cmake --build . --config [Release arba Debug]

## Naudojimas
1. Programa paklaus, ar norite įvesti duomenis iš failo, ar rankiniu būdu.
2. Rankiniu būdu įvedus duomenis, galima pasirinkti, ar sugeneruoti pažymius atsitiktinai, ar įvesti juos ranka.
3. Vartotojas gali pasirinkti, kaip apskaičiuoti galutinį pažymį – pagal vidurkį ar medianą.
4. Programa rūšiuos studentus pagal jūsų pasirinktą kriterijų (vardą arba pavardę) ir atspausdins rezultatus.

# v0.2
1. Pridėta failų sukūrimo funkcija - sukūriami 5 failai (1 000 studentų, 10 000 studentų, 100 000 studentų, 1 000 000 studentų ir 10 000 000 studentų)
2. Sukurta funkcija, dalinanti studentus į dvi kategorijas. Studentai išvedami į du naujus failus:

    - Studentai, kurių galutinis balas < 5.0 - vargšiukai

     - Studentai, kurių galutinis balas >= 5.0 - kietiakai

3. Sukurta funkcija kategorijų išvedimui į 2 atskirus failus: vargsiukai.txt, kietiakai.txt

4. Matuojama programos sparta šiems veiksmams: 
      - failų generavimui
      - duomenų nuskaitymui iš failo 
      - studentų rūšiavimui į 2 kategorijas
      - surūšiuotų studentų išvedimui į du failus

## Vidutiniai laiko spartos matavimai (vector)
| **Studentų skaičius** | **Failo genravimas (sek)** | **Rūšiavimas į 2 kategorijas (sek)** | Išvedimas į 2 failus (sek) |
|------------------|--------------------|-----------------------|----------------------|
| 1,000            | 0.003             | 0.002                 | 0.015                |
| 10,000           | 0.018              | 0.387                 | 0.381                |
| 100,000          | 0.123            | 1.858                 | 2.465                |
| 1,000,000        | 1.222             | 2.732                 | 43.907                |
| 10,000,000       | 11.796            | 11.149                | 435.121               |

## Naujos funkcijos:
- generuotiDuomenis() -  generuojami 5 studentų failai (studentai_1000.txt, studentai_10000.txt, studentai_100000.txt, studentai_1000000.txt, studentai_10000000.txt)
- skaiciavimai() - paskaičiuojamas vidurkis arba mediana kiekvienam studentui esančiam faile ir duomenys išsaugomi struktūroje
- padalintiStudentus() - padalinami studentai į 2 kategorijas
- isvestiIFailus() - išvedami studentai į du atskirus failus (kietiakai.txt, vargšiukai.txt)

# v0.3
Vietoje std::vector<Studentai> naudojame std::list<Studentai>.

## Vidutiniai laiko spartos matavimai (list)
| **Studentų skaičius** | **Failo genravimas (sek)** | **Rūšiavimas į 2 kategorijas (sek)** | Išvedimas į 2 failus (sek) |
|------------------|--------------------|-----------------------|----------------------|
| 1,000            | 0.003             | 0.002                 | 0.007                |
| 10,000           | 0.018              | 0.015                 | 0.065                |
| 100,000          | 0.098            | 0.122                 | 0.828                |
| 1,000,000        | 1.079             | 1.243                 | 15.966                |
| 10,000,000       | 9.008            | 15.039                | 235.011               |

## Testavimo sistemos parametrai
- CPU - Intel Core i5-8265U
- RAM - 12 GB
- SSD - 238 GB NVMe KINGSTON

# Studentų Rezultatų Skaičiavimo Sistema (v1.0)
## Tikslas
Šios versijos tikslas - išanalizuoti geriausius rūšiavimo algoritmus abiems studentų konteinerių tipams (Vector ir list) ir patobulinti juos.
## Failų struktūra
Šioje versijoje yra trys rūšiavimo strategijos:
- Strategija_1 - Bendro studentai konteinerio (vector ir list tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "vargšiukų" ir "kietiakų".
- Strategija_2 - Bendro studentų konteinerio (vector ir list) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "vargšiukai". 
- Strategija_3 (patobulinimas) - Bendro studentų konteinerio skaidymas (rūšiavimas) panaudojant greičiausiai veikiančią strategiją Vector ir List konteineriams, įtraukiant į ją partition (List) ir stable_partition (Vector) algoritmus.
## Rezultatai
Sukurti trys aplankai: Strategija_1, Strategija_2 ir Strategija_3, kuriuose yra po dar du aplankus: Vector ir List. Vector aplankas turi kodą, kur naudojamas Vector studentų konteinerio tipas, analogiškai List - List konteinerio tipas.

Atlikus pirmą ir antrą strategiją buvo pastebėta, kad pirmoji strategija tiko vektoriaus tipui, o antroji listo tipui. 3 strategijoje buvo pritaikyta pirma strategija ir stable_partition funkcija vektoriaus konteinerio tipui, o listui buvo panaudota antroji strategija ir atliktas rūšiavimo optimizavimas su partition funkcija. Laiko išmatavimai pateikti žemiau.
## Vidutiniai laiko spartos matavimai
### 1000
|                        | Failo iš įrašų nuskaitymo laikas | Įrašų rūšiavimo laikas | Įrašų dalijimo į dvi grupes laikas
|------------------------|----------------------------------|------------------------|-----------------------------------|
| 1_strategija vektoriai | 0.005                        | 0.002              | 0.015                          |
| 1_strategija listai    | 0.005                        | 0.002              | 0.015                          |
| 2_strategija vektoriai | 0.005                        | 0.053              | 0.030                          |
| 2_strategija listai    | 0.005                        | 0.000              | 0.015                          |
| list su partition      | 0.005                        | 0.000              | 0.007                          |
| stable_partition vektoriai    | 0.005                        | 0.001              | 0.017                          |

### 10 000
|                        | Failo iš įrašų nuskaitymo laikas | Įrašų rūšiavimo laikas | Įrašų dalijimo į dvi grupes laikas
|------------------------|----------------------------------|------------------------|-----------------------------------|
| 1_strategija vektoriai | 0.160                        | 0.387              | 0.381                          |
| 1_strategija listai    | 0.161                        | 0.015              | 0.123                          |
| 2_strategija vektoriai | 0.160                        | 2.468              | 0.368                          |
| 2_strategija listai    | 0.161                        | 0.003              | 0.121                          |
| list su partition      | 0.160                        | 0.000              | 0.066                          |
| partition vektoriai    | 0.161                        | 0.011              | 0.243                          |

### 100 000
|                        | Failo iš įrašų nuskaitymo laikas | Įrašų rūšiavimo laikas | Įrašų dalijimo į dvi grupes laikas
|------------------------|----------------------------------|------------------------|-----------------------------------|
| 1_strategija vektoriai | 1.188                        | 1.858              | 2.465                          |
| 1_strategija listai    | 1.177                        | 0.122              | 1.301                          |
| 2_strategija vektoriai | 1.188                        | 218.594              | 3.283                          |
| 2_strategija listai    | 1.177                        | 0.039              | 1.165                          |
| list su partition      | 1.188                        | 0.012              | 0.885                          |
| partition vektoriai    | 1.177                        | 0.052              | 3.621                          |

### 1 000 000
|                        | Failo iš įrašų nuskaitymo laikas | Įrašų rūšiavimo laikas | Įrašų dalijimo į dvi grupes laikas
|------------------------|----------------------------------|------------------------|-----------------------------------|
| 1_strategija vektoriai | 9.692                        | 2.732              | 43.907                          |
| 1_strategija listai    | 10.064                        | 1.243              | 15.966                          |
| 2_strategija vektoriai | 9.692                        | 21 680              | 51.273                          |
| 2_strategija listai    | 10.064                        | 0.310              | 15.213                          |
| list su partition      | 9.692                        | 0.112              | 14.410                          |
| partition vektoriai    | 10.064                        | 0.562              | 37.504                          |

### 10 000 000
|                        | Failo iš įrašų nuskaitymo laikas | Įrašų rūšiavimo laikas | Įrašų dalijimo į dvi grupes laikas
|------------------------|----------------------------------|------------------------|-----------------------------------|
| 1_strategija vektoriai | 93.548                        | 11.149              | 435.121                          |
| 1_strategija listai    | 93.104                        | 15.039              | 235.011                          |
| 2_strategija vektoriai | 93.548                        | 21 859 400            | 498.332                          |
| 2_strategija listai    | 93.104                        | 4.171              | 145.376                          |
| list su partition      | 93.548                        | 1.162              | 176.744                          |
| partition vektoriai    | 93.104                        | 7.126              | 537.426                          |

# v1.1
## Spartos analizė:
Eksperimentai parodė, kaip duomenų struktūrų pasirinkimas (struct ar class) ir optimizavimo strategijos (O1, O2, O3) įtakoja našumą atliekant tris pagrindines užduotis: failo nuskaitymą, įrašų rūšiavimą ir įrašų dalijimą į dvi grupes.
## 3 strategija su listais `struct` ir `class` palyginimas:
### 10 000 000:

|                        | Failo iš įrašų nuskaitymo laikas | Įrašų rūšiavimo laikas | Įrašų dalijimo į dvi grupes laikas |
|------------------------|----------------------------------|------------------------|-----------------------------------|
| struct  | 93.548 | 1.162 | 176.744 |
| class | 95.492 | 36.625   | 2.127 |


### 1 000 000:
|                        | Failo iš įrašų nuskaitymo laikas | Įrašų rūšiavimo laikas | Įrašų dalijimo į dvi grupes laikas |
|------------------------|----------------------------------|------------------------|-----------------------------------|
| struct    | 9.692  | 0.112 | 14.410 |
| class  | 27.300 |  3.548 | 0.339 |


###  100 000:
|                        | Failo iš įrašų nuskaitymo laikas | Įrašų rūšiavimo laikas | Įrašų dalijimo į dvi grupes laikas |
|------------------------|----------------------------------|------------------------|-----------------------------------|
| struct      | 1.188 | 0.012  | 0.885 |
| class  | 3.764 |  0.360 | 0.027 |

### Išvada
Struct yra efektyvesnis duomenų nuskaitymui ir rūšiavimui, tačiau class geriau tinka įrašų dalijimui į grupes.

## Optimizavimo strategijų (O1, O2, O3) laiko palyginimas:
### 10 000 000:
| Optimizacijos Lygis | Failo iš įrašų nuskaitymo laikas | Įrašų rūšiavimo laikas | Įrašų dalijimo į dvi grupes laikas |
|--------------------|----------------------------------|------------------------|-----------------------------------|
| O1                | 88.579                        | 22.332             | 1.442                          |
| O2                | 86.813                        | 22.636             | 1.441                         |
| O3                | 84.903                        | 20.934              | 1.432                          |

### 1 000 000:
| Optimizacijos Lygis | Failo iš įrašų nuskaitymo laikas | Įrašų rūšiavimo laikas | Įrašų dalijimo į dvi grupes laikas |
|--------------------|----------------------------------|------------------------|-----------------------------------|
| O1                | 25.501                        | 2.915              | 0.146                         |
| O2                | 25.721                        | 2.745              | 0.143                         |
| O3                | 25.432                        | 2.764              | 0.143                         |

### 100 000 Įrašų Laikų Palyginimas
| Optimizacijos Lygis | Failo iš įrašų nuskaitymo laikas (s) | Įrašų rūšiavimo laikas (s) | Įrašų dalijimo į dvi grupes laikas (s) |
|----------------------|--------------------------------------|----------------------------|---------------------------------------|
| O1 | 3.646 | 0.336 | 0.035 |
| O2 | 3.619 | 0.343 | 0.016 |
| O3 | 3.644 | 0.325 | 0.019 |

### Išvada
O3 optimizacijos lygis yra efektyviausias visais atvejais, nors skirtumai tarp O1, O2, ir O3 mažėja dirbant su mažesniais duomenų rinkiniais.

# v1.2

# Aprašymas:
Realizuota Rule of three: parašytas kopijavimo konstruktorius ir kopijavimo operatorius. Taip pat buvo perrašyti ">>" ir "<<" operatoriai.

# Detalus aprašymas:
Rule of three: 
- ## Iš praeitos versijos paliktas destruktorius:
 ``` cpp
	~Stud() { }
```
Užtikrina, kad nebūtų nutekėjimų atmintyje, kai sunaikinami objektai.
- ## Parašytas **kopijavimo konstruktorius**:
- Kopijavimo konstruktorius Leidžia inicijuoti naują objektą, kopijuojant duomenis iš esamo objekto.
  ``` cpp
  Studentas::Studentas(const Studentas& other)
    : vardas(other.vardas), pavarde(other.pavarde), nd(other.nd), egz(other.egz), galutinis(other.galutinis) {}
  ```
- ## Parašytas **kopijavimo operatorius**:
   Kopijavimo operatorius Užtikrina, kad jau egzistuojančio objekto duomenys būtų perrašomi iš kito objekto, vengiant savęs priskyrimo.
  ``` cpp
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
  ```
  ## Parašytas **">>" ir "<<" operatorius**:
  Aprašius ">>" operatorių buvo sutrumpinta nuskaitymo funkcija
  ### Prieš:
  ``` cpp
    string  input;
    int pazymys;
    cout << "Ar norite nuskaityti duomenis is failo? (1 - Taip, 0 - Ne): ";
    int readFromFile;
    cin >> readFromFile;

    if (readFromFile == 1) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string failo_adresas;
        while (true) {
            cout << "Iveskite failo adresa: ";
            getline(cin, failo_adresas);

            ifstream file(failo_adresas);  // Bandom atidaryti
            if (file.is_open()) {
                file.close();  // Jei atsidaro, uždarom
                skaitytiIsFailo(failo_adresas, studentai);
                break;  // Išeinam iš ciklo
            } else {
                cout << "Nepavyko atidaryti failo! Bandykite dar karta.\n";
            }
        }
    } else {
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear newline from previous input
        cout << "Noredami baigti ivesti studentus, paspauskite ENTER du kartus.\n";

        while (true) {
            Studentas x;
            
            // Imame studento vardą
            cout << "\nIrasykite studento varda (ne daugiau nei 10 simboliu) arba paspauskite ENTER, kad baigtumete: ";
            getline(cin, x.vardas);
            if (x.vardas.empty()) break; // Stabdom, jei enter paspaustas 2 kart
            
            if (!arTeisinga(x.vardas)) {
                cout << "Netinkamas vardas. Bandykite dar karta.\n";
                continue;
            }

            // Imame studento pavardę
            cout << "Irasykite studento pavarde (ne daugiau nei 10 simboliu): ";
            getline(cin, x.pavarde);
            if (x.pavarde.empty()) break; // Stabdom, jei enter paspaustas 2 kart
            
            if (!arTeisinga(x.pavarde)) {
                cout << "Netinkama pavarde. Bandykite dar karta.\n";
                continue;
            }

            // Klausia, kokio suvedimo norime
            int choice;
            cout << "Ar norite atsitiktinai sugeneruoti namu darbu ir egzamino pazymius?\n";
            cout << "0 - Ne, ivesiu ranka\n";
            cout << "1 - Taip, sugeneruok atsitiktinai\n";     
            
            while (true) {
                cout << "Iveskite pasirinkima (1 arba 0): ";
                if (!(cin >> choice) || (choice != 0 && choice != 1)) {
                    cout << "Neteisingas pasirinkimas. Bandykite dar karta.\n";
                    cin.clear(); // Clear error state
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear invalid input
                } else {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear newline after input
                    break;
                }
            }
            
            if (choice == 1) {
                // Sugeneruojam atsitiktinus namų darbų ir egzamino rezultatus
                int nd_kiekis;
                cout << "Kiek norite sugeneruoti namu darbu pazymiu? (Ne daugiau nei 10 000): ";
                while (!(cin >> nd_kiekis) || nd_kiekis < 0 || nd_kiekis > 10000) {
                    cout << "Iveskite teisinga skaiciu: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // pravalom netinkamą atsakymą
                }

                generuotiRandom(x, nd_kiekis);  // Kviečiam funkciją

                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the buffer
            } else {
                // Suvedame namų darbų rezultatus rankiniu būdu
                cout << "Irasykite namu darbu pazymius (nuo 0 iki 10). Noredami baigti ivesti pazymius, paspauskite ENTER:\n";
                
                while (true) {
                    cout << "Irasykite pazymi: ";
                    getline(cin, input);
                    if (input.empty()) break;

                    try {
                        pazymys = stoi(input);
                        if (pazymys < 0 || pazymys > 10) {
                            throw out_of_range("Pazymys turi buti tarp 0 ir 10.");
                        }
                        x.nd.push_back(pazymys);
                    } catch (invalid_argument&) {
                        cout << "Iveskite teisinga pazymi (skaiciu nuo 0 iki 10).\n";
                    } catch (out_of_range& e) {
                        cout << e.what() << endl;
                    }
                }

                // Imame egzamino rezultatą
                cout << "Irasykite egzamino pazymi: ";
                while (true) {
                    getline(cin, input);
                    try {
                        x.egz = stoi(input);
                        if (x.egz < 0 || x.egz > 10) {
                            throw out_of_range("Egzamino pazymys turi buti tarp 0 ir 10.");
                        }
                        break;
                    } catch (invalid_argument&) {
                        cout << "Iveskite teisinga egzamino pazymi (skaiciu nuo 0 iki 10).\n";
                    } catch (out_of_range& e) {
                        cout << e.what() << endl;
                    }
                }
            }

            studentai.push_back(x);  // įdedam studentą į vektorių
        }
    }
  }

  ```
  ### Po:
  ``` cpp
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
  ```
- ## Parašytas **Rule of three naudojimo pavyzdys**:
  ``` cpp
	Studentas a;
	cin >> a; // Įvedamas pirmas studentas
	Studentas b = a; // Naudojamas kopijavimo konstruktorius
	cin >> b; // Keičiamas antro studento turinys

	cout << "Rezultatai:\n";
	cout << "Studentas 1: " << a << endl;
	cout << "Studentas 2: " << b << endl;

  ```
# v1.5
## Sukurta bazinė klasė žmogus. zmogus.h:
  ``` cpp
#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Zmogus {
protected:
    string vardas;
    string pavarde;

public:
    // Konstruktoriai
    Zmogus() : vardas(""), pavarde("") {}
    Zmogus(const string& v, const string& p) : vardas(v), pavarde(p) {}

    virtual ~Zmogus() {}

    virtual string toString() const = 0;   

    // Getteriai
    virtual string getVardas() const;
    virtual string getPavarde() const;

    // Setteriai
    virtual void setVardas(const string& v);
    virtual void setPavarde(const string& p);
};

#endif


  ```
Klasėje žmogus sukurtas virtualus metodas toString(), todėl klasė yra abstrakti.
## zmogus.cpp:
  ``` cpp
#include "zmogus.h"

string Zmogus::getVardas() const {
    return vardas;
}

void Zmogus::setVardas(const string& v) {
    vardas = v;
}


string Zmogus::getPavarde() const {
    return pavarde;
}

void Zmogus::setPavarde(const string& p) {
    pavarde = p;
}

  ```
Klasė studentas paverčiama į išvestinę. studentas.cpp faile yra aprašomas toString() metodas.
## studentas.cpp iškarpa:
  ``` cpp
string Studentas::toString() const {
    stringstream ss;
    ss << "Vardas: " << vardas << ", Pavarde: " << pavarde << ", Galutinis: " << fixed << setprecision(2) << galutinis;
    return ss.str();
}
  ```
main.cpp faile iškviečiamas toString() metodas:
  ``` cpp
    cout << a.toString() << endl;
  ```
# v2.0
Aprašymas:
- Cmake pritaikytas Catch2 testų frameworkui
- Realizuoti unit testai
- Sukurta .html Doxygen dokumentacija

Sukūriami vertinimas.exe ir testavimas.exe failai su cmake:
  ``` cpp
    cmake "C:\Users\minvy\OneDrive\Desktop\antroji_uzduotis\CMakeLists.txt"
  ```
Sukūriamas TIK vertinimas.exe failas su cmake:
  ``` cpp
    cmake -DENABLE_TESTING=OFF "C:\Users\minvy\OneDrive\Desktop\antroji_uzduotis\CMakeLists.txt"
  ```
Testavimo paleidimas su g++:
 ``` cpp
    g++ -o programa *.cpp -DTESTING
    ./programa
  ```
tests.cpp atliekami 27 testai, į kuriuos įeina ir destructoriaus, copy assignment operatoriaus ir copy constructoriaus testai.
Visi testai sėkmingi.
Įkeltas catch.hpp failas, kad galėtume realizuoti testus.
 ``` cpp
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Studentas.h"
#include "zmogus.h"
#include "vertinimas.h"
#include "rikiavimas.h"

TEST_CASE("Studentas class basic functionality", "[Studentas]") {
    SECTION("Default constructor initializes with empty values") {
        Studentas s;
        REQUIRE(s.getVardas().empty());
        REQUIRE(s.getPavarde().empty());
        REQUIRE(s.getNd().empty());
        REQUIRE(s.getEgz() == 0);
        REQUIRE(s.getGalutinis() == Approx(0.0));
    }

    SECTION("Parameterized constructor initializes with given values") {
        vector<int> grades = {10, 9, 8};
        int exam = 9;
        Studentas s("John", "Doe", grades, exam);

        REQUIRE(s.getVardas() == "John");
        REQUIRE(s.getPavarde() == "Doe");
        REQUIRE(s.getNd() == grades);
        REQUIRE(s.getEgz() == exam);
    }

    SECTION("Copy constructor creates a copy of an existing Studentas") {
        vector<int> grades = {7, 8, 9};
        Studentas original("Jane", "Smith", grades, 8);
        Studentas copy(original);

        REQUIRE(copy.getVardas() == original.getVardas());
        REQUIRE(copy.getPavarde() == original.getPavarde());
        REQUIRE(copy.getNd() == original.getNd());
        REQUIRE(copy.getEgz() == original.getEgz());
        REQUIRE(copy.getGalutinis() == Approx(original.getGalutinis()));
    }

    SECTION("Assignment operator works correctly") {
        vector<int> grades = {6, 7, 8};
        Studentas s1("Alice", "Johnson", grades, 7);
        Studentas s2;
        s2 = s1;

        REQUIRE(s2.getVardas() == s1.getVardas());
        REQUIRE(s2.getPavarde() == s1.getPavarde());
        REQUIRE(s2.getNd() == s1.getNd());
        REQUIRE(s2.getEgz() == s1.getEgz());
        REQUIRE(s2.getGalutinis() == Approx(s1.getGalutinis()));
    }

    SECTION("Setters update the values correctly") {
        Studentas s;
        vector<int> grades = {5, 6, 7};
        int exam = 6;

        s.setVardas("Bob");
        s.setPavarde("Brown");
        s.setNd(grades);
        s.setEgz(exam);

        REQUIRE(s.getVardas() == "Bob");
        REQUIRE(s.getPavarde() == "Brown");
        REQUIRE(s.getNd() == grades);
        REQUIRE(s.getEgz() == exam);
    }

    SECTION("Adding grades updates the grades list") {
        Studentas s;
        s.addNd(10);
        s.addNd(9);

        vector<int> expectedGrades = {10, 9};
        REQUIRE(s.getNd() == expectedGrades);
    }

    SECTION("Final grade calculation works correctly") {
        vector<int> grades = {8, 9, 10};
        int exam = 9;
        Studentas s("Chris", "Evans", grades, exam);

        double expectedGalutinis = 0.4 * std::accumulate(grades.begin(), grades.end(), 0) / grades.size() + 0.6 * exam;
        REQUIRE(s.getGalutinis() == Approx(expectedGalutinis));
    }

    SECTION("Stream operators work correctly") {
        vector<int> grades = {7, 8};
        Studentas s("Emily", "Blunt", grades, 8);

        std::ostringstream out;
        out << s;

        REQUIRE(out.str().find("Emily") != std::string::npos);
        REQUIRE(out.str().find("Blunt") != std::string::npos);
    }
}

  ```
