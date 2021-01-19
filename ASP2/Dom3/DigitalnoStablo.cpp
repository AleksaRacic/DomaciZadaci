// DigitalnoStablo.cpp: implementation of the DigitalnoStablo class.
//
//////////////////////////////////////////////////////////////////////

#include "DigitalnoStablo.h"
#include <stack>
#include <queue>
using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DigitalnoStablo::DSUnutrasnjiCvor::~DSUnutrasnjiCvor()
{
	while (m_prvi)
	{
		ListElem *cvor = m_prvi;

		m_prvi = m_prvi->sledeci;
		delete cvor->podstablo;
		delete cvor;
	}
}

DigitalnoStablo::DSCvor * DigitalnoStablo::DSUnutrasnjiCvor::pronadjiPodstablo(char deoKljuca)
{
	if (!m_prvi)
		return 0;

	ListElem *cvor = m_prvi;
	while (cvor)
	{
		if (cvor->deoKljuca == deoKljuca)
			return cvor->podstablo;

		cvor = cvor->sledeci;
	}

	return 0;
}


void DigitalnoStablo::DSUnutrasnjiCvor::dodajPodstablo(char deoKljuca, DigitalnoStablo::DSCvor *cvor)
{
	ListElem *novi = new ListElem(deoKljuca, cvor);

	if (!m_prvi)
	{
		m_prvi = novi;
	}
	else
	{
		ListElem *tek = m_prvi, *preth = 0;

		while (tek && tek->deoKljuca < deoKljuca)
		{
			preth = tek;
			tek = tek->sledeci;
		}

		if (preth)
			preth->sledeci = novi;
		else
			m_prvi = novi;

		novi->sledeci = tek;
	}

	m_brojPodstabala++;
}

void DigitalnoStablo::DSUnutrasnjiCvor::ukloniPodstablo(char deoKljuca)
{
	if (!m_prvi)
		return;

	ListElem *tek = m_prvi, *preth = 0;

	while (tek && tek->deoKljuca != deoKljuca)
	{
		preth = tek;
		tek = tek->sledeci;
	}

	if (!tek)
		return;

	if (preth)
		preth->sledeci = tek->sledeci;
	else
		m_prvi = m_prvi->sledeci;

	delete tek;
	m_brojPodstabala--;
}

void DigitalnoStablo::DSUnutrasnjiCvor::poseti(ostream &it)
{

	for (ListElem *tek = m_prvi; tek; tek = tek->sledeci)
		tek->podstablo->poseti(it);
}


//----------------------------------------------

DigitalnoStablo::DSList::~DSList()
{

}

void DigitalnoStablo::DSList::povecajFrekvenciju() {
	this->freq++;
}

void DigitalnoStablo::DSList::poseti(ostream &it)
{
	it << freq << endl;
}


//-----------------------------------------------

DigitalnoStablo::DigitalnoStablo() : m_koren(0)
{

}

DigitalnoStablo::~DigitalnoStablo()
{
	if (m_koren)
		delete m_koren;
}

DigitalnoStablo::DSList *DigitalnoStablo::pronadjiCvor(const char *kljuc)   // pronalazi list koji sadrzi dati kljuc
{
	if (!m_koren)
		return 0;

	DSCvor *tek = m_koren;

	for (int i = 0; i < strlen(kljuc) && tek; i++)
		tek = tek->pronadjiPodstablo(kljuc[i]);

	if (tek)
		tek = tek->pronadjiPodstablo(EOK);

	if (tek)
		return (DSList *)tek;

	return 0;
}

bool DigitalnoStablo::umetni(const char *kljuc)
{
	if (!m_koren)
	{
		m_koren = new DSUnutrasnjiCvor(0);
		m_brCvorova++;
	}

	DSCvor *tek = m_koren;
	DSCvor *sledeci = 0;

	for (int i = 0; i < strlen(kljuc); i++)
	{

		sledeci = tek->pronadjiPodstablo(kljuc[i]);

		if (!sledeci)
		{
			sledeci = new DSUnutrasnjiCvor(tek);
			tek->dodajPodstablo(kljuc[i], sledeci);
			m_brCvorova++;
		}

		tek = sledeci;
	}

	bool rezultat = true;  // ako je kljuc prvi put umetnut, onda true
	if (tek->pronadjiPodstablo(EOK)) {
		rezultat = false;
	}
	else
	{
		sledeci = new DSList(tek);
		tek->dodajPodstablo(EOK, sledeci);
		m_brKljuceva++;
	}

	(tek->pronadjiPodstablo(EOK))->povecajFrekvenciju();

	return rezultat;
}


bool DigitalnoStablo::obrisi(const char *kljuc)
{
	if (!m_koren)
		return false;

	DSCvor *tek = pronadjiCvor(kljuc);
	if (!tek)
		return false;

	int i = strlen(kljuc);

	while (i >= 0 && tek && tek->brojPodstabala() == 0)
	{
		DSCvor *roditelj = tek->roditelj();

		delete tek;
		m_brCvorova--;

		if (roditelj)
			roditelj->ukloniPodstablo(kljuc[i--]);
		else
			m_koren = 0;
		tek = roditelj;
	}

	m_brKljuceva--;

	return true;
}

int DigitalnoStablo::dohvatiFrekvenciju(const char *kljuc)
{
	DSList *list = pronadjiCvor(kljuc);

	if (list)
		return list->dohvatiFrekvenciju();

	return -1;
}

void DigitalnoStablo::obidji(ostream &it)
{
	if (m_koren)
		m_koren->poseti(it);
}

char DigitalnoStablo::DSUnutrasnjiCvor::deoKljuca() {
	DSUnutrasnjiCvor* otac = dynamic_cast<DSUnutrasnjiCvor*>(this->m_roditelj);
	if (otac == nullptr) {
		return '0';
	}
	ListElem* prvi = otac->m_prvi;
	for (int i = 0; i < otac->m_brojPodstabala; i++) {
		if (prvi->podstablo == this) return prvi->deoKljuca;
		prvi = prvi->sledeci;
	}
	return '0';
}

string DigitalnoStablo::findString(DigitalnoStablo::DSCvor *List) {
	string str("");
	DSCvor *cur = List->m_roditelj;
	while (cur->m_roditelj != 0) {
		str = cur->deoKljuca() + str;
		cur = cur->m_roditelj;
	}
	return str;
}

void DigitalnoStablo::DSUnutrasnjiCvor::poseti(vector<DigitalnoStablo::DSCvor*> &vec)
{

	for (ListElem *tek = m_prvi; tek; tek = tek->sledeci)
		tek->podstablo->poseti(vec);
}

void DigitalnoStablo::DSList::poseti(vector<DigitalnoStablo::DSCvor*> &vec)
{
	for (auto i = vec.begin(); i < vec.end(); i++) {
		if (this->dohvatiFrekvenciju() < (*i)->dohvatiFrekvenciju()) {
			vec.insert(i, this);
			if (vec.size() > 3) vec.erase(vec.begin());
			return;
		}
	}
	vec.push_back(this);
	if (vec.size() > 3) vec.erase(vec.begin());

}

vector<DigitalnoStablo::DSCvor*> DigitalnoStablo::predict(const char* key, int br_gr) {
	QWERTY qwe;
	vector<DigitalnoStablo::DSCvor*> vec;
	queue<pair<DigitalnoStablo::DSCvor*, int>> q;
	DigitalnoStablo::DSCvor* cur;
	pair<DigitalnoStablo::DSCvor*, int> cvor_greska;
	int size;
	int gr = 0;
	bool greska;
	q.push(make_pair(m_koren, 0));
	for (int i = 0; i < strlen(key); i++) {
		size = q.size();
		if (size == 0) {
			return vec;
			//nemanicega
		}

		while (size--) {

			cvor_greska = q.front();

			gr = cvor_greska.second;
			cur = cvor_greska.first;

			if (cur->pronadjiPodstablo(key[i])) {
				q.push(make_pair(cur->pronadjiPodstablo(key[i]), gr));
			}
			if (gr < br_gr) {
				auto susedi = qwe.nadjiSuseda(key[i]);
				for (auto s : susedi) {
					if (cur->pronadjiPodstablo(s)) {
						q.push(make_pair(cur->pronadjiPodstablo(s), ++gr));
					}
				}
			}
			q.pop();
		}

	}


	while (!q.empty()) {
		cvor_greska = q.front();
		cur = cvor_greska.first;
		q.pop();
		cur->poseti(vec);
	}
	return vec;
}