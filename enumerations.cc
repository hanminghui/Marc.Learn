/* Enumerations
 */
#include <iostream>

/* unscoped enumeration */
enum color
{
	red,
	green,
	yellow
};

/* scoped enumeration */
enum class peppers
{
	red,
	green,
	yellow
};

/* Unlike an unscoped enumeration, 
 * a scoped enumeration is not implicitly convertible to its integer value. 
 * You need to explicitly convert it to an integer using a cast:
 * std::cout << static_cast<std::underlying_type<A>::type>(a) << std::endl;
 */
template <typename Enumeration>
auto as_integer(Enumeration const value)
    -> typename std::underlying_type<Enumeration>::type
{
    return static_cast<typename std::underlying_type<Enumeration>::type>(value);
}

int main(int argc, char *argv[])
{
	std::cout << "red: "<< red << std::endl;
	std::cout << "green: "<< green << std::endl;
	std::cout << "yellow: "<< yellow << std::endl;
	std::cout << "in pepers: " << std::endl;
	std::cout << "red: "<< int(peppers::red) << std::endl;
	std::cout << "green: "<< as_integer(peppers::green) << std::endl;
	std::cout << "yellow: "<< as_integer(peppers::yellow) << std::endl;

	color hair = red;
	peppers p = peppers::green;
    return 0;
}
