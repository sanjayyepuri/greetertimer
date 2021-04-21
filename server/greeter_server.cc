#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>

#include "proto/greetertimer.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

using helloworld::Greeter;
using helloworld::HelloRequest;
using helloworld::HelloReply;

class GreeterServiceImpl final : public Greeter::Service {

    Status SayHello(ServerContext *ctx, const HelloRequest *request,
                    HelloReply *reply) override
    {
        std::string prefix("hello ");
        reply->set_message(prefix + request->name());

        return Status::OK;
    }
};

void RunServer() {
    std::string address = "0.0.0.0";
    std::string port = "50051";
    std::string server_address = address + ":" + port;
    GreeterServiceImpl service;

    ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());

    builder.RegisterService(&service);
    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on: " << server_address << std::endl;

    server->Wait();
}

int main()
{
    RunServer();
    return 0;
}