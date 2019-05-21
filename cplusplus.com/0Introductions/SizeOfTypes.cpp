// Size of types
// --------------------------------------------------------------------------------

#include <iostream>
using namespace std;

int main ()
{
	cout << "The size of different types in this system:" << endl; 
	cout << "###########################################" << endl;

	int size;

	cout << "          Character types:" << endl; 
	size = sizeof(char);
	cout << "char       : " << size << "bytes, " << 8*size << "bits" << endl;
	size = sizeof(char16_t);
	cout << "char16_t   : " << size << "bytes, " << 8*size << "bits" << endl;
	size = sizeof(char32_t);
	cout << "char32_t   : " << size << "bytes, " << 8*size << "bits" << endl;
	size = sizeof(wchar_t);
	cout << "wchar_t    : " << size << "bytes, " << 8*size << "bits" << endl;

	cout << "-------------------------------------------" << endl;
	cout << "          Integer types:" << endl; 
	size = sizeof(short);
	cout << "short      : " << size << "bytes, " << 8*size << "bits" << endl;
	size = sizeof(int);
	cout << "int        : " << size << "bytes, " << 8*size << "bits" << endl;
	size = sizeof(long);
	cout << "long       : " << size << "bytes, " << 8*size << "bits" << endl;
	size = sizeof(long long);
	cout << "long long  : " << size << "bytes, " << 8*size << "bits" << endl;

	cout << "-------------------------------------------" << endl;
	cout << "          Floating-point types:" << endl; 
	size = sizeof(float);
	cout << "float      : " << size << "bytes, " << 8*size << "bits" << endl;
	size = sizeof(double);
	cout << "double     : " << size << "bytes, " << 8*size << "bits" << endl;
	size = sizeof(long double);
	cout << "long double: " << size << "bytes, " << 8*size << "bits" << endl;

	cout << "-------------------------------------------" << endl;
	cout << "          Boolean types:" << endl; 
	size = sizeof(bool);
	cout << "bool       : " << size << "bytes, " << 8*size << "bits" << endl;

	cout << "-------------------------------------------" << endl;
	cout << "          Pointer:" << endl; 
	size = sizeof(int *);
	cout << "pointer    : " << size << "bytes, " << 8*size << "bits" << endl;
	cout << "###########################################" << endl;

	return 0;
}
