#pragma once

#include "Tim.h"

class Privilegovani : public Tim {
private:
	int min_vr;
public:
	Privilegovani(const string& naziv, int max, int mi) :Tim(naziv, max), min_vr(mi) {};
	Privilegovani(const Privilegovani& pr) : Tim(pr), min_vr(pr.min_vr) {};
	Privilegovani(Privilegovani&& pr) : Tim(pr), min_vr(pr.min_vr) {};
	Privilegovani& operator=(const Privilegovani& pr) {
		if (this != &pr) {
			Tim::operator=(pr);
			this->min_vr = pr.min_vr;
		}
	}
	//ne treba destruktor jer se poziv base destruktor 

	Privilegovani& operator=(Privilegovani&& pr) {
		if (this != &pr) {
			Tim::operator=(pr);
			this->min_vr = pr.min_vr;
		}
	}
	void add_player(Igrac&, int) override;
	ostream& print(ostream&)const override;
};