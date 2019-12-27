#include "stdafx.h"
#include "PrimeFactor.h"
#include "Fraction.h"

using namespace std;

//unique_ptr <PrimeFactor> fac;
unique_ptr <Fraction> Frac;

void prt_func(uint_fast64_t i) {
	cout << i << " ";
}

int main(void) {


//	vector <uint_fast64_t> Divs;

	//uint_fast64_t num;
	string num;
	int mode = 0;
	string more;


	while (true) {
		cout << "give number:";
		cin >> num;
		cout << "\ngive mode:";
		cin >> mode;

		Frac = unique_ptr <Fraction>(make_unique <Fraction>(mode));

/*		fac = unique_ptr <PrimeFactor>(new PrimeFactor(mode));

		Divs = fac->factor(num);
		cout << "the factors of " << num << " are:\n";
		for (uint_fast64_t i : Divs) {
			cout << i << " ";
		}*/
		Frac->setFraction(num);

		system("CLS");

		cout << Frac->SimplifyFraction();

		cout << "\n\n\n";

		cout << "more?  ";
		cin >> more;
		if (more.compare("Y") || more.compare("y")) {
		//	Divs.~vector();
			Frac.reset();
			system("CLS");
		}
		else {
			break;
		}

	}

	return NULL;
}