#pragma once
#include <iostream>
using namespace std;

template<typename T>
class Par {
private:
	T* prvi;
	T* drugi;
public:
	Par(T* pr, T* dr) :prvi(pr), drugi(dr) {};
	//da li treba unistiti pointere kada se izadje

	//Ne trebaju premestajuci konstruktori jer par nije vlasnik podatka

	T* get_prvi()const { return prvi; }
	T* get_drugi()const { return drugi; }
	T* set_prvi(T* t) { prvi = t; }
	T* set_drugi(T* t) { drugi = t; }
	friend bool operator==(const Par<T>& par1, const Par<T>& par2) { return(par1.prvi == par2.prvi && par1.drugi == par2.drugi); }
	friend ostream& operator<<(ostream& os, const Par& p) {
		os << "[" << *p.prvi << "-" << *p.drugi << "]";
		return os;
	}
};