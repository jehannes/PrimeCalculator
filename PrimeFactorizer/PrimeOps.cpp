#include "PrimeOps.h"

PrimeOps::PrimeOps() : CurPrime(0), runtype(false)
{
}

PrimeOps::PrimeOps(shared_ptr <PrimeLibrary> l) : CurPrime(0), runtype(l->RunType),pvec(l->PrimeVect)//constructor without library loading 
{
}

