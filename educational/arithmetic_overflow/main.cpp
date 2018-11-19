#include <iostream>
 
main() {
  unsigned char c1, c2, c3;
 
  c1 = 0xff;
  c2 = 0xff;
  c3 = c1 * c2;
 
  __asm__("pushf;");
  std::cout << "It was ";
  __asm__("popf;");
  __asm__("jo end;");
  std::cout << "not ";
   __asm__("end:");
  std::cout << "arithmetic overflow." << std::endl;
}
