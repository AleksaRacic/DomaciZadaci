#pragma once

#include <iostream>
using namespace std;
#include "Exceptions.h"

class Datum {
	int dan, mes, god;
	int brojDanaUMesecu(int)const;
	void postaviDatum(int, int, int);
	int brojDanaUGodini(int)const;
public:
	Datum(int, int, int);
	friend ostream& operator<<(ostream& os, const Datum&);
	friend int operator-(const Datum&, const Datum&);
};