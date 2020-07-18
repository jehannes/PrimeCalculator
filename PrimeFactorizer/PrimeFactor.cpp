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

vector<uint64_t> PrimeFactor::factor(uint64_t num)//factorize number
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
			uint64_t divisor = 0;
			divisor = Div->N_Div(num);
			Divisors.push_back(divisor);
			num /= divisor;
		}
	}

	return Divisors;
	
}

