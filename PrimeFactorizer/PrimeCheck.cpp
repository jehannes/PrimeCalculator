#include "PrimeCheck.h"

PrimeCheck::PrimeCheck() noexcept{}

PrimeCheck::PrimeCheck(shared_ptr <PrimeLibrary> l) : Lib(l)
{
}


bool PrimeCheck::is_prime(uint_fast64_t input) {
	if (input == 2) {
		return true;
	}else
	if (Lib->RunType && Lib->PrimeVect.back() >= input) {
		return binary_search(Lib->PrimeVect.begin(), Lib->PrimeVect.end(), input);
	}
	else {
		for (uint_fast64_t i = 2; i <= sqrt(input); ++i) {
			if (input % i == 0) {
				return false;
			}
		}
		return true;
	}
}
