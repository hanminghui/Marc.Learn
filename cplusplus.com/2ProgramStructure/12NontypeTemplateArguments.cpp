// template arguments
#include <iostream>
using namespace std;

// The template parameters can not only include types introduced by class or typename,
// but can also include expressions of a paticular type

template <class T, int N>
T multiply (T val)
{
	return val * N;
}

int main ()
{
	// the value of template parameters is determined on compile-time
	// to generate a different instantiation of the function multiply
	// thus, the value of that argument is never passed during runtime
	cout << multiply <int, 2> (10) << endl;
	cout << multiply <int, 3> (10) << endl;
	cout << multiply <double, 2> (3.14) << endl;
	// So, the second template argument needs to be a constant expression (it cannot be passed a variable).
	// The code below will cause compile error:
// 	int wrong_argument = 2;
// 	cout << multiply <double, wrong_argument> (3.14) << endl;
	// right code:
	const int wrong_argument = 2;
	cout << multiply <double, wrong_argument> (3.14) << endl;
	return 0;
}
