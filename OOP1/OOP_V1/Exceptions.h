#ifndef _Exceptions_H
#define _Exceptions_H

#include <exception>

class errRac : std::exception {
public:
	const char* what() const override { return "Greska u placanju"; }
};

#endif