#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <fstream>

using namespace std;

string reverse(const string& s);
string squeeze(const string& s, char c);
string delete_all(const string& s, const string& junk);
//vector<string> split(const string& s, const string& delim);

int main()
{
	cout << reverse("hello") << endl;
	cout << squeeze("naahaaasapeemaapetilon", 'a');

	return 0;
}

string reverse(const string& s)
{
	size_t i = 0;
	size_t j = s.size();
	string newString(s);

	for(i = 0, j = s.size() - 1; i < s.size(); i++, j--)
	{
		newString[j] = s[i];
	}

	return newString;

}

string squeeze(const string& s, char c)
{
	size_t i = 0;
	int foundChar = 0;
	string newString;

	if(s.size() == 0)
	{
		return newString;
	}

	foundChar = s[0] == c;
	newString += s[0];

	for(i = 1; i < s.size(); i++)
	{
		if(s[i] == c && foundChar == 1)
		{
			continue;
		}

		newString += s[i];
		foundChar = s[i] == c;
	}

	return newString;
}
/*
string delete_all(const string& s, const string& junk)
{
	size_t start = 0;
	size_t pos = 0;
	string token;
	string newString;

	// as long as we can find junk
	// append the portion from the "starting position" to the location of junk
	while((start = s.find(junk, start)) != string::npos)
	{
		newString += s.replace(start, s.size(), junk);
		start += junk.size();
	}

	return newString;
}
*/
