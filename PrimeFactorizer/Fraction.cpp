#include "Fraction.h"
#include "pch.h"

Fraction::Fraction(shared_ptr <PrimeLibrary> l) :PF(make_shared <PrimeFactor>(l)), numeratorI(0), denominatorI(0)
{
}

void Fraction::setFraction(string input)
{
	string temp = "";
	input = inputSanitizer(input);
	const double i_s = input.size();

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
		numeratorI = stod(temp);

		if (i_s != input.size()) {
			denominatorI = stod(input);
		}
		else {
			denominatorI = 1;
		}
	}
	catch(const out_of_range & oor){
		system("CLS");
		cerr << "Out of Range error: " << oor.what() << '\n';
		cout << "number given entered exceeds " << DBL_MAX;
		Sleep(4000);
		system("CLS");

		cout << "enter new fraction: ";
		string nfrac;
		cin >> nfrac;
		setFraction(nfrac);

	}
}

void Fraction::setFraction(double numer, double denom) noexcept
{
	numeratorI = numer;
	denominatorI = denom;
}

string Fraction::SimplifyFraction()//returns a new string for in the form numerator/denominator ready for printing
{
	CnFrac();

	string g_string = "";

	g_string.append(to_string((numeratorI)));//put the numerator in the string

	if (denominatorI != 1) {//check if the denominator isn't 1
		g_string.append("/");
		g_string.append(to_string(denominatorI));
	}

	return g_string;
}

vector<double> Fraction::AsyncFactor(double ld)
{
	return (PF->factor(ld));
}



void Fraction::CnFrac()//calculates the new fraction by way of prime factorization
{
	double t_numerI = 1, t_denomI = 1;
	vector <double> t_numerV, t_denomV;

	numerator.resize(2000);
	denominator.resize(2000);

	future < vector<double> > fut_num = async(launch::async, &Fraction::AsyncFactor, this, numeratorI);
	future < vector<double> > fut_denom = async(launch::async, &Fraction::AsyncFactor, this, denominatorI);

	//get the sets of primes that make up the numbers
	numerator = fut_num.get();
	denominator = fut_denom.get();

	numerator.shrink_to_fit();
	denominator.shrink_to_fit();

	//if needed, sort the sets
	if (!is_sorted(numerator.begin(), numerator.end()))
		sort(numerator.begin(), numerator.end());
	if (!is_sorted(denominator.begin(), denominator.end()))
		sort(denominator.begin(), denominator.end());

	//get the difference between the sets for each set
	set_difference(numerator.begin(), numerator.end(), denominator.begin(), denominator.end(), inserter(t_numerV, t_numerV.begin()));
	set_difference(denominator.begin(), denominator.end(), numerator.begin(), numerator.end(), inserter(t_denomV, t_denomV.begin()));

	//multiply the sets to get the resulting number
	for (const double i : t_numerV)
		t_numerI *= i;

	for (const double i : t_denomV)
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

