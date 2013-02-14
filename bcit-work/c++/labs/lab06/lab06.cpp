#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <fstream>
#include <bitset>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;
#define N 1000000

string findKey(int number);

int main()
{	
	bitset<N> isprime;
	map<string, vector<int> > m;
	int currentMax = 0;

	isprime.set();

	for(size_t i = 2; i * i < N; i++)
	{
		if(isprime[i])
		{
			for(size_t j = 2; (j * i) < N; j++)
			{
				isprime[j * i] = 0;
			}
		}
	}
	
	for(size_t i = 100000; i < N; i++)
	{
		if(isprime[i])
		{
			m[findKey(i)].push_back(i);
		}
	}

	map<string, vector<int> >::iterator it, maxStart;

	for(it = m.begin(); it != m.end(); it++)
	{
		if(it->second.size() > currentMax)
		{
			maxStart = it;
			currentMax = it->second.size();
		}
	}

	cout << currentMax << endl;

	for(vector<int>::size_type i = 0; i < maxStart->second.size(); i++)
	{
		cout << maxStart->second[i] << endl;
	}

	return 0;
}

string findKey(int number)
{
	ostringstream os;
	os << number;
	string myNumber = os.str();

	sort(myNumber.begin(), myNumber.end());

	return myNumber;
}
