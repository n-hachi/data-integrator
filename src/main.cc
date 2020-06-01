#include <cstdlib>
#include <iostream>

#include "my_funcs.h"

void usage(const char *const program) {
  std::cerr << "Usage: " << program << "<num1> <num2>" << std::endl;
};

int main(int argc, char const *argv[]) {
  if (argc < 3) {
    usage(argv[0]);
    return 1;
  }

  int n1 = strtol(argv[1], nullptr, 10);
  int n2 = strtol(argv[2], nullptr, 10);

  std::cout << "my_max(" << n1 << ", " << n2 << ") = " << my_max(n1, n2);
  std::cout << "my_min(" << n1 << ", " << n2 << ") = " << my_min(n1, n2);

  return 0;
}
