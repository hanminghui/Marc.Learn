#include <iostream>

class A
{
public:
	/* with virtual or no virtual, will influence the output
	 */
	/* no virtual, will call the function */
	void Print() {std::cout << "This is class A." << std::endl;}

	/* with virtual, segmentation fault */
	/* cannot find vtable in nullptr */
// 	virtual void Print() {std::cout << "This is class A." << std::endl;}
};

int main(int argc, char *argv[])
{
    A* pA = nullptr;
	pA->Print();
    return 0;
}
