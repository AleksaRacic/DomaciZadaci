#pragma once
//Digitalno stablo
#include <unordered_set>
#include "DigitalnoStablo.h"
#include <ctime>
#include <ratio>
#include <chrono>
class Dict {
private:
	unordered_set<char> *nedozvoljeni_karakteri;
	DigitalnoStablo* tree;
	vector<vector<char>> *qwerty;
public:
	Dict();
	~Dict();
	void umetni(const char*);
	void umetni(vector<const char*>);
	bool pretraga(const char*);
	bool umetniRec(const char *);
	void predikcija(const char*);
	void umetni(string);
	void umetniSve();
};



