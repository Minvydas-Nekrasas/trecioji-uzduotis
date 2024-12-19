#include "rikiavimas.h"
#include <algorithm>

using namespace std;

void rikiuotiStudentus(list<Studentas>& studentai, int sort_choice) {
    if (sort_choice == 1) {
        // Rikiuojam pagal vardą
        studentai.sort([](const Studentas& a, const Studentas& b) {
            string vardasA = a.getVardas();
            string vardasB = b.getVardas();
            if (vardasA == vardasB) {
                return a.getPavarde() < b.getPavarde();
            }
            return vardasA < vardasB;
        });
    } else if (sort_choice == 0) {
        // Rikiuojam pagal pavardę
        studentai.sort([](const Studentas& a, const Studentas& b) {
            string pavardeA = a.getPavarde();
            string pavardeB = b.getPavarde();
            if (pavardeA == pavardeB) {
                return a.getVardas() < b.getVardas();
            }
            return pavardeA < pavardeB;
        });
    } else if (sort_choice == 2) {
        // Rikiuojam pagal galutinį pažymį
        studentai.sort([](const Studentas& a, const Studentas& b) {
            return a.getGalutinis() > b.getGalutinis();
        });
    }
}
