
load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_proto_library")

cc_binary(
    name = "greeter_client",
    srcs = ["greeter_client.cc"],
    deps =[
        "//proto:helloworld_cc_grpc",

        #made available by the http_archive in WORKSPACE
        "@com_github_grpc_grpc//:grpc++",
    ]
)
