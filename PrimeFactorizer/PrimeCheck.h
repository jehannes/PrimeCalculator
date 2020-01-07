#pragma once
#include "PrimeOps.h"
#include "pch.h"

using namespace std;

class PrimeCheck
{
public:
	PrimeCheck() noexcept; 
	PrimeCheck(shared_ptr <PrimeLibrary> l);
	bool is_prime(uint_fast64_t input);

private:
	shared_ptr <PrimeLibrary> Lib;
};

