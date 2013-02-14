#include "OptionStudent.h"

using namespace std;

// OptionStudent counter
size_t OptionStudent::count_ = 0;

// OptionStudent constructor
OptionStudent::OptionStudent(const string& id,
							 const string& firstname,
							 const string& lastname,
							 int term,
							 const string& option)
:Student(id, firstname, lastname), term_(term), option_(option)
{
	if(!isValidTerm(term_))
	{
		throw "Error: Invalid term!";			
	}

	count_++;
}

// A valid term must be a positive number
bool OptionStudent::isValidTerm(const int& term)
{
	if(term > 0)
	{
		return true;
	}

	return false;
}

// Display OptionStudent to console
void OptionStudent::display(ostream& os) const
{
	Student::display(os);
	os << "Term: " << term_ << endl;
	os << "Option: " << option_ << endl;
}

// Overloaded ostream operator
iostream& operator<<(ostream& os, const OptionStudent& s)
{
	return os << (const Student&)s << ' ' << s.term_ << ' ' << s.option_;
}

// Overloaded istream operator
istream& operator>>(istream& is, OptionStudent& s)
{
	return is >> (Student&)s >> s.term_ >> s.option_;
}
