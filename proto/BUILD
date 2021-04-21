load("@rules_proto//proto:defs.bzl", "proto_library")
load("@com_github_grpc_grpc//bazel:cc_grpc_library.bzl", "cc_grpc_library")

proto_library(
    name = "helloworld_proto",
    srcs = [
        "greetertimer.proto",
    ],
)

cc_proto_library(
    name = "helloworld_cc_proto",
    deps = ["//proto:helloworld_proto"]
)

cc_grpc_library(
    name = "helloworld_cc_grpc",
    srcs = ["//proto:helloworld_proto"],
    grpc_only = True,
    deps = ["//proto:helloworld_cc_proto"],
    visibility = ["//visibility:public"]
)
