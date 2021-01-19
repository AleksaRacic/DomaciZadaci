#pragma once
#include <string>
using namespace std;

class Destinacija {
private:
	string naziv;
	string opis;
	double pr;
	int br_oc;
public:
	Destinacija(string n, string o) : naziv(n), opis(o), pr(0), br_oc(0) {};
	void oceni(unsigned int);
	const string& get_naziv() const { return naziv; }
	const string& get_opis() const { return opis; }
	const double get_pr()const { return pr; }
	friend bool operator>(const Destinacija&, const Destinacija&);
	friend ostream& operator<<(ostream&, const Destinacija&);
};