#include "pch.h"
#include "PrimeFactor.h"
#include "Fraction.h"

using namespace std;

//unique_ptr <PrimeFactor> fac;
unique_ptr <Fraction> Frac;
shared_ptr <PrimeLibrary> Lib;


int main(void) {


	//	vector <unsigned long long> Divs;

		//unsigned long long num;
	string num;
	int mode = 0;
	string more;


	while (true) {
		cout << "give number:";
		cin >> num;
		cout << "\ngive mode:";
		cin >> mode;

		Lib = shared_ptr <PrimeLibrary>(make_shared<PrimeLibrary>(mode));
		Frac = unique_ptr <Fraction>(make_unique <Fraction>(Lib));

		/*		fac = unique_ptr <PrimeFactor>(new PrimeFactor(mode));

				Divs = fac->factor(num);
				cout << "the factors of " << num << " are:\n";
				for (unsigned long long i : Divs) {
					cout << i << " ";
				}
				Frac->setFraction(num);
				*/

		Frac->setFraction(num);
		system("CLS");
		cout << Frac->SimplifyFraction();

		cout << "\n\n\n";

		cout << "more?  ";
		cin >> more;
		if (more == "Y" || more == "y") {
			//	Divs.~vector();
			Lib.reset();
			Frac.reset();
			system("CLS");
		}
		else {
			break;
		}

	}

	return NULL;
}