#ifndef _Lista_H
#define _Lista_H

#include "Exceptions.h"
template <typename T>
class Lista {
private:
	struct element {
		T info; //videti da li se stavlja po pointeru ili po vrednosti
		struct element *sled;
		element() = default;
		element(const T& t, element* s = nullptr) : info(t), sled(s) {}
	};
	element *prvi, *poslednji;
	mutable element* tek;
	void brisi();
public:
	Lista() :prvi(nullptr), poslednji(nullptr), tek(nullptr) {}
	~Lista();

	Lista(const Lista&) = delete;
	void operator=(const Lista&) = delete;
	Lista(Lista &&) = delete;

	Lista<T>& push_back(const T&);
	void next() { if(tek) tek = tek->sled; }
	bool is_tek() const { return tek != nullptr; }
	void set_front() { tek = prvi; }
	T& get_elem() const;
	void isprazni() { brisi(); };
	
	brisi() {
		set_front();
		element* tmp;
		while (is_tek()) {
			tmp = tek;
			next();
			delete tmp;
		}
		prvi = poslednji = nullptr;
	}

	push_back(const T& t) {
		if (prvi == nullptr) { prvi = poslednji = new element(t); return *this; }

		poslednji->sled = new element(t);
		poslednji = poslednji->sled;
		return *this;
	}

	get_elem() const {
		if (!is_tek()) throw(GTek());
		return tek->info;
	}

	~Lista() { brisi(); }


};

#endif
