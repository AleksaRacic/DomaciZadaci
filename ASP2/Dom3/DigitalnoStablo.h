// DigitalnoStablo.h: interface for the DigitalnoStablo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIGITALNOSTABLO_H__3A24581B_2902_4E94_9213_DD2E7CFBE607__INCLUDED_)
#define AFX_DIGITALNOSTABLO_H__3A24581B_2902_4E94_9213_DD2E7CFBE607__INCLUDED_

#pragma once

#include "Stablo.h"
#include <vector>
#include <string>

#define EOK 0

class DigitalnoStablo : public Stablo
{
public:

	class DSCvor
	{
	public:
		DSCvor      *m_roditelj;
		virtual char deoKljuca() { return'0'; }

	public:
		DSCvor(DSCvor *roditelj) : m_roditelj(roditelj) { }
		virtual ~DSCvor() { }
		virtual string findString() { return string(""); };
		DSCvor *roditelj() { return m_roditelj; }

		virtual int dohvatiFrekvenciju() { return 0; }
		virtual void povecajFrekvenciju() { }
		virtual void poseti(ostream &it) = 0;
		virtual void poseti(vector<DSCvor*>&) = 0;
		virtual DSCvor *pronadjiPodstablo(char deoKljuca) { return 0; }
		virtual void dodajPodstablo(char deoKljuca, DSCvor *cvor) { }
		virtual void ukloniPodstablo(char deoKljuca) { }
		virtual int brojPodstabala() const { return 0; }
	};

	class DSUnutrasnjiCvor : public DSCvor
	{
	public:
		char deoKljuca();
		friend class DSCvor;
		struct ListElem
		{
			char                    deoKljuca;
			DSCvor                  *podstablo;
			ListElem                *sledeci;

			ListElem(char _deoKljuca, DSCvor *p)
			{
				deoKljuca = _deoKljuca;
				podstablo = p;
				sledeci = 0;
			}
		};

		ListElem    *m_prvi;
		int         m_brojPodstabala;


	public:
		ListElem* elem() { return m_prvi; }
		DSUnutrasnjiCvor(DSCvor *roditelj)
			: DSCvor(roditelj), m_prvi(0), m_brojPodstabala(0)
		{
		}

		~DSUnutrasnjiCvor();
		void poseti(vector<DSCvor*>&);
		virtual DSCvor *pronadjiPodstablo(char deoKljuca);
		virtual void dodajPodstablo(char deoKljuca, DSCvor *cvor);
		virtual void ukloniPodstablo(char deoKljuca);

		virtual int brojPodstabala() const { return m_brojPodstabala; }
		virtual void poseti(ostream &it);
	};

	class DSList : public DSCvor
	{
	protected:
		int        freq = 0;

	public:
		DSList(DSCvor *roditelj)
			: DSCvor(roditelj), freq(0)
		{
			freq = 0;
		}

		~DSList();

		virtual int dohvatiFrekvenciju() { return freq; }
		virtual void povecajFrekvenciju();
		virtual void poseti(ostream &it);
		void poseti(vector<DSCvor*>&);
	};


	DSUnutrasnjiCvor  *m_koren;

	DSList    *pronadjiCvor(const char *kljuc);
	// pronalazi list koji sadrzi dati kljuc
public:
	DigitalnoStablo();
	virtual ~DigitalnoStablo();

	string DigitalnoStablo::findString(DigitalnoStablo::DSCvor *);
	virtual bool umetni(const char *kljuc);
	virtual bool obrisi(const char *kljuc);

	virtual int dohvatiFrekvenciju(const char *kljuc);
	vector<DSCvor*> predict(const char*, int br_gr);
	virtual void obidji(ostream &it);

};

class QWERTY {
private:
	vector<vector<char>> *qwerty = 0;
public:
	QWERTY();
	~QWERTY();
	vector<char> nadjiSuseda(char);
};

#endif // !defined(AFX_DIGITALNOSTABLO_H__3A24581B_2902_4E94_9213_DD2E7CFBE607__INCLUDED_)
