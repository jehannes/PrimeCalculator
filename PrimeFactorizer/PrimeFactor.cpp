#include "PrimeFactor.h"

PrimeFactor::PrimeFactor()  : Check(make_unique <PrimeCheck>()), Div(make_unique <PrimeDivisor>()), fl(false)
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
		Check = unique_ptr <PrimeCheck>(make_unique <PrimeCheck>());
		Div = unique_ptr <PrimeDivisor>(make_unique <PrimeDivisor>());
	}
	else {
		Check = unique_ptr <PrimeCheck>(make_unique <PrimeCheck>(fname));
		Div = unique_ptr <PrimeDivisor>(make_unique <PrimeDivisor>(fname));
	}
}

vector<uint_fast64_t> PrimeFactor::factor(uint_fast64_t num)//factorize number
{

	Divisors.~vector();
	fl = false;
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
			uint_fast64_t divisor = 0;
			divisor = Div->N_Div(num);
			Divisors.push_back(divisor);
			num /= divisor;
		}
		fl = true;
	}

	return Divisors;

}

