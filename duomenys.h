#ifndef DUOMENYS_H
#define DUOMENYS_H

#include <vector>
#include <string>
#include "studentas.h"
#include "vertinimas.h"
#include "rikiavimas.h"
#include <fstream>
#include <iostream>
#include <random>
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <algorithm>

void generuotiRandom(Studentas& studentas, int nd_kiekis);
void skaitytiIsFailo(const string& failo_adresas, list<Studentas>& studentai);
void generuotiDuomenis(int studentuSk, const string &failoPavadinimas);
void skaiciavimai(list<Studentas>& studentai, int choice);
void padalintiStudentus(list<Studentas>& studentai, list<Studentas>& vargsiukai);
void isvestiIFailus(list<Studentas>& studentai, list<Studentas>& vargsiukai, int sort_choice);

#endif