/* run-time type identification */
#include <iostream>
#include <typeinfo>

class A
{
public:
	/* virtual or not will influence the type identification */
	virtual void Print() {std::cout << "This is class A." << std::endl;}
};

class B : public A
{
public:
	void Print() {std::cout << "This is class B." << std::endl;}
};

int main(int argc, char *argv[])
{
	A *pA = new B;
	/* pointer to A */
	std::cout << typeid(pA).name() << std::endl;
	/* novirtual, A */
	/* virtual, B */
	std::cout << typeid(*pA).name() << std::endl;
    return 0;
}
