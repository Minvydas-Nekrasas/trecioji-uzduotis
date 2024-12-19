#include "vertinimas.h"
#include <algorithm>
#include <numeric>

double formule(double bendras, int egz){ // panaudojama ta pati formulė ir medianai, ir vidurkiui
    double rez = 0.4 * bendras + 0.6 * egz;
    return rez;
}

// funkcija vidurkio paskaičiavimui
double vidurkis(const vector<int>& nd, int egz) { //taupom atmintį ir rodom į vektorių
    if (nd.empty()) return 0.00; 
    double sum = 0;
    for (double grade : nd) {
        sum += grade;
    }
    double vid = sum / nd.size();
    double rez = formule(vid, egz);
    return rez;
}

// Funkcija medianos paskaičiavimui
double mediana(vector<int> nd, int egz) {
    if (nd.empty()) return 0.0;

    // Surikiavimas, kad gautusi skaičių eilutė. Pridėti sorto algoritmą
    sort(nd.begin(), nd.end()); // naudojamas quicksort didėjimo tvarka

    int dydis = nd.size();
    double med;
    if (dydis % 2 == 0) {
        // Jeigu lyginis elementų skaičius
        med = (nd[dydis / 2 - 1] + nd[dydis / 2])/2;
        
    } else {
        // Jeigu nelyginis
        med = nd[dydis / 2];
    }
    double rez = formule(med, egz);
    return rez;
}