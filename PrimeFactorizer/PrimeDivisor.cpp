#include "PrimeDivisor.h"

PrimeDivisor::PrimeDivisor() :  Lib(), Checker(make_unique <PrimeCheck>()), CurPrime(0)
{
}

PrimeDivisor::PrimeDivisor(shared_ptr <PrimeLibrary> l) : Lib(l), Checker(make_unique <PrimeCheck>(l)), CurPrime(0)
{
}

unsigned long long PrimeDivisor::N_Div(unsigned long long input) {
	if (Checker->is_prime(input)) {
		return input;
	}

	if (Lib->RunType && Lib->PrimeVect.back() >= input) {

		for (const unsigned long long i : Lib->PrimeVect) {
			if (input % i == 0) {
				return i;
			}
		}
		return 1;
	}
	else {
		unsigned long long DivPrime = FnPrime();


		while (DivPrime <= input) {
			if (input % DivPrime == 0) {
				CurPrime = 0;
				return DivPrime;
			}
			DivPrime = FnPrime();
		}
		CurPrime = 0;
		return 1;//it really shouldn't get here
	}
}

unsigned long long PrimeDivisor::FnPrime() {//todo make dependend on run type, could look through library
	unsigned long long number = 2;
	for (; number < UINT_FAST64_MAX; number++) {
		if (Checker->is_prime(number) && number > CurPrime) {
			break;
		}
	}
	CurPrime = number;
	return number;
}
