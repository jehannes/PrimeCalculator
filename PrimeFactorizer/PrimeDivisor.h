#pragma once
#include "stdafx.h"
#include "PrimeOps.h"
#include "PrimeCheck.h"

using namespace std;

class PrimeDivisor :
	public PrimeOps
{
public:
	PrimeDivisor();
	PrimeDivisor(string b);
	uint64_t N_Div(uint64_t input);
	
private:
	uint64_t FnPrime();
	unique_ptr <PrimeCheck> Checker;
};

