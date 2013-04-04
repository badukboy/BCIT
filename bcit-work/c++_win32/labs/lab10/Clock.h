#ifndef CLOCK_H
#define CLOCK_H
#include <iostream>
#include <string>

class Clock
{
	public:

		// Constructors
		explicit Clock(int hour = 0, int min = 0);
		explicit Clock(const std::string& s);

		// Compiler-generated copy constructor, destructor, assignment operator

		// Operations
		Clock& operator++();		// Increment by 1 minute (prefix)
		Clock operator++(int);		// Increment by 1 minute (postfix)

		// Displays
		void print() const          // Print time in 12-hour format

		// Friend declarations
		friend std::ostream& operator<<(std::ostream&, const Clock&);
		friend bool operator==(const Clock&, const Clock&);
		friend bool operator<(const Clock&, const Clock&);
		friend bool operator<=(const Clock&, const Clock&);
		friend bool operator>=(const Clock&, const Clock&);
		friend bool operator>(const Clock&, const Clock&);

	private:

		int hour_;		// 0 - 23
		int min_;		// 0 - 59
		
		// Validation
		static bool isValidTimeInt(const int& hour, const int& min);
		static bool isValidTimeStr(const std::string& s);
};

#endif
