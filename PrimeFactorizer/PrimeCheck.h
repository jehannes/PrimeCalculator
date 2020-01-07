#pragma once
#include "PrimeOps.h"
#include "pch.h"

using namespace std;

class PrimeCheck :
	public PrimeOps
{
public:
	PrimeCheck() noexcept; 
	PrimeCheck(string b);
	bool is_prime(uint_fast64_t input);

};

