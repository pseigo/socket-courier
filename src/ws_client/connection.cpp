#include "connection.hpp"

#include <iostream>

namespace ws_client {
  void Connection::hello_world() const {
    std::cout << "Hello, World! This is a connection." << std::endl;
  }
}
