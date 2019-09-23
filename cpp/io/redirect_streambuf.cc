#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[])
{
	std::ifstream in("in.txt");
	/* save the original cin streambuf */
	std::streambuf *cinbuf = std::cin.rdbuf();
	/* redirect to in.txt */
	std::cin.rdbuf(in.rdbuf());

	/* read from in.txt */
	std::string input;
	getline(std::cin, input);

	std::ofstream out("out.txt");
	/* save the original cout streambuf 
	 * and redirect to out.txt in one line*/
	/* rdubf() returns the associated stream buffer
	 * before the operation. */
	std::streambuf *coutbuf = std::cout.rdbuf(out.rdbuf());

	/* write to out.txt */
	std::cout << input;

	/* restore cin and cout */
	std::cin.rdbuf(cinbuf);
	std::cout.rdbuf(coutbuf);
	std::cout << "cin and cout are back, enter something:" << std::endl;
	std::cin >> input;
	std::cout << input << std::endl;

    return 0;
}
