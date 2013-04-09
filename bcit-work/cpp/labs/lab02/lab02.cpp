#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <fstream>

#define NAMESIZE 20

using namespace std;

/* Structure to hold student name and score out of 100 */
struct Record
{
	char firstName[NAMESIZE];
	char lastName[NAMESIZE];
	int score;
};

/* Reads a word input and validates it */
bool get_valid_word(const string& prompt, string& word, bool (*is_valid)(const string&) = 0);

/* Reads an integer input and validates it */
bool get_valid_int(const string& prompt, int& n, bool (*is_valid)(int) = 0);

/* Determines if word input is within 20 characters and contains only alphabets */
bool is_valid_name(const string& name);

/* Determines if integer input is between 0 and 100 inclusive */
bool is_valid_score(int score);

/* lab02.cpp */
int main()
{
	string inputLastName;
	string inputFirstName;
	int inputScore;

	Record studentRecord;

	/* Only proceed if all three inputs are valid */
	while(get_valid_word("Enter student last name:\n> ", inputLastName, &is_valid_name) &&
		  get_valid_word("Enter student first name:\n> ", inputFirstName, &is_valid_name) &&
		   get_valid_int("Enter student score:\n> ", inputScore, &is_valid_score))

	{
		strcpy(studentRecord.lastName, inputLastName.c_str());
		

		strcpy(studentRecord.firstName, inputFirstName.c_str());

		studentRecord.score = inputScore;

		cerr.write((const char*)&studentRecord, sizeof(studentRecord));
	}
}

/* Reads a word input and validates it */
bool get_valid_word(const string& prompt, string& word, bool (*is_valid_name)(const string&))
{	
	string line;

	cout << prompt;

	while(getline(cin, line))
	{
		istringstream iss(line);

		if(iss >> word && (is_valid_name == 0 || is_valid_name(word)))
		{
			return true;
		}
	}

	return false;
}

/* Reads an integer input and validates it */
bool get_valid_int(const string& prompt, int& n, bool (*is_valid_score)(int))
{	
	string line;

	cout << prompt;

	while(getline(cin, line))
	{
		istringstream iss(line);

		if(iss >> n && (is_valid_score == 0 || is_valid_score(n)))
		{
			return true;
		}
	}

	return false;
}

/* Determines if word input is within 20 characters and contains only alphabets */
bool is_valid_name(const string& name)
{
	string::size_type i;

	if(name.length() <= 20)
	{
		for(i = 0; i < name.size(); i++)
		{
			if(!isalpha(name[i]))
			{
				return false;
			}
		}

		return true;
	}
	
	return false;
}

/* Determines if integer input is between 0 and 100 inclusive */
bool is_valid_score(int score)
{
	if(score >= 0 && score <= 100)
	{
		return true;
	}
	
	return false;
}

