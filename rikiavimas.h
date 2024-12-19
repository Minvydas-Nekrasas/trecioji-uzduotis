#ifndef RIKIAVIMAS_H
#define RIKIAVIMAS_H

#include <string>
#include <vector>
#include <list>
#include "studentas.h"
using namespace std;

string toLowerCase(const string& str);
void rikiuotiStudentus(list<Studentas>& studentai, int sort_choice);

#endif