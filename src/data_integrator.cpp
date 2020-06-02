#include "data_integrator.hpp"

#include <arpa/inet.h>
#include <chrono>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

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

void DataIntegrator::start() {
  is_running_ = true;

  send_th_ = std::thread([this] { SendThreadFunc(); });
}

void DataIntegrator::SendThreadFunc() {
  int a = 0;
  while (is_running_) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << a << std::endl;
    a++;
  }
  std::cout << "exit" << std::endl;
}

void DataIntegrator::shutdown() { is_running_ = false; }

void DataIntegrator::join() { send_th_.join(); }

} // namespace messenger
