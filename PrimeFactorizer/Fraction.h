#pragma once
#include "STDlibs.h"
#include "PrimeFactor.h"



class Fraction
{
public:
	Fraction(shared_ptr <PrimeLibrary> l);
	void setFraction(string input);
	void setFraction(uint64_t numer, uint64_t denom) noexcept;
	uint64_t getNumerator();
	uint64_t getDenominator();
	string getFractionString();

private:
	shared_ptr <PrimeFactor> PF;
	vector <uint64_t> AsyncFactor(uint64_t);
	vector <uint64_t> NumeratorVector, DenominatorVector;
	uint64_t Numerator,Denominator;
	bool calcstate;
	void CalcNewFraction();
	string inputSanitizer(string input);

};

