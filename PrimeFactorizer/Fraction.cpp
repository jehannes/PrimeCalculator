#include "Fraction.h"
#include "pch.h"

Fraction::Fraction(shared_ptr <PrimeLibrary> l) :PF(make_unique <PrimeFactor>(l)), numeratorI(0), denominatorI(0)
{
}

void Fraction::setFraction(string input)
{
	string temp = "";
	input = inputSanitizer(input);
	const unsigned long long i_s = input.size();

	for (int i = 0; i < input.size(); i++) {
		if (input.at(i) == '/') {
			input.erase(input.begin(), input.begin() + i + 1);
			break;
		}
		else {
			temp += input.at(i);
		}

	}

	try {
		numeratorI = stoull(temp);

		if (i_s != input.size()) {
			denominatorI = stoull(input);
		}
		else {
			denominatorI = 1;
		}
	}
	catch(const out_of_range & oor){
		system("CLS");
		cerr << "Out of Range error: " << oor.what() << '\n';
		cout << "number given entered exceeds " << ULLONG_MAX;
		Sleep(4000);
		system("CLS");

		cout << "enter new fraction: ";
		string nfrac;
		cin >> nfrac;
		setFraction(nfrac);

	}
}

void Fraction::setFraction(unsigned long long numer, unsigned long long denom) noexcept
{
	numeratorI = numer;
	denominatorI = denom;
}

string Fraction::SimplifyFraction()//returns a new string for in the form numerator/denominator ready for printing
{
	CnFrac();

	string g_string = "";

	g_string.append(to_string(numeratorI));//put the numerator in the string

	if (denominatorI != 1) {//check if the denominator isn't 1
		g_string.append("/");
		g_string.append(to_string(denominatorI));
	}

	return g_string;
}

void Fraction::CnFrac()//calculates the new fraction by way of prime factorization
{
	unsigned long long t_numerI = 1, t_denomI = 1;
	vector <unsigned long long> t_numerV, t_denomV;

	//get the sets of primes that make up the numbers
	numerator = PF->factor(numeratorI);
	denominator = PF->factor(denominatorI);

	//if needed, sort the sets
	if (!is_sorted(numerator.begin(), numerator.end()))
		sort(numerator.begin(), numerator.end());
	if (!is_sorted(denominator.begin(), denominator.end()))
		sort(denominator.begin(), denominator.end());

	//get the difference between the sets for each set
	set_difference(numerator.begin(), numerator.end(), denominator.begin(), denominator.end(), inserter(t_numerV, t_numerV.begin()));
	set_difference(denominator.begin(), denominator.end(), numerator.begin(), numerator.end(), inserter(t_denomV, t_denomV.begin()));

	//multiply the sets to get the resulting number
	for (const unsigned long long i : t_numerV)
		t_numerI *= i;

	for (const unsigned long long i : t_denomV)
		t_denomI *= i;

	//set the object values
	numeratorI = t_numerI;
	denominatorI = t_denomI;
}

string Fraction::inputSanitizer(string input)
{
	regex rgx("(\\d+\\/\\d+)");//apperently c++ uses double escape sequences
	smatch match;
	const bool mb=regex_search(input,match,rgx, regex_constants::match_any);
	if (!mb) {
		cout << "input error,shutting down";
		ExitProcess(0xff);
	}
	return match.str(1);
}

