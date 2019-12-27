#pragma once
#include "PrimeOps.h"
#include "stdafx.h"

using namespace std;

class PrimeCheck :
	public PrimeOps
{
public:
	PrimeCheck() ;
	PrimeCheck(string b);
	bool is_prime(uint_fast64_t input);

};

