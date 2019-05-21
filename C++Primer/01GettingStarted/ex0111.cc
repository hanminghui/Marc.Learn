#include <iostream>

void show(int a, int b);

int main()
{
	std::cout << "Please input two integer:" << std::endl;
	int v1, v2;
	std::cin >> v1 >> v2;

	std::cout << "The numbers between are: " << std::endl;

	if(v1 < v2)
		show(v1, v2);
	else
		show(v2, v1);
	
	return 0;
}

void show(int a, int b)
{
	while(a <= b)
	{
		std::cout << a << std::endl;
		a++;
	}
}
