#pragma once
#include "pch.h"
#include "PrimeOps.h"
#include "PrimeCheck.h"

using namespace std;

class PrimeDivisor :
	public PrimeOps
{
public:
	PrimeDivisor() ;
	PrimeDivisor(string b);
	uint_fast64_t N_Div(uint_fast64_t input);

private:
	uint_fast64_t FnPrime();
	unique_ptr <PrimeCheck> Checker;
};

