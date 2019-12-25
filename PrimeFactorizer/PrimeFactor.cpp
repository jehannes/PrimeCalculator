#include "PrimeFactor.h"

PrimeFactor::PrimeFactor() : Check(new PrimeCheck()), Div(new PrimeDivisor), fl(false)
{
}

PrimeFactor::~PrimeFactor()
{
}

PrimeFactor::PrimeFactor(int mode) : fl(false)//choose library
{
	string fname = "Primes";
	string check = "Primes";

	switch (mode) {
	case 0:
		break;

	case 1:
		fname.append("[XS].txt");
		break;

	case 2:
		fname.append("[S].txt");
		break;

	case 3:
		fname.append("[M].txt");
		break;

	case 4:
		fname.append("[L].txt");
		break;
	}

	if (fname == check) {
		Check = unique_ptr <PrimeCheck>(new PrimeCheck());
		Div = unique_ptr <PrimeDivisor>(new PrimeDivisor());
	}
	else {
		Check = unique_ptr <PrimeCheck>(new PrimeCheck(fname));
		Div = unique_ptr <PrimeDivisor>(new PrimeDivisor(fname));
	}
}

vector<uint64_t> PrimeFactor::factor(uint64_t num)//factorize number
{
	while (num > 1) {
		if (fl == false) {
			if (num > ULLONG_MAX) {
				cout << "this number is too large" << endl;
				cout << "press a key to exit the program";
				cin.get();
				ExitProcess(0xff);
			}
			else
				if (Check->is_prime(num)) {
					Divisors.push_back(num);
					break;
				}
		}
		else {
			uint64_t divisor = 0;
			divisor = Div->N_Div(num);
			Divisors.push_back(divisor);
			num /= divisor;
		}
		fl = true;
	}
	fl = false;
	return Divisors;
}

