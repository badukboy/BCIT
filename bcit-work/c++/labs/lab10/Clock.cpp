#include <iostream>
#include <sstream>
#include <iomanip>
#include "Clock.h"

using namespace std;

// Constructor takes in hour and minute seperately
Clock::Clock(int hour, int min):
	hour_(hour), min_(min)
{
	if(!isValidTimeInt(hour_, min_))
	{
		throw "Error: hour or minute input error!";
	}
}

// Constructor takes in time as a full string
Clock::Clock(const string& s)
{
	if(!isValidTimeStr(s))
	{
		throw "Error: time input error!";
	}
	else
	{
		istringstream iss(s);
		int hour;
		int min;
		char timeSeparator;
		
		// String example: "12:30"
		if(iss >> hour >> timeSeparator >> min)
		{
			hour_ = hour;
			min_ = min;
		}
	}
}

// A valid time is one with an hour from 0 to 23 and minute from 0 to 59
bool Clock::isValidTimeInt(const int& hour, const int& min)
{
	if(hour >= 0 && hour <= 23 && min >= 0 && min <= 59)
	{
		return true;
	}

	return false;
}

// A valid string time is in the form of 'H:M'
bool Clock::isValidTimeStr(const string& s)
{
	istringstream iss(s);
	int hour;
	int min;
	char timeSeparator;

	if(iss >> hour >> timeSeparator >> min)
	{
		if(hour >= 0 && hour <= 23 && min >= 0 && min <= 59)
		{
			return true;
		}
	}

	return false;
}

// Prefix minute increment
Clock& Clock::operator++()
{
	min_++;

	if(min_ > 59)
	{
		min_ = 0;
		hour_++;

		if(hour_ > 23)
		{
			hour_ = 0;
		}

	}

	return *this;
}

// Postfix minute increment
Clock Clock::operator++(int)
{
	Clock tmp(*this);
	++*this;

	return tmp;
}

// Print the Clock in 12-hour format
void Clock::print() const
{
	string dayHalf;
	int hour = hour_;
	int min = min_;

	// Noon
	if(hour == 12)
	{
		dayHalf = "PM";
	}

	// Midnight
	if(hour == 0)
	{
		dayHalf = "AM";
		hour = 12;
	}

	// First half of day
	if(hour < 12 && hour > 0)
	{
		dayHalf = "AM";
	}
	
	// Second half of day
	if(hour > 12 && hour < 24)
	{
		hour -= 12;
		dayHalf = "PM";
	}

	cout << setw(2) << setfill('0') << hour;
	cout << ':';
	cout << setw(2) << setfill('0') << min;
	cout << dayHalf << endl;
}

// Overloaded ostream operator
ostream& operator<<(ostream& os, const Clock& c)
{
	os << setw(2) << setfill('0') << c.hour_;
	os << ':';
	os << setw(2) << setfill('0') << c.min_;

	return os;
}

// Overloaded equality operator
bool operator==(const Clock& lhs, const Clock& rhs)
{
	return lhs.hour_ == rhs.hour_ && lhs.min_ == rhs.min_;
}

// Overloaded less than operator
bool operator<(const Clock& lhs, const Clock& rhs)
{
	return lhs.hour_ < rhs.hour_ || (lhs.hour_ == rhs.hour_ && lhs.min_ < rhs.min_);
}

// Overloaded less than or equal to operator
bool operator<=(const Clock& lhs, const Clock& rhs)
{
	return lhs < rhs || lhs == rhs;
}

// Overloaded greater than or equal to operator
bool operator>=(const Clock& lhs, const Clock& rhs)
{
	return !(lhs < rhs);
}

// Overloaded greater than operator
bool operator>(const Clock& lhs, const Clock& rhs)
{
	return !(lhs <= rhs);
}
