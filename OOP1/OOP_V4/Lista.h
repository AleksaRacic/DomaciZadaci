#pragma once
#include "Exceptions.h"
#include <iostream>

template <typename T>
class Lista {
	struct Elem {
		T* info;
		struct Elem *pret, *sled;
		Elem() :info(nullptr), pret(nullptr), sled(nullptr) {}
	};
	int br_pod;

	Elem *prvi, *poslednji;

	void kopiraj(const Lista& l) {
		br_pod = l.br_pod;
		Elem *tr = l.prvi;
		Elem *tmp;
		prvi = poslednji = nullptr; // videti da li ovo treba
		while (tr) {
			tmp = new Elem;
			if (!prvi) {
				prvi= poslednji = tmp;
			}
			else {
				tmp->pret = poslednji;
				poslednji->sled = tmp;
				poslednji = tmp;
			}
			tmp->info = tr->info;
			tr = tr->sled;
			
		}

	}

	void premesti(Lista& l) {
		br_pod = l.br_pod;
		prvi = l.prvi;
		poslednji = l.poslednji;
		l.prvi = nullptr;
		l.poslednji = nullptr;
	}
	void obrisi() {
		Elem *tr = poslednji;
		while (tr) {
			poslednji = poslednji->pret;
			delete tr;
			tr = poslednji;
		}
		prvi = nullptr;
	}
public:
	Lista() : prvi(nullptr), poslednji(nullptr), br_pod(0) {};
	Lista(const Lista& l) { obrisi(); kopiraj(l); }
	Lista(Lista&& l) { obrisi(); premesti(l); }
	Lista& operator=(const Lista& l) {
		if (this != &l) {
			obrisi(); kopiraj(l);
		}
		return *this;
	}
	Lista& operator=(Lista&& l) {
		if (this != &l) {
			obrisi(); premesti(l);
		}
		return *this;
	}

	int get_br_pod() { return br_pod; }
	Lista& operator+=(T* t) {
		Elem *tmp = new Elem;
		tmp->info = t->kopiraj(); //clone constructor
		if (prvi == nullptr) {
			prvi = poslednji = tmp;
			br_pod++;
			return *this;

		}
		tmp->pret = poslednji;
		poslednji->sled = tmp;
		poslednji = tmp;
		br_pod++;
		return *this;
	}

	T* operator-() {
		if (!poslednji) throw(GPrazna());
		T* info = poslednji->info;
		if (poslednji->pret) {
			poslednji = poslednji->pret;
			delete poslednji->sled;
			poslednji->sled = nullptr;
		}
		else {
			delete poslednji;
			poslednji = nullptr;
			prvi = nullptr;
		}
		br_pod--;
		return info;
	}
	T* operator*() {
		if (!prvi) throw(GPrazna());
		T* info = prvi->info;
		if (prvi->sled) {
			prvi = prvi->sled;
			delete prvi->pret;
			prvi->pret = nullptr;
		}
		else {
			delete prvi;
			poslednji = nullptr;
			prvi = nullptr;
		}
		br_pod--;
		return info;
	}
	friend ostream& operator<<(ostream& os, const Lista& l) {
		Elem *tr = l.prvi;
		while (tr) {
			os << *(tr->info) << " ";
			tr = tr->sled;
		}
		return os;
	}
};