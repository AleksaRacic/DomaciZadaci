#ifndef _Datum_H
#define _Datum_H

#include <iostream>

using namespace std;

class Datum {
private:
	int dan, mesec, godina;
	int brojDanaUMesecu(int)const;
	void postaviDatum(int, int, int);
public:
	Datum(int, int, int);

	friend bool operator==(const Datum&, const Datum&);
	friend ostream& operator<<(ostream&, const Datum&);
};
#endif