/// Takes 2 files and compares them and display any differences
/// Made it to compare truth tables

#include<string>
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	ifstream table1("magn.txt", ios::in);
	ifstream table2("magn2.txt",ios::in);
	//cout << table1.is_open() << "   " << table2.is_open()<<endl;
	string word1, word2;
	bool IsCorrect = true;	
	while ( getline(table1, word1) && getline(table2, word2))
	{
		if ( word1 == word2 ){ 
		//	cout << 1;
		}
		else
		{
			IsCorrect = false;
			cout << word1 << endl << word2 << endl << endl << endl;
		}
	}
	if (IsCorrect)
		cout << "Your circuit is 100\% correct, CONGRATTTSSSSS!!!!!" << endl; 
	table1.close();
	table2.close();
	return 0;
}

