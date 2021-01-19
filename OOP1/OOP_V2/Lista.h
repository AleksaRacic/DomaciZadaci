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

	Lista<T>& push_back(const T&);
	void next() { if(tek) tek = tek->sled; }
	bool is_tek() const { return tek != nullptr; }
	void set_front() { tek = prvi; }
	T& get_elem() const;
	void isprazni() { brisi(); };
	


};

#endif
