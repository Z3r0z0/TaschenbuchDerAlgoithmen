#include <iostream>
#include <string>

void searchWord(std::string text, std::string word);

using namespace std;

int main()
{
	string text = "test string tes endtest";
	string word;
	
	cin >> word;

	searchWord(text, word);
}

void searchWord(string text, string word)
{
	for (int i = 0; i < (text.size() - (word.size() - 1)); i++)
	{
		for(int j = 0; j < word.size(); j++)
		{
			if (text[i + j] != word[j]) {
				i += (j + 1);
				break;
			}

			if (j == (word.size() - 1)) 
			{
				cout << word << " found starting at position " << i << " and ending at position " << (i + j) << endl;
			}
		}
	}
}

