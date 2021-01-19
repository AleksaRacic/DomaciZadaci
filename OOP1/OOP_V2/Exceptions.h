#ifndef _Exceptions_H
#define _Exceptions_H

#include <exception>

class GTek : std::exception {
public:
	const char* what() const override { return "Ne postoji tek"; }
};
#endif
