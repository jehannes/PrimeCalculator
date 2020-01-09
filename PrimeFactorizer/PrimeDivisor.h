#pragma once
#include "pch.h"

#include "PrimeCheck.h"

using namespace std;

class PrimeDivisor
{
public:
	PrimeDivisor();
	PrimeDivisor(shared_ptr <PrimeLibrary> l);
	unsigned long long N_Div(unsigned long long input);

private:
	unsigned long long FnPrime();
	unique_ptr <PrimeCheck> Checker;
	unsigned long long CurPrime;

	shared_ptr <PrimeLibrary> Lib;
};

