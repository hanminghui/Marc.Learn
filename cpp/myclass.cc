#include <iostream>
using namespace std;

class MyClass
{
public:
void fun(void){};
};
 
 
int main(void)
{
 void (MyClass::*fptr) (void) = &MyClass::fun;
 cout << &fptr << endl;
 return 0;
}
