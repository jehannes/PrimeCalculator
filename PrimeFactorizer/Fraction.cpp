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

string Fraction::SiplifyFraction()//returns a new string for in the form numerator/denominator ready for printing
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
	//somehow do this:
	//string:	 	   numerator/denominator
	//				    /				  \
	//uint_fast64_t: numeratorI	   ,	  denominatorI
	string temp = "";

	for (int i = 0;; i++) {
		if (input.at(i) == (char)*"/") {
			for (int j = 0; j <= i; j++) {
				input.erase(j);
			}
			break;
		}

		temp.append((const char*)&input.at(i));//does this work?

	}

	numeratorI = stoi(temp);
	denominatorI = stoi(input);

}

void Fraction::CnFrac()//calculates the new fraction by way of prime factorization
{
	uint_fast64_t t_numerI = 0, t_denomI = 0;

	numerator = PF->factor(numeratorI);
	denominator = PF->factor(denominatorI);

	for (vector <uint_fast64_t>::iterator it_1 = numerator.begin(); it_1 != numerator.end(); it_1++) {
		for (vector <uint_fast64_t>::iterator it_2 = denominator.begin(); it_2 != denominator.end(); it_2++) {
			if (*it_1 == *it_2) {
				numerator.erase(it_1);
				denominator.erase(it_2);
			}
		}
	}


	for (uint_fast64_t i : numerator)
		t_numerI *= i;

	for (uint_fast64_t i : denominator)
		t_denomI *= i;

	numeratorI = t_numerI;
	denominatorI = t_denomI;
}

