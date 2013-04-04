#include <iostream>
#include <ostream>
#include <iterator>
#include <istream>
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

struct Grades
{
	string				id;			// student ID, e.g., a12345678
	map<string, int>	scores;		// course, score, e.g. COMP3512, 86
};

struct Cmp
{
	string courseId;

	Cmp(const string& course):courseId(course)
	{
	}

	bool operator()(const Grades& g1, const Grades& g2) const
	{
		int score1;
		int score2;

		score1 = ((g1.scores.find(courseId) != g1.scores.end()) ? g1.scores[courseId] : -1);
		score2 = ((g2.scores.find(courseId) != g2.scores.end()) ? g2.scores[courseId] : -1);

		return score1 > score2;
	}
};

ostream& operator<<(ostream&, const Grades& g);
istream& operator>>(istream& is, Grades& g);

int main()
{
	Grades g1, g2, g3;
	vector<Grades> v;

	/* Printing preset grades...
	g1.id = "a00800403";
	g1.scores["COMP3512"] = 80;
	g1.scores["COMP3760"] = 85;

	g2.id = "a00123456";
	g2.scores["COMP3770"] = 56;
	g2.scores["COMP1510"] = 25;
	g1.scores["COMP3760"] = 85;

	g3.id = "a00893928";
	g3.scores["COMP3721"] = 89;
	g3.scores["COMP3940"] = 32;
	g2.scores["COMP3770"] = 56;
	g2.scores["COMP1510"] = 25;

	cout << g1;
	cout << g2;
	cout << g3;
	... in order to fill up a data file */

	while(cin >> g2)
	{
		v.push_back(g2);
	}

	sort(v.begin(), v.end(), Cmp("COMP3512"));

	copy(v.begin(), v.end(), ostream_iterator<Grades>(cout, "\n"));
}

ostream& operator<<(ostream& os, const Grades& g)
{
	os << g.id << endl;
	os << g.scores.size() << endl;
	
	map<string, int>::const_iterator it;

	for(it = g.scores.begin(); it != g.scores.end(); ++it)
	{
		os << it -> first << " " << it -> second << endl;
	}

	return os;
}

istream& operator>>(istream& is, Grades& g)
{
	int courseCount;
	string courseId;
	int courseScore;

	is >> g.id;
	
	if(!is)
	{
		return is;
	}
	
	is >> courseCount;

	g.scores.clear();

	for(int i = 0; i < courseCount; i++)
	{
		is >> courseId;
		is >> courseScore;

		g.scores[courseId] = courseScore;
	}

	return is;
}
