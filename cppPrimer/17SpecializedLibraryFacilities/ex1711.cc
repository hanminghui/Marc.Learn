#include <iostream>
#include <bitset>
#include <string>

int main(int argc, char *argv[])
{
	/* answers to 10 quiz */
    std::bitset<10> answers;
	answers.set(0);
	answers.set(3);
	answers.set(9);
	for(size_t i = 0; i < answers.size(); i++)
	{
		std::string ans;
		if(answers[i]) ans = "true";
		else ans = "false";
		std::cout << "answer " << i+1 << ": " << ans << std::endl;
	}
    return 0;
}
