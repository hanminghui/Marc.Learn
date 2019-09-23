#include <iostream>
#include "Sales_item.h"

int main()
{
	Sales_item currItem, item;
	int count = 0;
	if(std::cin >> currItem)
	{
		Sales_item sumItem = currItem;
		++count;
		while(std::cin >> item)
		{
			if(item.isbn() == currItem.isbn())
			{
				sumItem += item;
				++count;
			}
			else
			{
				std::cout << currItem.isbn() << " have " << count
				          << " sales records." << std::endl;
				std::cout << sumItem << std::endl;
				currItem = item;
				sumItem = currItem;
				count = 1;
			}

		}
		std::cout << currItem.isbn() << " have " << count
				  << " sales records." << std::endl;
		std::cout << sumItem << std::endl;
	}
	return 0;
}
