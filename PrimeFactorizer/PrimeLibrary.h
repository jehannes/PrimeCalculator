#pragma once

#include "STDlibs.h"

using namespace std;

class PrimeLibrary
{
public:
	PrimeLibrary();
	PrimeLibrary(uint16_t mode);

	vector <uint64_t> PrimeVect;
	bool RunType;

private:
	void LoadLib(string fname);
};

