#pragma once
#include "pch.h"
#include "PrimeFactor.h"



class Fraction
{
public:
	Fraction(shared_ptr <PrimeLibrary> l);
	void setFraction(string input);
	void setFraction(double numer, double denom) noexcept;
	string SimplifyFraction();

private:
	shared_ptr <PrimeFactor> PF;
	vector <double> AsyncFactor(double);
	vector <double> numerator, denominator;
	double numeratorI,denominatorI;

	void CnFrac();
	string inputSanitizer(string input);

};

