#include "PrimeFactor.h"

PrimeFactor::PrimeFactor() : Check(make_unique <PrimeCheck>()), Div(make_unique <PrimeDivisor>())
{
}

PrimeFactor::~PrimeFactor()
{
}

PrimeFactor::PrimeFactor(shared_ptr <PrimeLibrary> l) : Check(make_unique <PrimeCheck>(l)), Div(make_unique <PrimeDivisor>(l))
{
}

vector<unsigned long long> PrimeFactor::factor(unsigned long long num)//factorize number
{

	Divisors.~vector();

	bool fl = false;
	while (num > 1) {
		if (fl == false) {

			if (Check->is_prime(num)) {
				Divisors.push_back(num);
				break;
			}

			fl = true;

		}
		else {
			unsigned long long divisor = 0;
			divisor = Div->N_Div(num);
			Divisors.push_back(divisor);
			num /= divisor;
		}
	}

	return Divisors;

}

