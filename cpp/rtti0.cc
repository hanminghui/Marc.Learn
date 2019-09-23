#include <iostream>
#include <typeinfo>
using namespace std;

class A
{
public:
     virtual void Print() { cout<<"This is class A."<<endl; }
};

class B : public A
{
public:
     void Print() { cout<<"This is class B."<<endl; }
};

class C : public A
{
public:
     void Print() { cout<<"This is class C."<<endl; }
};

void Handle(A *a)
{
     if (typeid(*a) == typeid(A))
     {
          cout<<"I am a A truly."<<endl;
     }
     else if (typeid(*a) == typeid(B))
     {
          cout<<"I am a B truly."<<endl;
     }
     else if (typeid(*a) == typeid(C))
     {
          cout<<"I am a C truly."<<endl;
     }
     else
     {
          cout<<"I am alone."<<endl;
     }
}

int main()
{
     A *pA = new B();
     Handle(pA);
     delete pA;
     pA = new C();
     Handle(pA);
     return 0;
}
