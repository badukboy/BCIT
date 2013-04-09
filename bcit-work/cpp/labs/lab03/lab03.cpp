#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <fstream>

#define NAMESIZE 20

using namespace std;

struct Record
{
	char firstName[NAMESIZE];
	char lastName[NAMESIZE];
	int score;
};

/* Reads an integer input and validates it */
bool get_valid_int(const string& prompt, int& n);

/* lab03.cpp */
int main(int argc, char *argv[])
{
	int searchNumber;
	fstream fileStream(argv[1]);
	string wordFromFile;
	Record studentRecord;

	if(argc != 2)
	{
		cerr << "WARNING: Invalid number of command line arguments." << endl;
	}

	if(!fileStream)
	{
		cerr << "ERROR: Unable to open file " << argv[1] << "." << endl;

		return 1;
	}

	while(get_valid_int("Enter an integer to search through records:\n> ", searchNumber))
	{
		fileStream.seekg(0, ios::beg);

		if(searchNumber > 0)
		{
			fileStream.clear();

			if(!fileStream.seekg(ios::pos_type(sizeof(studentRecord) * (searchNumber - 1))))
			{
				cerr << "ERROR: File seeking error." << endl;

				continue;
			}

			if(fileStream.read((char *) &studentRecord, sizeof(studentRecord)))
			{
				cout << studentRecord.firstName << " " << studentRecord.lastName << " " << studentRecord.score << endl;
			}
		}

		if(searchNumber < 0)
		{
			fileStream.clear();

			if(!fileStream.seekg(ios::pos_type(sizeof(studentRecord) * (-searchNumber - 1))))
			{
				cerr << "ERROR: File seeking error." << endl;

				continue;
			}

				while(fileStream.read((char *) &studentRecord, sizeof(studentRecord)))
				{
					cout << studentRecord.firstName << " " << studentRecord.lastName << " " << studentRecord.score << endl;
				}
		}

		if(searchNumber == 0)
		{
			return 0;
		}
	}
}

/* Reads an integer input and validates it */
bool get_valid_int(const string& prompt, int& n)
{	
	string line;

	cout << prompt;

	while(getline(cin, line))
	{
		istringstream iss(line);

		if(iss >> n)
		{
			return true;
		}
	}

	return false;
}
