#pragma once
#include "stdafx.h"

using namespace std;
//basic base class
class PrimeOps
{
public:
	PrimeOps();
	PrimeOps(string b);

protected:
	uint64_t CurPrime;
	vector <uint64_t> pvec;
	bool runtype;
};

