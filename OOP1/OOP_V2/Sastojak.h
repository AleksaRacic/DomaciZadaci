#ifndef _Sastojak_H
#define _Sastojak_H

#include "Namirnica.h"

class Sastojak {
	const Namirnica& namirnica;
	double gr;
public:
	Sastojak(const Namirnica& nam, double g) :namirnica(nam), gr(g) {};
	double get_gr() const { return gr; }
	const Namirnica& get_nam() const { return namirnica; }
	Nutritivna_Vrednost nut_vr() const;
	double get_cal()const;
	friend ostream& operator<<(ostream&, const Sastojak&);
};

#endif