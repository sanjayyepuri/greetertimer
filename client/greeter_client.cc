#include <iostream>
#include <memory>

#include <grpcpp/grpcpp.h>

#include "proto/greetertimer.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using helloworld::Greeter;
using helloworld::HelloReply;
using helloworld::HelloRequest;

class GreeterClient
{
public:
    GreeterClient(std::shared_ptr<Channel> channel)
        : stub_(Greeter::NewStub(channel)) {}

    std::string SayHello(const std::string &user)
    {
        HelloRequest request;
        request.set_name(user);

        HelloReply reply;

        ClientContext context;

        Status status = stub_->SayHello(&context, request, &reply);

        if (status.ok())
            return reply.message();
        else
        {
            std::cout << status.error_code() << ": " << status.error_message()
                      << std::endl;

            return "RPC failed";
        }
    }

private:
    std::unique_ptr<Greeter::Stub> stub_;
};

int main()
{
    std::string address = "localhost";
    std::string port = "50051";
    std::string server_address = address + ":" + port;
    std::cout << "Client querying server address: " << server_address << std::endl;

    GreeterClient greeter(grpc::CreateChannel(
        server_address, grpc::InsecureChannelCredentials()));

    std::string user("world");

    std::string reply = greeter.SayHello(user);
    std::cout << "Greeter sent: " << reply << std::endl;

    return 0;
}