// CTA5_PROG3_STEVENDIMMIT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void reverseFileContent(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile); //open inputFile
    vector<char> charStack; //use vector as a stack to reverse chars
    char ch;
    while (inFile.get(ch)) {
        charStack.push_back(ch); // push char to vector
    }
    ofstream outFile(outputFile);
    for (int i = charStack.size() - 1; i >= 0; --i) {
        outFile.put(charStack[i]); //write chars to output in reverse order
        
    }
    outFile.close(); //close reversed file for saftey
}

int main() {
    string inputFile = "CSC450_CT5_mod5.txt";  // original file name
    string reverseFile = "CSC450-mod5-reverse.txt";  // reverse file name
	string userInput;
	ofstream myFile(inputFile, ios::app);  //open in append mode using ios::app
	if (myFile.is_open())
	{
        cout << "Enter text to append to the file: ";
        getline(cin, userInput); //get userinput
        myFile << userInput << endl;  // add userinput tofile
        myFile.close();  //close file for saftey
        cout << "Data written to file successfully!" << endl;
	}
	else
		cout << "Unable to open file";

    reverseFileContent(inputFile, reverseFile);
	return 0;
}