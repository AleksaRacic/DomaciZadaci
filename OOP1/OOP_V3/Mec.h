#pragma once

#include "Priveligovani.h"
#include "Par.h"

class Mec {
	enum Ishod { POBEDA_DOMACIN, NERESENO, POBEDA_GOST };
	Par<Tim>* par; //preveslati ovo kako ne bi morao praviti premestajuci konstruktor
	bool odigran;
	Ishod ishod;
public:
	Mec(Tim& gost, Tim& domacin);
	Par<Tim>& get_par()const { return *par; }
	void odigraj();
	bool is_odigran() { return odigran; }
	Par<int> rezultat()const;
};