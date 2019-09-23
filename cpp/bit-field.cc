#include <iostream>

int main(int argc, char *argv[])
{
    unsigned int v;
	std::cout << "sizeof unsigned int: "<< sizeof(v) << std::endl;

	struct
	{
		unsigned int setting_a : 1;
		unsigned int setting_b : 1;
		unsigned int setting_c : 1;
		unsigned int setting_d : 1;
	} settings;
	std::cout << "sizeof settings: "<< sizeof(settings) << std::endl;
	struct
	{
		unsigned int code1 : 1;
		unsigned int code2 : 2;
		unsigned int code3 : 3;
	} prcode;
	std::cout << "sizeof prcode: "<< sizeof(prcode) << std::endl;
	/* Using an unnamed field of 0 forces the next field to align with next integer.
	 */
	struct
	{
		unsigned int field1 : 1;
		unsigned int        : 0;
		unsigned int field2 : 1;
		unsigned int        : 0;
		unsigned int field3 : 1;
	} stuff;
	std::cout << "sizeof stuff: "<< sizeof(stuff) << std::endl;
	/* a single field is not allowed to overlap the boundary between 2 unsigned ints.
	 * aligned with the unsigned int boundary
	 */
	struct
	{
		unsigned int a : 16;
		unsigned int b : 15;
		unsigned int c : 16;
		unsigned int d : 16;
		unsigned int e : 1;
	} test;
	std::cout << "sizeof test: " << sizeof(test) << std::endl;
	struct
	{
		unsigned int bf1 : 5;
		unsigned int bf2 : 5;
		unsigned int bf3 : 5;
		unsigned int bf4 : 5;
		unsigned int bf5 : 2;
		unsigned int bf6 : 5;
		unsigned int bf7 : 5;
	} bf;
	std::cout << "sizeof bf: " << sizeof(bf) << std::endl;

    return 0;
}
