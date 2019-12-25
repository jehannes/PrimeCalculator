#include "stdafx.h"
#include "PrimeFactor.h"

using namespace std;

unique_ptr <PrimeFactor> fac;

void prt_func(uint64_t i) {
	cout << i << " ";
}

int main(void) {


	vector <uint64_t> Divs;

	uint64_t num;
	int mode;
	string more;


	while (true) {
		cout << "give number:";
		cin >> num;
		cout << "\ngive mode:";
		cin >> mode;
		fac = unique_ptr <PrimeFactor>(new PrimeFactor(mode));

		Divs = fac->factor(num);
		cout << "the factors of " << num << " are:\n";
		for (uint64_t i : Divs) {
			cout << i << " ";
		}
		cout << "\n\n\n";

		cout << "more?  ";
		cin >> more;
		if (more.compare("Y") || more.compare("y")) {
			Divs.~vector();
			fac.reset();
			system("CLS");
		}
		else {
			break;
		}

	}

	return NULL;
}