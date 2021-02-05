#pragma once

#include "Izraz.h"
#include "Exceptions.h"
class Generator {
private:
	Generator() {};
public:
	static Generator* instanca() {
		static Generator instanca;
		return &instanca;
	}
	Generator(const Generator&) = delete;
	void operator=(const Generator&) = delete;

	Generator(Generator&&) = delete;
	void operator=(Generator&&) = delete;

	Izraz& operator()(Izraz&);
};
