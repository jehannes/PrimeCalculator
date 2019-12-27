#pragma once
#include "stdafx.h"
#include "PrimeFactor.h"



class Fraction
{
public:
	Fraction(int Mo);
	void setFraction(string input);
	void setFraction(uint_fast64_t numer, uint_fast64_t denom);
	string SimplifyFraction();

private:
	unique_ptr <PrimeFactor> PF;
	vector <uint_fast64_t> numerator, denominator;
	uint_fast64_t numeratorI;
	uint_fast64_t denominatorI;

	void STRto2INT(string input);
	void CnFrac();
};

