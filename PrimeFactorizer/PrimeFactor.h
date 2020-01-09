#pragma once
#include "pch.h"
#include "PrimeCheck.h"
#include "PrimeDivisor.h"

using namespace std;
//factorizer for a single int
class PrimeFactor
{
public:
	PrimeFactor() ;//no lib
	PrimeFactor(shared_ptr <PrimeLibrary> l);//0-4; select library size with 0 being no library and 4 being the largest
	~PrimeFactor();
	vector <unsigned long long> factor(unsigned long long num);

private:

	unique_ptr <PrimeCheck> Check;
	unique_ptr <PrimeDivisor> Div;
	vector <unsigned long long> Divisors;

};

