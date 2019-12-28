#include "Fraction.h"

Fraction::Fraction(int Mo) :PF(make_unique <PrimeFactor>(Mo)), numeratorI(0), denominatorI(0)
{
}

void Fraction::setFraction(string input)
{
	string temp1 = input;
	string temp = "";

	for (int i = 0;; i++) {
		if (temp1.at(i) =='/') {
			temp1.erase(temp1.begin(), temp1.begin() + i + 1);
			break;
		}
		else {
			temp += temp1.at(i);
		}

	}

	numeratorI = stoi(temp);
	denominatorI = stoi(temp1);
}

void Fraction::setFraction(uint_fast64_t numer, uint_fast64_t denom)
{
	numeratorI = numer;
	denominatorI = denom;
}

string Fraction::SimplifyFraction()//returns a new string for in the form numerator/denominator ready for printing
{
	CnFrac();

	string g_string;

	g_string.append(to_string(numeratorI));

	if (denominatorI != 1) {
		g_string.append("/");
		g_string.append(to_string(denominatorI));
	}

	return g_string;
}

void Fraction::CnFrac()//calculates the new fraction by way of prime factorization
{
	uint_fast64_t t_numerI = 1, t_denomI = 1;
	vector <uint_fast64_t> t_numerV, t_denomV;

	numerator = PF->factor(numeratorI);
	denominator = PF->factor(denominatorI);

	sort(numerator.begin(), numerator.end());
	sort(denominator.begin(), denominator.end());

	set_difference(numerator.begin(), numerator.end(), denominator.begin(), denominator.end(), inserter(t_numerV, t_numerV.begin()));
	set_difference(denominator.begin(), denominator.end(), numerator.begin(), numerator.end(), inserter(t_denomV, t_denomV.begin()));


	for (const uint_fast64_t i : t_numerV)
		t_numerI *= i;

	for (const uint_fast64_t i : t_denomV)
		t_denomI *= i;

	numeratorI = t_numerI;
	denominatorI = t_denomI;
}

