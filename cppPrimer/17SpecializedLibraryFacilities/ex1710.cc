#include <iostream>
#include <bitset>

int main(int argc, char *argv[])
{
    size_t pos[] = {1,2,3,5,8,13,21};
	std::bitset<32> bit;
	std::cout << bit << std::endl;
	for(size_t i = 0; i < sizeof(pos)/sizeof(*pos); i++)
	{
	    bit.set(pos[i]);
	}
	std::cout << bit << std::endl;
    return 0;
}
