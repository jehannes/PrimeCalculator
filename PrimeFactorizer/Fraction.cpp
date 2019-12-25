#include "Fraction.h"

Fraction::Fraction(int Mo, string FN)
{
}

void Fraction::setFraction(string input)
{
	STRto2INT(input);
}

void Fraction::setFraction(uint64_t numer, uint64_t denom)
{
	numeratorI = numer;
	denominatorI = denom;
}

string Fraction::SiplifyFraction()
{
	CnFrac();
	string g_string;
	g_string.append(to_string(numeratorI));
	g_string.append("/");
	g_string.append(to_string(denominatorI));
	return g_string;
}

void Fraction::STRto2INT(string input)
{

}

void Fraction::CnFrac()
{
	uint64_t t_numerI = 0, t_denomI = 0;

	numerator = PF->factor(numeratorI);
	denominator = PF->factor(denominatorI);

	for (vector <uint64_t>::iterator it_1 = numerator.begin(); it_1 != numerator.end(); it_1++) {
		for (vector <uint64_t>::iterator it_2 = denominator.begin(); it_2 != denominator.end(); it_2++) {
			if (*it_1 == *it_2) {
				numerator.erase(it_1);
				denominator.erase(it_2);
			}
		}
	}
	

	for (uint64_t i : numerator)
		t_numerI *= i;

	for (uint64_t i : denominator)
		t_denomI *= i;

	numeratorI = t_numerI;
	denominatorI = t_denomI;
}

