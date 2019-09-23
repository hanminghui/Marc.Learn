#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>
class Printer{//An abstract printing machine
public:
  void Copy(char * buff, const char * source){//copy the file
    strcpy(buff, source);
  }
  void Append(char * buff, const char * source){//extend the file
    strcat(buff, source);
  }
};
 
enum OPTIONS { COPY, APPEND };//two possible commands in the menu.
typedef void(Printer::*PTR) (char*, const char*);//pointer-to-member function 
 
void working(OPTIONS option,
Printer* machine,
char* buff,
const char* infostr){
 
  PTR pmf[2]= {&Printer::Copy, &Printer::Append}; //pointer array 
 
  switch (option){
  case COPY:
    (machine->*pmf[COPY])(buff, infostr);
    break;
  case APPEND:
    (machine->*pmf[APPEND])(buff, infostr);
    break;
  }
}
 
int main(){
  OPTIONS option; 
  Printer machine;
  char buff[40];//target
 
  working(COPY, &machine, buff, "Strings ");  
  working(APPEND, &machine, buff, "are concatenated! ");
//   working(APPEND, &machine, buff, "test ");
//   working(COPY, &machine, buff, "nothing");  
 
  std::cout<<buff<<std::endl;
} 
