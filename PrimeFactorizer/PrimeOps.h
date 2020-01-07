#pragma once

#include "pch.h"

using namespace std;

class PrimeOps
{
public:
	PrimeOps();
	PrimeOps(shared_ptr <PrimeLibrary> l);

protected:
	uint_fast64_t CurPrime;
	vector <uint_fast64_t> pvec;
	bool runtype;
};

