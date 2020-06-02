#include "data_integrator.hpp"

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h> /* See NOTES */

namespace messenger {

int DataIntegrator::DEFAULT_PORT = 50000;
char DataIntegrator::DEFAULT_IP[] = "192.168.1.10";

DataIntegrator::DataIntegrator() {
  if ((sock_A_ = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
    throw "socket creation failure";
  }

  addr_A_.sin_family = AF_INET;
  addr_A_.sin_port = htons(DataIntegrator::DEFAULT_PORT);
  addr_A_.sin_addr.s_addr = inet_addr(DataIntegrator::DEFAULT_IP);

  if ((sock_B_ = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
    throw "socket creation failure";
  }

  addr_B_.sin_family = AF_INET;
  addr_B_.sin_port = htons(DataIntegrator::DEFAULT_PORT);
  addr_B_.sin_addr.s_addr = inet_addr(DataIntegrator::DEFAULT_IP);
}

} // namespace messenger
