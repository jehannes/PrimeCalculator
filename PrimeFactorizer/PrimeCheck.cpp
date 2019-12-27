#include "PrimeCheck.h"

PrimeCheck::PrimeCheck() :PrimeOps() {}

PrimeCheck::PrimeCheck(string b) : PrimeOps(b)
{
}


bool PrimeCheck::is_prime(uint_fast64_t input) {
	if (input == 2) {
		return true;
	}
	if (PrimeOps::runtype) {
		for (uint_fast64_t i : PrimeOps::pvec) {
			if (i == input) {
				return true;
			}
		}
		for (uint_fast64_t j = 2; (uint_fast64_t)(j < sqrt(input) + 1); j++) {
			if (input % j == 0) {
				return false;
			}
		}
		return true;
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
