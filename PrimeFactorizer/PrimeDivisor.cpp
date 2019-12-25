#include "PrimeDivisor.h"

PrimeDivisor::PrimeDivisor() :PrimeOps(), Checker(new PrimeCheck())
{
}

PrimeDivisor::PrimeDivisor(string b) : PrimeOps(b), Checker(new PrimeCheck())
{
}

uint64_t PrimeDivisor::N_Div(uint64_t input) {
	if (Checker->is_prime(input)) {
		return input;
	}
	if (PrimeOps::runtype) {

		for (int i = 0; i < PrimeOps::pvec.size(); ++i) {
			if (input % PrimeOps::pvec.at(i) == 0 && input > PrimeOps::pvec.at(i)) {
				return PrimeOps::pvec.at(i);
			}
			else if (PrimeOps::pvec.at(i) > input) {
				break;
			}
		}
		uint64_t DivPrime = FnPrime();

		while (DivPrime <= input) {
			if (input % DivPrime == 0) {
				PrimeOps::CurPrime = pvec.at(PrimeOps::pvec.size());
				return DivPrime;
			}
			DivPrime = FnPrime();
		}
		PrimeOps::CurPrime = 0;
		return 1;
		//if the divisor goes beyond the vector it should revert to calculating the outcome, maybe as start point the last point in the vector
		//return 1;
	}
	else {
		uint64_t DivPrime = FnPrime();


		while (DivPrime <= input) {
			if (input % DivPrime == 0) {
				PrimeOps::CurPrime = 0;
				return DivPrime;
			}
			DivPrime = FnPrime();
		}
		PrimeOps::CurPrime = 0;
		return 1;
	}
}

uint64_t PrimeDivisor::FnPrime() {
	uint64_t number = 2;
	while (true) {
		if (Checker->is_prime(number) && number > PrimeOps::CurPrime) {
			break;
		}
		number++;
	}
	PrimeOps::CurPrime = number;
	return number;
}
