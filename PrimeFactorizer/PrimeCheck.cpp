#include "PrimeCheck.h"

PrimeCheck::PrimeCheck() noexcept{}

PrimeCheck::PrimeCheck(shared_ptr <PrimeLibrary> l) : Lib(l)
{
}


bool PrimeCheck::is_prime(uint64_t input) {
	
	if (input < 2){
		return false;
	}else
	if (input == 2) {
		return true;
	}else
	if (Lib->RunType && Lib->PrimeVect.back() >= input) {
		return binary_search(Lib->PrimeVect.begin(), Lib->PrimeVect.end(), input);
	}
	else {
		uint64_t sqrt_i = sqrtl(input);

		if (input % 2 == 0 || input % 3 == 0)
			return false;

		for (uint64_t i = 5; i <= sqrt_i; i += 6)
			if (input % i == 0 || input % (i + 2) == 0)
				return false;

		return true;
	}
}
