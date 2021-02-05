#ifndef _Igrac_H_
#define _Igrac_H_

#include <string>
#include <iostream>
using namespace std;

class Igrac {
private:
	const string ime;
	int vr;
public:
	//da li prebaciti string po kopiji ili referenci
	Igrac(const string& i, int v = 1000) : ime(i), vr(v) {};
	const string& get_ime() const { return ime; }
	int get_vr() const { return vr; }
	void promeni_procentualno(int procenat) { vr += procenat*vr / 100; }
	friend bool operator==(const Igrac&, const Igrac&);
	friend ostream& operator<<(ostream&, const Igrac&);
};

#endif