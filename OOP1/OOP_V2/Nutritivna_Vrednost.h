#ifndef _Nutritivna_Vrednost_H
#define _Nutritivna_Vrednost_H

#include <iostream>

using namespace std;

class Nutritivna_Vrednost {
private:
	double uh, ma, pr;
public:
	Nutritivna_Vrednost(double u, double m, double p) : uh(u), ma(m), pr(p) {};
	double get_uh()const { return uh; }
	double get_ma()const { return ma; }
	double get_pr()const { return pr; }

	friend Nutritivna_Vrednost operator+(const Nutritivna_Vrednost&, const Nutritivna_Vrednost&);
	double get_cal() const { return uh * 4 + ma * 9 + pr * 4; }
	friend ostream& operator<<(ostream& os, const Nutritivna_Vrednost&);
};

#endif