#pragma once
#include "pch.h"

#include "PrimeCheck.h"

using namespace std;

class PrimeDivisor
{
public:
	PrimeDivisor();
	PrimeDivisor(shared_ptr <PrimeLibrary> l);
	uint_fast64_t N_Div(uint_fast64_t input);

private:
	uint_fast64_t FnPrime();
	unique_ptr <PrimeCheck> Checker;
	uint_fast64_t CurPrime;

	shared_ptr <PrimeLibrary> Lib;
};

