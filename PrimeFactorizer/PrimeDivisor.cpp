#include "PrimeDivisor.h"

PrimeDivisor::PrimeDivisor() :  Lib(), Checker(make_unique <PrimeCheck>()), CurPrime(0)
{
}

PrimeDivisor::PrimeDivisor(shared_ptr <PrimeLibrary> l) : Lib(l), Checker(make_unique <PrimeCheck>(l)), CurPrime(0)
{
}

uint64_t PrimeDivisor::N_Div(uint64_t input) {
	if (Checker->is_prime(input)) {
		return input;
	}

	if (Lib->RunType && Lib->PrimeVect.back() >= input) {

		for (const uint64_t i : Lib->PrimeVect) {
			if (input % i == 0) {
				return i;
			}
		}
		return 1;
	}
	else {
		uint64_t DivPrime = FnPrime();

		while (DivPrime <= input) {
			if (input % DivPrime == 0) {
				CurPrime = 0;
				return DivPrime;
			}
			DivPrime = FnPrime();
		}
		CurPrime = 0;
		return 1;//it really shouldn't get here,throw execption
	}
}

uint64_t PrimeDivisor::FnPrime() {
	//todo make dependend on run type, could look through library
	//use iterator to keep track of point in library

	uint64_t number = 2;
	for (; number < UINT64_MAX; number++) {
		if (Checker->is_prime(number) && number > CurPrime) {
			break;
		}
	}
	CurPrime = number;
	return number;
}
