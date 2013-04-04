#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>

// Student.h
class Student
{
	public:

		// Constructor
		explicit Student(const std::string& id = "A11111111",
						 const std::string& firstname = "John",
						 const std::string& lastname = "Doe")
		:id_(id), firstname_(firstname), lastname_(lastname)
		{
			if(!isValidId(id_) || !isValidName(firstname_) ||
			   !isValidName(lastname_))
			{
				throw "Error: Invalid name or ID!";
			}
		}

		// Destructor
		virtual ~Student()
		{
		}

		// Display Student
		virtual void display(std::ostream& os) const;

		// Friend declarations
		friend std::ostream& operator<<(std::ostream&, const Student&);
		friend std::istream& operator>>(std::istream&, Student&);

	private:

		std::string id_;
		std::string firstname_;
		std::string lastname_;

		// Validation functions
		static bool isValidId(const std::string& id);
		static bool isValidName(const std::string& name);
};

// Inline overloaded ostream operator
inline std::ostream& operator<<(std::ostream& os, const Student& s)
{
	os << s.id_ <<  ' ' << s.firstname_ << ' ' << s.lastname_;

	return os;
}

// Inline overloaded istream operator
inline std::istream& operator>>(std::istream& is, Student& s)
{
	return is >> s.id_ >> s.firstname_ >> s.lastname_;
}

#endif
