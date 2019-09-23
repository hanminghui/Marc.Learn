#include <iostream>

class A
{
public:
	virtual void Print() {std::cout << "This is class A." << std::endl;}
};

class B
{
public:
	virtual void Print() {std::cout << "This is class B." << std::endl;}
};

class C : public A, public B
{
public:
	virtual void Print() {std::cout << "This is class C." << std::endl;}
};

int main(int argc, char *argv[])
{
	A *pA = new C;
	pA->Print();
// 	C *pC = pA;    /* error */
	C *pC = dynamic_cast<C *>(pA);
	if(pC)
	{
		pC->Print();
	}
    return 0;
}
