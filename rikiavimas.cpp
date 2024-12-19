#include "rikiavimas.h"
#include <algorithm>  // Naudojama rikiavimo funkcijoms

using namespace std;

// Funkcija studentų sąrašui rikiuoti pagal pasirinktą kriterijų
void rikiuotiStudentus(list<Studentas>& studentai, int sort_choice) {
    if (sort_choice == 1) {  // Rikiavimas pagal vardą
        studentai.sort([](const Studentas& a, const Studentas& b) {
            string vardasA = a.getVardas();  // Gautas pirmo studento vardas
            string vardasB = b.getVardas();  // Gautas antro studento vardas
            if (vardasA == vardasB) {  // Jei vardai sutampa, rikiuojam pagal pavardę
                return a.getPavarde() < b.getPavarde();
            }
            return vardasA < vardasB;  // Rikiuojam pagal vardą abėcėlės tvarka
        });
    } else if (sort_choice == 0) {  // Rikiavimas pagal pavardę
        studentai.sort([](const Studentas& a, const Studentas& b) {
            string pavardeA = a.getPavarde();  // Gautas pirmo studento pavardė
            string pavardeB = b.getPavarde();  // Gautas antro studento pavardė
            if (pavardeA == pavardeB) {  // Jei pavardės sutampa, rikiuojam pagal vardą
                return a.getVardas() < b.getVardas();
            }
            return pavardeA < pavardeB;  // Rikiuojam pagal pavardę abėcėlės tvarka
        });
    } else if (sort_choice == 2) {  // Rikiavimas pagal galutinį pažymį
        studentai.sort([](const Studentas& a, const Studentas& b) {
            return a.getGalutinis() > b.getGalutinis();  // Rikiuojam nuo didžiausio iki mažiausio galutinio pažymio
        });
    }
}
