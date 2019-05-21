// Preprocessor directives
// --------------------------------------------------------------------------------

// preceded by a hash sign # , and no semicolon ;
// These lines are not program statements but directives for the preprocessor.
// The preprocessor examines the code before actual compilation of code begins 
// and resolves all these directives before any code is actually generated by 
// regular statements.


#include <iostream>
#include <cmath>
#include "12test.h"
using namespace std;

// The only way a preprocessor directive can extend through more than one line is
// by preceding the newline character at the end of the line by a backslash ( \ )
#define FUCK \
	"It's really a fucking thing."

// (1) macro definitions ( #define, #undef )
//--------------------------------------------------------------------------------
// #define identifier replacement
// it replaces any occurrence of identifier in the rest of code by replacement.
// This repacement can be an expression, a statement, a block or simply anything.
#define TABLE_NUM 100
#define SHIT main ()
#define OVER \
	cout << "captain, program done. over" << endl; \
	return 0;

// function macro
// ------------------------------
// #define can work also with parameters to define function macros:
// this will replace getmax() followed by two arguments by the replacement,
// but also replace each argument by its identifier, just as a function.
#define getmax(a,b) a>b?a:b
// NOTE the (), a,b can be expression, this will avoid errors by direct replacement
#define getmin(a,b) ((a)<(b)?(a):(b))

int SHIT
{
	cout << FUCK << endl;
	cout << endl;

	int tables1[TABLE_NUM];
	cout << "There are " << sizeof(tables1) / sizeof(int) << " tables." << endl;
	cout << endl;
// Defined macros are not affected by block structure.
// A macro lasts until it is undefined with #undef
#undef TABLE_NUM

	int x = 4, y = 9;
	int max = getmax(4,9);
	cout << max << " is bigger than " << getmin(4,9) << endl;
	cout << endl;

// redefine of TABLE_NUM
#define TABLE_NUM 200
	int tables2[TABLE_NUM];
	cout << "There are " << sizeof(tables2) / sizeof(int) << " tables." << endl;
	cout << endl;

// function macro definitions accept two special operator # and ## in replacement
// the operator #, followed by a parameter name,
// is replaced by a string literal that contains the argument passed
#define str(x) #x
	cout << str(what?) << endl;		// this would be translated into cout << "what?";
// the operator ## concatenates two arguments leaving no blank spaces between them:
#define glue(a,b) a ## b
	glue(c,out) << "## glue test" << endl;	// translated into cout << "## glue test"
	cout << endl;

// (2) Conditional inclusions ( #ifdef , #ifndef , #if , #endif , #else , and #elif )
// --------------------------------------------------------------------------------
// These directives allow to include or discard part of the code of a program 
// if a certain condition is met.

// #undef TABLE_NUM		// toggle(1)
// comment this or not to change between #ifdef and #ifndef

// #ifdef
// ------------------------------
#ifdef TABLE_NUM
	cout << "TABLE_NUM defined." << endl;
#endif

// #ifndef
// ------------------------------
#ifndef TABLE_NUM
#define TABLE_NUM 234
	cout << "TABLE_NUM is not defined. Define it to 234:" << endl;
#endif
	int tables3[TABLE_NUM];
	// if the TABLE_SIZE macro is defined, it's 200, otherwise 234
	cout << "There are " << sizeof(tables3) / sizeof(int) << " tables." << endl;
	cout << endl;
// #if #else and #elif
// ------------------------------
#undef TABLE_NUM		// toggle(2)
#define TABLE_NUM 99	// toggle(2)
	int tables4[TABLE_NUM];
	cout << "Now, there are " << sizeof(tables4) / sizeof(int) << " tables." << endl;

// change the toggle1 and toggle2 to test the three different conditions
#if TABLE_NUM > 220
	cout << "There are more than 220 tables." << endl;
#undef TABLE_NUM
#define TABLE_NUM 220
#elif TABLE_NUM > 100
	cout << "There are more than 100, less than 220 tables." << endl;
#else
	cout << "There are less than 100 tables." << endl;
#endif
	cout << endl;

// The behavior of #ifdef and #ifndef can also be achieved by using the special operators
// defined and !defined respectively in any #if or #elif directive:
#if defined ARRAY_SIZE
#define TABLE_SIZE ARRAY_SIZE
#elif !defined BUFFER_SIZE
#define TABLE_SIZE 128
#else
#define TABLE_SIZE BUFFER_SIZE
#endif

// (3) Line control ( #line )
// --------------------------------------------------------------------------------
// syntax:  #line number "filename"
// control the compile error message, both the line number and the file name
// #line 20 "assigning variable"
// int a?;		// toggle(3), compile this will cause an error below:
/*
assigning variable: In function ‘int main()’:
assigning variable:20:6: error: expected initializer before ‘?’ token
*/

// (4) Error directive ( #error )
// --------------------------------------------------------------------------------
// This directive aborts the compilation process when it is found,
// generating a compilation error that can be specified as its parameter:
// #undef __cplusplus		// toggle (4)
#ifndef __cplusplus
#error A C++ compiler is required!
#endif
// This example aborts the compilation process 
// if the macro name __cplusplus is not defined 
// (this macro name is defined by default in all C++ compilers).

// (5) Source file inclusion ( #include )
// --------------------------------------------------------------------------------
// When preprocessor finds an #include directive 
// it replaces it by the entire content of the specified header or file.
// There are two ways to use #include:
// #include <cmath>			// includes headers provided by the implementation
// #include "12test.h"		// includes a file
	test t;
	t.print();
	cout << endl;

// (6) Pragma directive ( #pragma )
// --------------------------------------------------------------------------------
/*
This directive is used to specify diverse options to the compiler. 
These options are specific for the platform and the compiler you use. 
Consult the manual or the reference of your compiler for more information 
on the possible parameters that you can define with #pragma.

If the compiler does not support a specific argument for #pragma, 
it is ignored - no syntax error is generated.
*/

// (7) Predefined macro names
// --------------------------------------------------------------------------------

// The following macro names are always defined 
// (they all begin and end with two underscore characters, __):
// __LINE__ __FILE__ __DATE__ __TIME__ __cplusplus __STDC_HOSTED__

	cout << "it's " << __LINE__ << " line in the source code." << endl;
	cout << "compile file name: " << __FILE__ << endl;
	cout << "compile date: " << __DATE__ << endl;
	cout << "compile time: " << __TIME__ << endl;
	cout << "the version of the standard supported by the compiler: " 
	     << __cplusplus << endl;
	cout << "if the implementation is a hosted implementation\n" 
	     << "(with all standard headers available) 1 or 0 : " << __STDC_HOSTED__ << endl;
	cout << endl;

// The following macros are optionally defined, 
// generally depending on whether a feature is available:
	cout << "__STDC__ : " << __STDC__ << endl;
	cout << "__VERSION__ : " << __VERSION__ << endl;
	cout << "the date of the Unicode standard followed by " 
	     << "the encoding of wchar_t characters: " << endl;
	cout << "__STDC_ISO_10646__ : " << __STDC_ISO_10646__ << endl; 
	cout << "If the program can have more than one thread: " << endl;
	cout << "__STDC_NO_THREADS__ : " << __STDC_NO_THREADS__ << endl;
	cout << endl;

	OVER
}                                               