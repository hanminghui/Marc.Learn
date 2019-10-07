#include <iostream>

/* uncomment to disable assert */
// #define NDEBUG
#include <cassert>
/* assert(condition)
 * if condition compare equal to zero, FALSE
 * (1) assert ouputs implementation-specific diagnostic information on stderr
 * (2) and calls std::abort
 */

int main(int argc, char *argv[])
{
	assert(2+2 == 4);
	std::cout << "execution continues past the first assert." << std::endl;
	assert(2+2 == 5);
	std::cout << "Execution continues past the second assert." << std::endl;
    return 0;
}
