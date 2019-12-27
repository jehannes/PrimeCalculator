#include "Fraction.h"

Fraction::Fraction(int Mo) :PF(new PrimeFactor(Mo)), numeratorI(0), denominatorI(0)//have it make the correct things
{
}

void Fraction::setFraction(string input)
{
	STRto2INT(input);
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
	g_string.append("/");
	g_string.append(to_string(denominatorI));
	return g_string;
}

void Fraction::STRto2INT(string input)
{
	string temp1 = input;
	string temp = "";

	for (int i = 0;; i++) {
		if (temp1.at(i) == (char)*"/") {
				temp1.erase(temp1.begin(), temp1.begin() + i + 1);
				break;
		}
		else {
			temp += temp1[i];//does this work?
		}

	}

	numeratorI = stoi(temp);
	denominatorI = stoi(temp1);

}

void Fraction::CnFrac()//calculates the new fraction by way of prime factorization
{
	uint_fast64_t t_numerI = 1, t_denomI = 1;
	vector <uint_fast64_t> t_numerV, t_denomV;
	numerator = PF->factor(numeratorI);
	denominator = PF->factor(denominatorI);

	
	set_difference(numerator.begin(),numerator.end(),denominator.begin(),denominator.end(),inserter(t_numerV,t_numerV.begin()));//crashes on access violation in return vector
	set_difference(denominator.begin(), denominator.end(), numerator.begin(), numerator.end(), inserter(t_denomV, t_denomV.begin()));
	

	for (uint_fast64_t i : t_numerV)
		t_numerI *= i;

	for (uint_fast64_t i : t_denomV)
		t_denomI *= i;

	numeratorI = t_numerI;
	denominatorI = t_denomI;
}

