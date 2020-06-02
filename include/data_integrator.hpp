#ifndef UPD_MESSENGER_H
#define UPD_MESSENGER_H

#include <netinet/in.h>

namespace messenger {

/**
 * This class integrate datas which receives from some remote node.
 * Remote node has been fixed already, so this instance do not need increase
 * socket count. (in other words, need only fixed count sockets.)
 */
class DataIntegrator {
private:
  int sock_A_ = -1;
  struct sockaddr_in addr_A_;

  int sock_B_ = -1;
  struct sockaddr_in addr_B_;

public:
  static int DEFAULT_PORT;
  static char DEFAULT_IP[];
  DataIntegrator();
};
} // namespace messenger

#endif
