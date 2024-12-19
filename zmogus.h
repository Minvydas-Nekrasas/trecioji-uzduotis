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
