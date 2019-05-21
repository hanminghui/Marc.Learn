// my first program in C++
// this is a line comment
/*
	this is a block comment
	line1
	line2
*/

// Comments will make your code more readable.

/*
	Blank lines have no effect on a program.
	They simply improve readability of the code.
*/

// lines begin with a hash sign (#) are directives
// read and interpreted by preprocessor.
// the header <iostream> allows to perform standard input and output operations.
#include <iostream>	// Preprocessor directives, they are not statements

using namespace std;	// using declarations
// NOTE that explicit qualification is the only way to guarantee that name collisions never happen.

/*	A function is group of code statements which are given a name.
	functions' definition is introduced with a succession of 
	a type(int), a name(main), and a pair of parentheses(), optionally including parameters.
	In this case, the name is "main".*/

int main()	// initiates the declaration of a function.
{	// { indicates the beginning of the main's function definition
	/* standard character output device
	   the insertion operator( << )
	   a sentence within quotes " "
	   statements end with a semicolon ;
	   */
	cout << "Hello World!";	// the function's body, defines what will happen when main is called
	cout << "I'm a C++ program."
}	// { ends the function
