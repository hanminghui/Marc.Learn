#include <iostream>

int main()
{
	std::cout << "Please enter some integers, and CTRL+D to stop" << std::endl;
	int sum = 0, num = 0;
	for(;std::cin >> num;)
	{
		sum += num;
	}
	std::cout << "The sum is " << sum << std::endl;
	return 0;
}
