#include <iostream>

int main()
{
	//ok
	std::cout << "/*";
	std::cout << "*/";

	std::cout << /*  "*/" /* "/*"  */;

	// not ok
	std::cout << /* "*/" */;

	return 0;
}
