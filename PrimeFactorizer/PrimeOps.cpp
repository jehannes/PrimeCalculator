#include "PrimeOps.h"

PrimeOps::PrimeOps()  :CurPrime(0), runtype(false)//constructor without library loading 
{
}

PrimeOps::PrimeOps(string b) : CurPrime(0), runtype(true)//constructor with library loading 
{
	fstream fs;
	string str;

	fs.open(b.c_str(), fstream::in);

	system("CLS");
	cout << "loading primes library..." << endl;


	if (fs.is_open())

		while (fs >> str) {
			if (str == "") {
				break;
			}
			else {
				pvec.push_back((uint_fast64_t)stoi(str));
			}
		}

	cout << "done loading" << endl;
	Sleep(300);
	system("CLS");
	fs.close();
}
