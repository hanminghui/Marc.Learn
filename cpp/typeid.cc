#include <iostream>
#include <typeinfo>

using namespace std;

int main(int argc, char *argv[])
{
    short s = 2;
	unsigned ui = 10;
	int i = 10;
	char ch = 'a';
	wchar_t wch = L'b';
	float f = 1.0f;
	double d = 2;
	
	cout<<typeid(s).name()<<endl; // short
	cout<<typeid(ui).name()<<endl; // unsigned int
	cout<<typeid(i).name()<<endl; // int
	cout<<typeid(ch).name()<<endl; // char
	cout<<typeid(wch).name()<<endl; // wchar_t
	cout<<typeid(f).name()<<endl; // float
	cout<<typeid(d).name()<<endl; // double

    return 0;
}
