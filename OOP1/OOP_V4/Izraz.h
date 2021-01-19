#pragma once

#include "Lista.h"
#include "Element.h"

class Izraz : public Lista<Element> {
public:
	Izraz* kopiraj() { return new Izraz(*this); }

};
