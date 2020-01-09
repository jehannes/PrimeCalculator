#pragma once

#include "pch.h"

using namespace std;

class PrimeLibrary
{
public:
	PrimeLibrary();
	PrimeLibrary(uint16_t mode);

	vector <unsigned long long> PrimeVect;
	bool RunType;

private:
	void LoadLib(string fname);
};

