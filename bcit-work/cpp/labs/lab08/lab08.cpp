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
#include <deque>

using namespace std;

class BufferedInput
{
	public:
		BufferedInput(istream& in, size_t capacity = 1)
			:inp_(&in), capacity_(capacity)
		{
		}

		// If there is a char in unread_, use that char
		// If there is no char in unread_, store a char from the stream into unread_
		// Store char into the front of read_
		// Resize read_ accordingly
		bool get(char& c)
		{
			if(good_ == false)								// If state is false...
			{
				return false;								// Return FAILURE
			}

			if(!unread_.empty())							// If unread is not empty...
			{
				read_.push_front(unread_.front());			// Store the char into the front of read
				
				if(read_.size() > capacity_)				// If the size of read is greater than the capacity...
				{
					read_.resize(capacity_);				// ...Resize read accordingly
				}

				c = unread_.front();						// Store the front of unread into c
				unread_.pop_front();						// Remove the front of unread

				return true;								// Return SUCCESS
			}
			else                                            // If unread is empty...
			{
				inp_ -> get(c);								// Get a char from the stream

				if(!*inp_)									// If file stream fails...
				{
					cerr << "Stream error!" << endl;
					good_ = false;							// ...Set state to false

					return false;							// Return FAILURE
				}

				read_.push_front(c);						// Store the char into the front of read

				if(read_.size() > capacity_)				// If the size of read is greater than the capacity...
				{
					read_.resize(capacity_);				// ...Resize read accordingly
				}

				return true;								// Return SUCCESS
			}
		}

		bool unget()
		{
			if(good_ == false)								// If state is false...			
			{
				return false;								// Return FAILURE
			}

			if(!read_.empty())								// If thread is not empty...
			{
				unread_.push_front(read_.front());			// Store the char from the front of read into the front of unread
				read_.pop_front();							// Remove the char from the front of read

				return true;								// Return SUCCESS
			}
			
			good_ = false;									// ...Otherwise set state to false

			return false;									// Return FAILURE
		}

		void clear()
		{
			good_ = true;
		}

	private:
		istream *inp_;			// pointer to input stream
		size_t capacity_;		// maximum number of consecutive calls of unget() allowed
		bool good_;				// whether BufferedInput is in a "good" state
		deque<char> unread_;	// stores characters to be read
		deque<char> read_;		// stores characters already read
};

int main()
{
	ifstream myFile;
	myFile.open("testFile");

	BufferedInput bi(myFile, 1);

	char c;

	bi.clear();

	bi.get(c);			// Go to 'h'
	cout << c << endl;	// 'h'

	bi.get(c);			// Go to 'e'
	cout << c << endl;  // 'e'

	bi.unget();			// Back to 'e'

	bi.get(c);			// Go to 'e'
	cout << c << endl;	// 'e'

	bi.get(c);			// Go to 'l'
	cout << c << endl;	// 'l'

	bi.get(c);			// Go to 'l'
	cout << c << endl;	// 'l'

	bi.get(c);			// Go to 'o'
	cout << c << endl;	// 'o'

	bi.unget();			// Back to 'o'

	bi.get(c);			// Go to 'o'
	cout << c << endl;	// 'o'

	bi.unget();			// Back to 'o'

	bi.get(c);			// Go to 'o'
	cout << c << endl;	// 'o'

	bi.unget();			// Back to 'o'

	bi.get(c);			// Go to 'o'
	cout << c << endl;	// 'o'


	myFile.close();

	return 0;
}
