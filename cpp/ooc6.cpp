#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
	string data;
	
// Accepting data

	fstream opf("Book.txt", ios::out);
	
	cout << endl << "Enter contents of file (Enter 'quit' to stop):" << endl << endl;
	
	while (getline(cin, data) && data != "quit")
		opf << data << endl;
		
	opf.close();
	
// Printing contents
	
	fstream ipf("Book.txt");
	
	if (!ipf.is_open()) {
		cout << "File could not be opened!" << endl;
		return 1;
	}
	
	cout << endl << "Contents of the file:" << endl << endl;
	
	while (getline(ipf, data))
		cout << data << endl;
	
	cout << endl;
	
	ipf.close();
	
// Copying contents to another file
	
	ipf.open("Book.txt");
	
	opf.open("Copy.txt", ios::out);
	
	while (getline(ipf, data))
		opf << data << endl;
	
	cout << "Data has been copied successfully to Copy.txt" << endl;
	
	ipf.close();
	opf.close();
	
// Counting number of uppercase alphabets, letters, digits, whitespaces and vowels

    ipf.open("Book.txt");

    char ch;
    int upper = 0, letter = 0, digit = 0, space = 0, vowel = 0;

    if (!ipf.is_open()) {
        cout << "File could not be opened!" << endl;
        return 1;
    }

    while (ipf.get(ch)) {
        if (isupper(ch))
            upper++;
        if (isalpha(ch))
            letter++;
        if (isdigit(ch))
            digit++;
        if (isspace(ch))
            space++;
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            vowel++;
    }

    cout << endl << "Number of uppercase alphabets: " << upper << endl;
    cout << "Number of letters: " << letter << endl;
    cout << "Number of digits: " << digit << endl;
    cout << "Number of whitespaces: " << space << endl;
    cout << "Number of vowels: " << vowel << endl << endl;

    ipf.close();

	return 0;
}
