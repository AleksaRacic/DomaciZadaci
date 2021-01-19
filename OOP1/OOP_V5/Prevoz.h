#pragma once

#include "Destinacija.h"

class Prevoz {
	Destinacija& dest;
	double cena;
public:
	Prevoz(Destinacija& d, double c) :dest(d), cena(c) {};
	const Destinacija& get_dest() { return dest; }
	double get_cena() { return cena; }
};