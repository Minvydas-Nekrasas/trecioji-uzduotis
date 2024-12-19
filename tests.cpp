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
