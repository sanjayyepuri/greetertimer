#include <iostream>
#include <memory>

#include <grpcpp/grpcpp.h>

#include "proto/greetertimer.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

int main() {
    std::cout << "helloworld" << std::endl;
}