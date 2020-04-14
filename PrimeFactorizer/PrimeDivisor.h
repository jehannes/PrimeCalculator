#pragma once
#include "pch.h"

#include "PrimeCheck.h"

using namespace std;

class PrimeDivisor
{
public:
	PrimeDivisor();
	PrimeDivisor(shared_ptr <PrimeLibrary> l);
	uint64_t N_Div(uint64_t input);

private:
	uint64_t FnPrime();
	unique_ptr <PrimeCheck> Checker;
	uint64_t CurPrime;

	shared_ptr <PrimeLibrary> Lib;
};

