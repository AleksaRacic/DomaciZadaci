#pragma once
#include <string>
using namespace std;

class Element {
public:
	virtual char get_oznaka()const = 0;
	virtual const char* get_natpis() const = 0;
	friend ostream& operator<<(ostream&, const Element&);
	virtual Element* kopiraj() const = 0;

};

class Operand : public Element {
	const char* natpis;
public:
	Operand(const char* s) :natpis(s) {};
	char get_oznaka()const override { return 'D'; }
	const char* get_natpis() const { return natpis; }
	Operand* kopiraj() const override { return new Operand(*this); }
};

class Binarni_Operator : public Element {
public:
	virtual int get_priority() const = 0;
	friend bool operator>(const Binarni_Operator&, const Binarni_Operator&);
	char get_oznaka() const override { return'O'; }
	//virtual Binarni_Operator* kopiraj() = 0 ;
};

class Sabiranje :public Binarni_Operator {
public:
	int get_priority()const override { return 1; }
	const char* get_natpis()const { return "+"; }
	Sabiranje* kopiraj() const override { return new Sabiranje(*this); }
};

class Leva_Zagrada : public Element {
public:
	const char* get_natpis()const override { return "("; }
	char get_oznaka() const override { return'('; }
	Leva_Zagrada* kopiraj() const override { return new Leva_Zagrada(*this); }
};

class Desna_Zagrada : public Element {
public:
	const char* get_natpis()const override { return ")"; }
	char get_oznaka() const override { return')'; }
	Desna_Zagrada* kopiraj() const override { return new Desna_Zagrada(*this); }
};

//Test

class Oduzimanje :public Binarni_Operator {
public:
	int get_priority()const override { return 1; }
	const char* get_natpis()const { return "-"; }
	Oduzimanje* kopiraj() const override { return new Oduzimanje(*this); }
};

class Mnozenje :public Binarni_Operator {
public:
	int get_priority() const override { return 2; }
	const char* get_natpis()const { return "*"; }
	Mnozenje* kopiraj() const override { return new Mnozenje(*this); }
};