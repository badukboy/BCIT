#ifndef OPTIONSTUDENT_H
#define OPTIONSTUDENT_H
#include <iostream>
#include <string>
#include "Student.h"

// OptionStudent.h
class OptionStudent: public Student
{
	public:

		// Constructor
		explicit OptionStudent(const std::string& id = "A11111111",
							   const std::string& firstname = "John",
							   const std::string& lastname = "Doe",
							   int term = 3,
							   const std::string& option = "CS");

		// GET: OptionStudent count
		static size_t count()
		{
			return count_;
		}

		// Display OptionStudent
		virtual void display(std::ostream& os) const;
		
		// Friend declarations
		friend std::ostream& operator<<(std::ostream&, const OptionStudent&);
		friend std::istream& operator>>(std::istream&, OptionStudent&);

	private:

		int term_;
		std::string option_;
		static size_t count_;

		// Validation functions
		static bool isValidTerm(const int& term);
};

#endif
