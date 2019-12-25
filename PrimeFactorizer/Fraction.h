#pragma once
#include "stdafx.h"
#include "PrimeFactor.h"



class Fraction
{
public:
	Fraction(int Mo,string FN);
	void setFraction(string input);
	void setFraction(uint64_t numer, uint64_t denom);
	string SiplifyFraction();

private:
	unique_ptr <PrimeFactor> PF;
	vector <uint64_t> numerator, denominator;
	uint64_t numeratorI, denominatorI;
	
	void STRto2INT(string input);
	void CnFrac();
};

