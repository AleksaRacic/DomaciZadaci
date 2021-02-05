#pragma once

#include "Priveligovani.h"
#include "Par.h"

class Mec {
public:
	enum Ishod { POBEDA_DOMACIN, NERESENO, POBEDA_GOST };
private:
	Par<Tim> par;
	bool odigran;
	Ishod ishod;
	mutable int *prvi, *drugi;
public:
	
	Mec(Par<Tim>);
	~Mec() { delete prvi; delete drugi; }
	const Par<Tim>& get_par() const { return par; }
	void odigraj();
	bool is_odigran() { return odigran; }
	Par<int> rezultat()const;
};