#include <iostream>

int main()
{
	int sum = 0;
	for(int i = 50; i <= 100; ++i)
		sum += i;
	std::cout << "Sum of 50 to 100 inclusive is " << sum << std::endl;

	for(int i = 10; i >= 0; --i)
		std::cout << i << " ";
	std::cout << std::endl;

	std::cout << "Please input two integer:" << std::endl;
	int v1, v2;
	std::cin >> v1 >> v2;
	if(v1 < v2)
	{
		for(int i = v1; i <= v2; ++i)
			std::cout << i << " ";
	}
	else
	{
		for(int i = v1; i >= v2; --i)
			std::cout << i << " ";
	}

	return 0;
}
