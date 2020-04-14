#include "Fraction.h"
#include "pch.h"

Fraction::Fraction(shared_ptr <PrimeLibrary> l) :PF(make_shared <PrimeFactor>(l)), numeratorI(0), denominatorI(0)
{
}

void Fraction::setFraction(string input)
{
	string temp = "";
	input = inputSanitizer(input);
	const uint64_t i_s = input.size();

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
		cout << "number given exceeds " << UINT64_MAX;
		Sleep(4000);
		system("CLS");

		cout << "enter new fraction: ";//want to continue?
		string nfrac;
		cin >> nfrac;
		setFraction(nfrac);

	}
}

void Fraction::setFraction(uint64_t numer, uint64_t denom) noexcept
{
	numeratorI = numer;
	denominatorI = denom;
}

uint64_t Fraction::getNumerator()
{
	CalcNewFraction();
	return numeratorI;
}

uint64_t Fraction::getDenominator()
{
	CalcNewFraction();
	return denominatorI;
}

string Fraction::getFractionString()
{
	CalcNewFraction();

	string g_string = "";

	g_string.append(to_string(numeratorI));//put the numerator in the string

	if (denominatorI != 1) {//check if the denominator isn't 1
		g_string.append("/");
		g_string.append(to_string(denominatorI));
	}

	return g_string;
}

string Fraction::SimplifyFraction()//returns a new string for in the form numerator/denominator ready for printing
{
	CalcNewFraction();

	string g_string = "";

	g_string.append(to_string(numeratorI));//put the numerator in the string

	if (denominatorI != 1) {//check if the denominator isn't 1
		g_string.append("/");
		g_string.append(to_string(denominatorI));
	}

	return g_string;
}

vector<uint64_t> Fraction::AsyncFactor(uint64_t ld)
{
	return (PF->factor(ld));
}

void Fraction::CalcNewFraction()//calculates the new fraction by way of prime factorization
{//maybe check if it is a perfect fraction first?
	if (!calcstate) {
		uint64_t t_numerI = 1, t_denomI = 1;
		vector <uint64_t> t_numerV, t_denomV;

		numerator.resize(2000);
		denominator.resize(2000);

		future < vector<uint64_t> > fut_num = async(launch::async, &Fraction::AsyncFactor, this, numeratorI);//needs to be tested and probably debugged
		future < vector<uint64_t> > fut_denom = async(launch::async, &Fraction::AsyncFactor, this, denominatorI);

		//get the sets of primes that make up the numbers
		if (fut_num.valid() && fut_denom.valid()) {
			numerator = fut_num.get();
			denominator = fut_denom.get();
		}
		else {
			throw exception("future exception");
		}

		numerator.shrink_to_fit();
		denominator.shrink_to_fit();

		//if needed, sort the sets
		if (!is_sorted(numerator.begin(), numerator.end()))
			sort(numerator.begin(), numerator.end());
		if (!is_sorted(denominator.begin(), denominator.end()))
			sort(denominator.begin(), denominator.end());

		//get the difference between the sets for each set
		std::set_difference(numerator.begin(), numerator.end(), denominator.begin(), denominator.end(), inserter(t_numerV, t_numerV.begin()));
		std::set_difference(denominator.begin(), denominator.end(), numerator.begin(), numerator.end(), inserter(t_denomV, t_denomV.begin()));

		//multiply the sets to get the resulting number
		for (const uint64_t i : t_numerV)
			t_numerI *= i;

		for (const uint64_t i : t_denomV)
			t_denomI *= i;

		//set the object values
		numeratorI = t_numerI;
		denominatorI = t_denomI;
		calcstate = true;
	}
	

}

string Fraction::inputSanitizer(string input)
{
	regex rgx("(\\d+\\/\\d+)");//apperently c++ uses uint64_t escape sequences
	smatch match;
	const bool mb=regex_search(input,match,rgx, regex_constants::match_any);
	if (!mb) {
		cout << "input error,shutting down";
		ExitProcess(0xff);
	}
	return match.str(1);
}

