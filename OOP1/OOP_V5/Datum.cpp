#include "Datum.h"

int Datum::brojDanaUMesecu(int mes) const {
	switch (mes) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31;
	case 4: case 6: case 9: case 11:
		return 30;
	case 2:
		if (this->god % 400 == 0 || (this->god % 4 == 0 && this->god % 100 != 0))
			return 29;
		else
			return 28;
	default:
		return -1;
	}
}

int Datum::brojDanaUGodini(int god) const {
	if (this->god % 400 == 0 || (this->god % 4 == 0 && this->god % 100 != 0))
		return 366;
	else
		return 365;
}

void Datum::postaviDatum(int dan, int mes, int god) {
	this->god = god;
	this->mes = (mes >= 1 && mes <= 12) ? mes : throw(GDatum());
	this->dan = (dan >= 1 && dan <= brojDanaUMesecu(this->mes)) ? dan : throw(GDatum());
}

Datum::Datum(int dan, int mes, int god) {
	postaviDatum(dan, mes, god);
}

ostream& operator<<(ostream& os, const Datum& dat) {
	os << dat.dan << '.' << dat.mes << '.' << dat.god << ' ';
	return os;
}

int operator-(const Datum& dat1, const Datum& dat2) {
	int broj_dana = 0;
	broj_dana += (dat1.dan - dat2.dan);
	if (dat1.mes > dat2.mes) {
		for (int i = dat1.mes; i != dat2.mes; broj_dana += dat1.brojDanaUMesecu(--i));
	}
	else {
		for (int i = dat2.mes; i != dat1.mes; broj_dana -= dat1.brojDanaUMesecu(--i));
	}

	if (dat1.god > dat2.god) {
		for (int i = dat1.god; i != dat2.god; broj_dana += dat1.brojDanaUGodini(--i));
	}
	else {
		for (int i = dat2.god; i != dat1.god; broj_dana -= dat1.brojDanaUGodini(--i));
	}

	return broj_dana;

}