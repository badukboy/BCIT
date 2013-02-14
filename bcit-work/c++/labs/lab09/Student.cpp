#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include "Student.h"

using namespace std;

// A valid ID must start with the letter 'a', followed by 8 digits
bool Student::isValidId(const string& id)
{
	string::size_type i = 0;

	// Check length
	if(id.length() == 9)
	{
		// Check 'A' or 'a' prefix
		if(id[i] == 'A' || id[i] == 'a')
		{
			// Check for remaining numbers
			for(i = 1; i < id.size(); i++)
			{
				if(!isdigit(id[i]))
				{
					return false;
				}
			}

			return true;
		}
	}

	return false;
}

// A valid first/last name must be non-empty & cannot contain whitespace
bool Student::isValidName(const string& name)
{
	string::size_type i = 0;

	// If name is empty
	if(name.length() == 0)
	{
		return false;
	}

	// Cannot contain whitespace, only alphabets
	for(i = 0; i < name.size(); i++)
	{
		if(!isalpha(name[i]))
		{
			return false;
		}
	}

	return true;
}

// Display Student to console
void Student::display(ostream& os) const
{
	os << "ID: " << id_ << endl;
	os << "Name: " << firstname_ << ' ' << lastname_ << endl;
}
