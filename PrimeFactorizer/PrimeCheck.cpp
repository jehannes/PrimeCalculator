#include "PrimeCheck.h"

PrimeCheck::PrimeCheck() noexcept :PrimeOps() {}

PrimeCheck::PrimeCheck(shared_ptr <PrimeLibrary> l) : PrimeOps(l)
{
}


bool PrimeCheck::is_prime(uint_fast64_t input) {
	if (input == 2) {
		return true;
	}else
	if (PrimeOps::runtype && PrimeOps::pvec.back() >= input) {
		return binary_search(PrimeOps::pvec.begin(), PrimeOps::pvec.end(), input);
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
