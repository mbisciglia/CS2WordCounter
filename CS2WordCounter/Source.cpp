//	Michael Bisciglia & Autumn Gnabasik
//	Project 1 Word Counter
//	Professor Kivolowits
//	Computer Science II
//	28 Feb, 2017


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctype.h>
#include <unordered_map>


using namespace std;


/*
The function Cleaning returns a string, rv, which is only lowercase alphas.
The function is passed in each word from the stringstream using string s,
and is 'cleaned' accordingly by removing all non-alphas and all upercase
alphas into lowercase
*/
string Cleaning(string word)
{
	string rv;
	for (int i = 0; i < word.size(); i++)
	{
		char c = word[i];
		// May not need spaces, but if we don't than we can fix later
		if (isalpha(c))
		{
			rv.push_back(tolower(c));
		}
	}
	return rv;
}








int main(int argc, char * argv[])
{

	ifstream f;
	//	argc must always be >1 or arrc is empty and can not run.
	if (argc > 1)
	{
		//	Passing in the .txt file from our argument, to allow for generality
		f.open(argv[1], std::ios::binary);

		string s;

		if (!f.is_open())
		{
			cout << "This file could not be opened." << endl;
		}

		else
		{
			//	Determines the size of the file
			f.seekg(0, f.end);
			size_t file_size = f.tellg();
			f.seekg(0, f.beg);
			s.resize(file_size);
			f.read(&s[0], file_size);
			f.close();

			//	Reads string s word by word, which will go into string word
			stringstream ss(s);

			//	word is for ss
			//	Single word is taken from file using stringstream
			string word;
			//	Total number of words in file
			int numWords = 0;
			//	Will keep count of how many times each word appears in .txt file
			unordered_map <string, int> wc;
			//	Stringstream will continue to take words from file until the end of file
			while (!ss.eof())
			{
				ss >> word;
				word = Cleaning(word);
				wc[word]++;
				numWords++;
			}
			cout << "Word Counter:" << '\t' << (numWords) << endl;
			cout << "Insertion Counter:" << '\t' << wc.size() << endl;
			for (int i = 2; i < argc; i++)
			{
				//	Argv[i] are words defined in argument, again to allow for generality
				//	This call is used to display the word, and how many times it appears in the .txt file.
				cout << "Count of: " << "\"" << argv[i] << "\" is:" << '\t' << wc[string(argv[i])] << endl;
			}
		}
	}
	//	To ensure argument is filled
	else
	{
		cout << "argc is empty, please enter an argument." << endl;
	}

#if defined (WIN32)
	system("pause");
#endif
	return 0;

}