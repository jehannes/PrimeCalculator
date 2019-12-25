#pragma once
#include "stdafx.h"
#include "PrimeCheck.h"
#include "PrimeDivisor.h"

using namespace std;
//factorizer for a single int
class PrimeFactor
{
public:
	PrimeFactor();//no lib
	PrimeFactor(int mode);//0-4; select library size with 0 being no library and 4 being the largest
	~PrimeFactor();
	vector <uint64_t> factor(uint64_t num);

private:

	unique_ptr <PrimeCheck> Check;
	unique_ptr <PrimeDivisor> Div;
	vector <uint64_t> Divisors;
	bool fl;

};

