#include <iostream>
class Foo{
public:
  virtual int f(char* c=0){
    std::cout<<"Foo::f()"<<std::endl;
    return 1;
  }
};
 
class Bar{
public:
  virtual void b(int i=0){
    std::cout<<"Bar::b()"<<std::endl;
  }
};
 
class FooDerived:public Foo{
public:
  int f(char* c=0){
    std::cout<<"FooDerived::f()"<<std::endl;
    return 1;
  }
};
 
int main(int argc, char* argv[]){
  typedef  int (Foo::*FPTR) (char*);
  typedef  void (Bar::*BPTR) (int);
  FPTR fptr=&Foo::f;
  BPTR bptr=&Bar::b;
 
  FooDerived objDer;
  (objDer.*fptr)(0);//call: FooDerived::f(), not Foo::f()
 
  Bar obj;
  ( obj.*(BPTR) fptr )(1);//call: Bar::b() , not Foo::f()
}
