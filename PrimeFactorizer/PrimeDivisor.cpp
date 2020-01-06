#include "PrimeDivisor.h"

PrimeDivisor::PrimeDivisor() :PrimeOps(), Checker(make_unique <PrimeCheck>())
{
}

PrimeDivisor::PrimeDivisor(string b) : PrimeOps(b), Checker(make_unique <PrimeCheck>(b))
{
}

uint_fast64_t PrimeDivisor::N_Div(uint_fast64_t input) {
	if (Checker->is_prime(input)) {
		return input;
	}

	if (PrimeOps::runtype && PrimeOps::pvec.back() >= input) {

		for (const uint_fast64_t i : PrimeOps::pvec) {
			if (input % i == 0) {
				return i;
			}
		}
		return 1;
	}
	else {
		uint_fast64_t DivPrime = FnPrime();


		while (DivPrime <= input) {
			if (input % DivPrime == 0) {
				PrimeOps::CurPrime = 0;
				return DivPrime;
			}
			DivPrime = FnPrime();
		}
		PrimeOps::CurPrime = 0;
		return 1;//it really shouldn't get here
	}
}

uint_fast64_t PrimeDivisor::FnPrime() {//todo make dependend on run type, could look through library
	uint_fast64_t number = 2;
	for (; number < UINT_FAST64_MAX; number++) {
		if (Checker->is_prime(number) && number > PrimeOps::CurPrime) {
			break;
		}
	}
	PrimeOps::CurPrime = number;
	return number;
}
