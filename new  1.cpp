/*
 * lab9.cpp
 *
 *  Created on: Apr 3, 2014
 *      Author: Anna Wendt
 *      Course: COSC 246, Winter 2014
 *        Lab#: 9
 *    Due Date: 4-3-14
 * Description: This program will read in characters from a user-specified input-file, and then
 *     report the number of a specific vowel (also user-specified) that occurs on each
 *     line
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// declaring function
void readInput(istream&, char);

int main()
{
	// declaring variables
	char user_vowel, answer;
	char file_name[21];
	ifstream fin;
	ofstream fout;

	// header block
	cout << "Programmer: Anna Wendt\n";
	cout << "Course:     COSC 246, Winter 2014\n";
	cout << "Lab#:       9\n";
	cout << "Due Date:   4-3-14\n";

	// beginning of do-while loop
	do
	{
		//gathering user input
		cout << "\nEnter an input file name: ";
		cin >> file_name;
		fin.open(file_name);

        cout << "Enter a vowel: ";
        cin >> user_vowel;

        // calling function
        readInput(fin, user_vowel);

        // prompting user for input
		cout << "\n\nDo it again? Y or y (for yes), and N or n (for no): ";
		cin >> answer;
	}while(answer == 'Y' || answer == 'y');

	return 0;
}

void readInput(istream& file_name = cin, char user_vowel)
{
	// declaring variables
	int count = 0, vowel_per_line_count = 0, line_count = 0;
	char next;
	do{
		do{
		file_name.get(next);
		//cout << "\n\n" << next << "\n\n";
		if (next == user_vowel)
		{
			count = count + 1;
			vowel_per_line_count = vowel_per_line_count + 1;
		}
		}while (next != '\n');
		line_count = line_count + 1;
		cout << line_count << "- " << vowel_per_line_count;
	}while (file_name >> next);

	cout << "\n\nTotal number of " << user_vowel << " or " << char(tolower(user_vowel)) << ": ";
	cout << count;

	return;
}