#include "PrimeLibrary.h"

PrimeLibrary::PrimeLibrary() : RunType(false)
{
	PrimeVect.~vector();
}

PrimeLibrary::PrimeLibrary(uint16_t mode) : RunType(false)
{
	string fname = "Primes";

	PrimeVect.~vector();

	switch (mode) {
	case 0:
		break;

	case 1:
		fname.append("[XS].txt");
		RunType = true;
		break;

	case 2:
		fname.append("[S].txt");
		RunType = true;
		break;

	case 3:
		fname.append("[M].txt");
		RunType = true;
		break;

	case 4:
		fname.append("[L].txt");
		RunType = true;
		break;

	default:
		break;
	}

	if (RunType) {
		LoadLib(fname);
	}
}

void PrimeLibrary::LoadLib(string fname)
{
	fstream fs;
	string str;

	fs.open(fname.c_str(), fstream::in);

	system("CLS");
	cout << "loading primes library...\n";


	if (fs.is_open())
		
		while (fs >> str) {
			if (str == "") {
				break;
			}
			else {
				PrimeVect.push_back((unsigned long long)stoi(str));
			}
		}

	sort(PrimeVect.begin(), PrimeVect.end());

	if (PrimeVect.size() != NULL) {
		cout << "done loading\n";
	}
	else {
		RunType = false;
		cout << "error while loading, continueing in mode 0\n";
	}
	Sleep(300);
	system("CLS");
	fs.close();
}
