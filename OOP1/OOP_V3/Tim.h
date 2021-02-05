#ifndef _Tim_H
#define _Tim_H

#include "Exceptions.h"
#include "Igrac.h"

class Tim {
private:
	string naziv;
	int tr_br;
	int max_br;
	Igrac **niz;
	void premesti(Tim&);
	void kopiraj(const Tim&);
	void brisi();
public:
	Tim(const string&, int);
	Tim(const Tim& t) { kopiraj(t); };
	Tim(Tim&& t) { premesti(t); }
	virtual ~Tim() { brisi(); }
	Tim& operator=(const Tim& t) {
		if (&t != this) {
			brisi();
			kopiraj(t);
		}
		return *this;
	}

	Tim& operator=(Tim&& t) {
		if (&t != this) {
			brisi();
			premesti(t);
		}
		return *this;
	}

	virtual void add_player(Igrac&, int);
	int get_br() { return tr_br; }
	Igrac* const operator[](int) const;
	Igrac* operator[](int);
	int sr_vr();
	friend bool operator==(const Tim&, const Tim&);
	virtual ostream& print(ostream &) const;
	friend ostream& operator<<(ostream& os, const Tim& t) { return t.print(os); }
	//videti d li se moze napisati posebna metoda za ovo povecanje
	void promeni_procentualno(int);
};

#endif