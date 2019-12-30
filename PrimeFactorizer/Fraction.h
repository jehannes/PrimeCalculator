#pragma once
#include "stdafx.h"
#include "PrimeFactor.h"



class Fraction
{
public:
	Fraction(int Mo);
	void setFraction(string input);
	void setFraction(uint_fast64_t numer, uint_fast64_t denom) noexcept;
	string SimplifyFraction();

private:
	unique_ptr <PrimeFactor> PF;
	vector <uint_fast64_t> numerator, denominator;
	uint_fast64_t numeratorI,denominatorI;

	void CnFrac();
	string inputSanitizer(string input);
};

