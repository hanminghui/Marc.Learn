// Statements and flow control
// Statements are executed in the same order in which they appear in a program.
// But programs are not limited to a linear sequence of statements.
// During its process, a program may repeat segments of code, or take decisions and bifurcate.
// C++ provides flow control statements

// compound statement {statement1; statement2; statement3;}
// the entire block is considered a single statement

#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

int main()
{
	// Selection statements: if and else
	//--------------------------------------------------
	// if (condition) statement
	// if (condition) statement1 else statement2
	int grade;
	cout << "Please enter your grade: ";
	cin >> grade;
	if (grade >= 60)
		cout << "Congratulations! You passed the exam!" << endl;
	else
		cout << "Sorry, try again..." << endl;
	
	// Iteration statements (loops) while do for
	//--------------------------------------------------

	// The while loop
	// while (expression) statement
	cout << "Countdown:" << endl;
	int countdown = 10;
	while (countdown > 0)
	{
		cout << countdown << endl;
		// add practical delay
		this_thread::sleep_for (chrono::seconds(1));
		// the loop should end at some point,
		// and thus the statement shall alter values checked in the condition in some way
		// so as to force it to become false at some point.
		--countdown;
	}
	cout << "liftoff!\n";

	// The do-while loop
	// do statement while (condition)
	// guarantee at least one execution of statement, even if condition is never fulfilled
	cin.ignore();
	string str;
	do
	{
		cout << "Input something (goodbye to exit):" << endl;
		getline (cin, str);
		cout << "You entered: " << str << endl;
	}
	while (str != "goodbye");

	// The for loop
	// for (initialization; condition; increase) statement;
	for (int i = 10; i > 0; i--)
		cout << i << ", ";
	cout << "liftoff!" << endl;
	// the three fields in a for-loop are optional
	// these are not statements, but rather, simple expressions
	// thus, cannot be replaced by a block. 
	// As expressions they can make use of the comma operator ,
	for (int n = 0, m = 100; n != m; ++n, --m)
		cout << n << " ";
	cout << endl;

	// Range-based for loop
	// for (declaration : range) statement;
	// declaration declares some variable able to take the value of an element in this range.
	// ranges are sequences of elements, including arrays, containers,
	// and any other type supporting the functions begin and end
	string hi {"Hello!"};
	for (char c : hi)
		cout << "[" << c << "]";
	cout << "\n";
	// Ranged based loops usually also make use of type deduction for the type of the elements with auto.
	for (auto c : hi)
		cout << "[" << c << "]";
	cout << "\n";

	// Jump statements
	//--------------------------------------------------
	// jump statements allow altering the flow of a program by perfoming jumps to specific locations.

	// The break statement
	for (int i = 10; i > 0; --i)
	{
		cout << i << ", ";
		if (i == 3)
		{
			cout << "Something wrong, countdown aborted!" << endl;
			break;
		}
	}

	// The continue statement
	for (int i = 10; i > 0; --i)
	{
		if (i == 5)
		{
			cout << "(cough), ";
			continue;
		}
		cout << i << ", ";
	}
	cout << "liftoff!\n";

	// The goto statement
	// goto allows to make absolute jump to another point in the program
	// ignores nesting levels
	// Therefore, it is a feature to use with care,
	// and preferably within the same block of statements, especially in the presence of local variables.
	// The destination point is identified by a label. 
	// A label is made of a valid identifier followed by a colon :
	int num = 10;
mylabel:
	cout << num << ", ";
	num--;
	if (num > 0) goto mylabel;
	cout << "liftoff!\n";

	// Another selection statement: switch
	//--------------------------------------------------
	int x;
	cout << "Please enter an integer: ";
	cin >> x;
	switch(x)
	{
		case 1:
		case 2:
		case 3:
			cout << "x is 1, 2, or 3" << endl;
			break;
		default:
			cout << "x is not 1, 2, or 3" << endl;
	}
	// To check for ranges or values that are not constant,
	// it is better to use concatenations of if and else if statements.
	
	return 0;
}
