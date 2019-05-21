#include <iostream>
#include "Sales_item.h"

int main()
{
	Sales_item currItem, item;
	if(std::cin >> currItem)
	{
		Sales_item sumItem = currItem;
		while(std::cin >> item)
		{
			sumItem += item;
		}
		std::cout << sumItem << std::endl;
	}
	return 0;
}
