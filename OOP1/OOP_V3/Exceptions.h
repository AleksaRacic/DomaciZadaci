#pragma once

#include <exception>


class errPrik :std::exception {
public:
	const char* what()const override { return "Ne moze se prikljuciti"; };
};

class errMec : std::exception{
	const char* what()const override { return "Ne moze se odigrati"; };
};