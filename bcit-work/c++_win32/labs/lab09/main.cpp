#include <iostream>
#include <ostream>
#include <istream>
#include <sstream>
#include "OptionStudent.h"
#include "Student.h"

using namespace std;

// DRIVER
int main()
{
	Student s1("a11111111", "Homer", "Simpson");
	cout << s1 << endl;

	OptionStudent s2("a22222222", "Monty", "Burns", 3, "IS");
	cout << s2 << endl;

	Student s3("AAA", "carl", "carlson");

	s1.display(cout);
	s2.display(cout);
}
