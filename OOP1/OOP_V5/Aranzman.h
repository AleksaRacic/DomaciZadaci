#pragma once
#include "Datum.h"
#include "Destinacija.h"
#include "Prevoz.h"
#include "Smestaj.h"

class Aranzman {
	Destinacija &dest;
	Datum &pocetak, &kraj;
	Smestaj *smestaj = nullptr;
	//kako dodeljujemo kada jedna klasa sarzi drugu
	Prevoz *prevoz = nullptr;
public:
	Aranzman(Destinacija& de, Datum& poc, Datum& kr) : dest(de), pocetak(poc), kraj(kr) {};
	void dodaj_smestaj(Smestaj &);
	void dodaj_prevoz(Prevoz &);
	Destinacija& get_dest() const { return dest; }
	Datum& get_pocetak()const { return pocetak; }
	Datum& get_kraj()const { return kraj; }
	int trajanje()const { return pocetak - kraj; }
	double cena()const;
	friend ostream& operator<<(ostream&, const Aranzman&);
};