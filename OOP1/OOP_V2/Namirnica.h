#ifndef _Namirnica_H
#define _Namirnica_H

#include "Nutritivna_Vrednost.h"

#include <string>

class Namirnica {
private:
	string naziv;
	const Nutritivna_Vrednost& nut_vr;
	bool posno;
public:
	Namirnica(string n, const Nutritivna_Vrednost& nu, bool p) :naziv(n), nut_vr(nu), posno(p) {};

	const string& get_naziv() const { return naziv; }
	//proveriti da li treba vracati double po referenci ili moze isto po kopiji
	const Nutritivna_Vrednost& get_nut()const { return nut_vr; }
	friend bool operator==(const Namirnica&, const Namirnica&);
	friend ostream& operator<<(ostream& os, const Namirnica&);

};

#endif
