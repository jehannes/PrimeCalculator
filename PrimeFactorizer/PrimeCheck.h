#pragma once

#include "STDlibs.h"

using namespace std;

class PrimeCheck
{
public:
	PrimeCheck() noexcept; 
	PrimeCheck(shared_ptr <PrimeLibrary> l);
	bool is_prime(uint64_t input);

private:
	shared_ptr <PrimeLibrary> Lib;
};

