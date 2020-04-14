#include "PrimeDivisor.h"

PrimeDivisor::PrimeDivisor() :  Lib(), Checker(make_unique <PrimeCheck>()), CurPrime(0)
{
}

PrimeDivisor::PrimeDivisor(shared_ptr <PrimeLibrary> l) : Lib(l), Checker(make_unique <PrimeCheck>(l)), CurPrime(0)
{
}

double PrimeDivisor::N_Div(double input) {
	if (Checker->is_prime(input)) {
		return input;
	}

	if (Lib->RunType && Lib->PrimeVect.back() >= input) {

		for (const double i : Lib->PrimeVect) {
			if (fmod(input, i) == 0) {
				return i;
			}
		}
		return 1;
	}
	else {
		double DivPrime = FnPrime();

		while (DivPrime <= input) {
			if (fmod(input,DivPrime) == 0) {
				CurPrime = 0;
				return DivPrime;
			}
			DivPrime = FnPrime();
		}
		CurPrime = 0;
		return 1;//it really shouldn't get here
	}
}

double PrimeDivisor::FnPrime() {//todo make dependend on run type, could look through library
	double number = 2;
	for (; number < DBL_MAX; number++) {
		if (Checker->is_prime(number) && number > CurPrime) {
			break;
		}
	}
	CurPrime = number;
	return number;
}
