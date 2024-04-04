// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to check if the given
// string is a comment or not
void isComment(string line)
{

	// If two continuous slashes
	// precedes the comment
	if (line.size()>=2 && line[0] == '/' && line[1] == '/') {

		cout << "It is a single-line comment";
		return;
	}

	if (line.size()>=4 && line[line.size() - 2] == '*'
		&& line[line.size() - 1] == '/' && line[0] == '/' && line[1] == '*') {

		cout << "It is a multi-line comment";
		return;
	}

	cout << "It is not a comment";
}

// Driver Code
int main()
{
	// Given string
	string line = "/*GeeksForGeeks GeeksForGeeks*/";

	// Function call to check whether then
	// given string is a comment or not
	isComment(line);

	return 0;
}
