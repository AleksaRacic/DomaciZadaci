#ifndef _Dinarski_Racun_H
#define _Dinarski_Racun_H

#include "Racun.h"

class Dinarski_Racun : public Racun {
public:
	Dinarski_Racun(const Osoba& os, char* bRac) : Racun(os, bRac) {};

	//Pogledati da li ima efikasniji nacin zabrane kopiranja u izvedenoj klasi

	Dinarski_Racun(const Dinarski_Racun&) = delete;
	Dinarski_Racun& operator=(const Dinarski_Racun&) = delete;


	const char* get_val() const { return "RSD"; }
};


#endif
