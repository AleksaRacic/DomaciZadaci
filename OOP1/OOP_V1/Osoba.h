#ifndef _Osoba_H
#define _Osoba_H

#include "Datum.h"

class Osoba {
private:
	//Da li se smiju koristiti stringovi-------------
	char* ime;
	char* JMBG;
	const Datum &dat;
public:
	Osoba(const Osoba& os) = delete;
	Osoba& operator=(const Osoba& is) = delete;

	Osoba(char*, char*, const Datum&);//Videti da li traziti konst char
	friend ostream& operator<<(ostream&, const Osoba&);
	const char* get_ime()const { return ime; }
	const char* get_JMBG()const { return JMBG; }
	const Datum get_dat()const { return dat; }

};

#endif