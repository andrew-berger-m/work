//  this code demonstrates internal compiler error in parser in gcc, g++ and mingw in row 24
//  maybe can be more simplified to check for the problem :-)
//  error was detected in 32bit system Yocto Pyro and 64bit system Windows 10, Qt 5.9.6 using MinGW
//  information about compiler switches and instruction sets are not available

#include <string>
#include <map>

union person {
  std::string *woman;
  char *man;
};

struct mapper {
  int id;
  person person;
};

int main()
{
    std::map<std::string, mapper> people;

    char *neversex = nullptr;
    people["johnsmith"] = { 1, {.man =  neversex} };
    return 0;
}
