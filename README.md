# PrimeCalculator


a calculator for prime based operations

at this point in time there are 2 functionallities to this program:
  * the prime factorizer, this is basis for all calculations, it factorizes any integer input in to it's constituent primes
  * fraction simplifier, this takes a fraction either as a single string or as 2 independent unsigned 64bit integers and simplifies it 
    using prime-factorization and set difference

it can factorize any positive integer up to and including 18.446.744.073.709.551.615 (uint64_t max)
it can do this 1 one of 5 modes 0 -> no use a library, up until 4-> use of the large library.

the 4 libraries of primes are:
XS => the first 1.000 
S  => the first 10.0000
M  => the first 1.000.000
L  => the first 10.000.000


roadmap:
fraction minimizer[done]-> root minimizer -> t.b.d.-> ui
