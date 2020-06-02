#include <cstdlib>
#include <iostream>

#include "data_integrator.hpp"

void usage(const char *const program) {
  std::cerr << "Usage: " << program << "<num1> <num2>" << std::endl;
};

int main(int argc, char const *argv[]) {
  messenger::DataIntegrator di = messenger::DataIntegrator();
  di.start();
  std::this_thread::sleep_for(std::chrono::seconds(10));
  di.shutdown();
  di.join();

  return 0;
}
