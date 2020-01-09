#pragma once
#include "pch.h"
#include "PrimeFactor.h"



class Fraction
{
public:
	Fraction(shared_ptr <PrimeLibrary> l);
	void setFraction(string input);
	void setFraction(unsigned long long numer, unsigned long long denom) noexcept;
	string SimplifyFraction();

private:
	unique_ptr <PrimeFactor> PF;
	vector <unsigned long long> numerator, denominator;
	unsigned long long numeratorI,denominatorI;

	void CnFrac();
	string inputSanitizer(string input);
};

