#include<iostream>
#include<string>
using namespace std;

int main()
{
	string alphabets = "abcdefghijklmnopqrstrvwyxz";
	
	string word = "";

	for (int cypher_number = 0; cypher_number < 26 ;cypher_number++) // Repeat for all possible caesar cyphers
	{
		cout << "This is Caesar cypher number: " << cypher_number << endl; 
		
		for (unsigned int text_index = 0; text_index < word.size(); text_index++) // Loop arround the whole text
		{

			for (unsigned int alphabets_index = 0; alphabets_index < alphabets.size(); alphabets_index++) // Match the letter to the alphabet string and increment it by the cypher_number 
			{
				if (word[text_index] == alphabets[alphabets_index])
				{
					if (alphabets_index + cypher_number > 25 )
					{
						cout << alphabets[alphabets_index + cypher_number - 26];
					}
					else
					{
						cout << alphabets[alphabets_index+cypher_number];
					}
					break;
				}
				if (alphabets_index == 26 )
				{
					cout << word[text_index];

					break;
				}
			}
		}

		cout << endl << endl;
	}



	return 0; 
}

