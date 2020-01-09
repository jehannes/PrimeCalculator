#include "PrimeCheck.h"

PrimeCheck::PrimeCheck() noexcept{}

PrimeCheck::PrimeCheck(shared_ptr <PrimeLibrary> l) : Lib(l)
{
}


bool PrimeCheck::is_prime(unsigned long long input) {
	if (input == 2) {
		return true;
	}else
	if (Lib->RunType && Lib->PrimeVect.back() >= input) {
		return binary_search(Lib->PrimeVect.begin(), Lib->PrimeVect.end(), input);
	}
	else {
		for (unsigned long long i = 2; i <= sqrt(input); ++i) {
			if (input % i == 0) {
				return false;
			}
		}
		return true;
	}
}
