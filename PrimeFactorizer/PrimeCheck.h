#pragma once

#include "pch.h"

using namespace std;

class PrimeCheck
{
public:
	PrimeCheck() noexcept; 
	PrimeCheck(shared_ptr <PrimeLibrary> l);
	bool is_prime(unsigned long long input);

private:
	shared_ptr <PrimeLibrary> Lib;
};

