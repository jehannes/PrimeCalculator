#pragma once
#include "pch.h"

#include "PrimeCheck.h"

using namespace std;

class PrimeDivisor
{
public:
	PrimeDivisor();
	PrimeDivisor(shared_ptr <PrimeLibrary> l);
	double N_Div(double input);

private:
	double FnPrime();
	unique_ptr <PrimeCheck> Checker;
	double CurPrime;

	shared_ptr <PrimeLibrary> Lib;
};

