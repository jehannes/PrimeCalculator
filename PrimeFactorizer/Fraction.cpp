#include "Fraction.h"
#include "STDlibs.h"

Fraction::Fraction(shared_ptr <PrimeLibrary> l) :PF(make_shared <PrimeFactor>(l)), Numerator(0), Denominator(0)
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
		Numerator = stoull(temp);

		if (i_s != input.size()) {
			Denominator = stoull(input);
		}
		else {
			Denominator = 1;
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
	Numerator = numer;
	Denominator = denom;
}

uint64_t Fraction::getNumerator()
{
	CalcNewFraction();
	return Numerator;
}

uint64_t Fraction::getDenominator()
{
	CalcNewFraction();
	return Denominator;
}


string Fraction::getFractionString()//returns a new string for in the form numerator/denominator ready for printing
{
	CalcNewFraction();

	string g_string = "";

	g_string.append(to_string(Numerator));//put the numerator in the string

	if (Denominator != 1) {//check if the denominator isn't 1
		g_string.append("/");
		g_string.append(to_string(Denominator));
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

		NumeratorVector.resize(2000);//could maybe be removed
		DenominatorVector.resize(2000);

		future < vector<uint64_t> > fut_num = async(launch::async, &Fraction::AsyncFactor, this, Numerator);//needs to be tested and probably debugged
		future < vector<uint64_t> > fut_denom = async(launch::async, &Fraction::AsyncFactor, this, Denominator);

		//get the sets of primes that make up the numbers
		if (fut_num.valid() && fut_denom.valid()) {
			NumeratorVector = fut_num.get();
			DenominatorVector = fut_denom.get();
		}
		else {
			throw exception("future exception");
		}

		NumeratorVector.shrink_to_fit();
		DenominatorVector.shrink_to_fit();

		//if needed, sort the sets
		if (!is_sorted(NumeratorVector.begin(), NumeratorVector.end()))
			sort(NumeratorVector.begin(), NumeratorVector.end());
		if (!is_sorted(DenominatorVector.begin(), DenominatorVector.end()))
			sort(DenominatorVector.begin(), DenominatorVector.end());

		//get the difference between the sets for each set
		std::set_difference(NumeratorVector.begin(), NumeratorVector.end(), DenominatorVector.begin(), DenominatorVector.end(), inserter(t_numerV, t_numerV.begin()));
		std::set_difference(DenominatorVector.begin(), DenominatorVector.end(), NumeratorVector.begin(), NumeratorVector.end(), inserter(t_denomV, t_denomV.begin()));

		//multiply the sets to get the resulting number
		for (const uint64_t i : t_numerV)//update to a algorithm
			t_numerI *= i;

		for (const uint64_t i : t_denomV)
			t_denomI *= i;

		//set the object values
		Numerator = t_numerI;
		Denominator = t_denomI;
		calcstate = true;
	}
	

}

string Fraction::inputSanitizer(string input)
{
	regex rgx("(\\d+\\/\\d+)");//apperently c++ uses uint64_t escape sequences
	smatch match;
	const bool mb=regex_search(input,match,rgx, regex_constants::match_any);
	if (!mb) {//move to exception, with reentry possibillity
		cout << "input error,shutting down";
		ExitProcess(0xff);
	}
	return match.str(1);
}

