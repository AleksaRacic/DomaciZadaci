#pragma once

#include <exception>
using namespace std;

class GOpseg : exception {
public:
	const char* what() const override { return "Greska u zvezdicama!"; }
};

class GDatum :exception {
	const char* what() const override { return "Greska u datumu!"; }
};

class GAra : exception {
private:
	const char* gr;
public:
	GAra(const char* g) :gr(g) {};
	const char* what() const override { return gr; }
};