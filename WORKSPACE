workspace(name = "grpc_greetertimer")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# Load rules for protobufs https://github.com/bazelbuild/rules_proto
# http_archive(
#     name = "rules_proto",
#     sha256 = "602e7161d9195e50246177e7c55b2f39950a9cf7366f74ed5f22fd45750cd208",
#     strip_prefix = "rules_proto-97d8af4dc474595af3900dd85cb3a29ad28cc313",
#     urls = [
#         "https://mirror.bazel.build/github.com/bazelbuild/rules_proto/archive/97d8af4dc474595af3900dd85cb3a29ad28cc313.tar.gz",
#         "https://github.com/bazelbuild/rules_proto/archive/97d8af4dc474595af3900dd85cb3a29ad28cc313.tar.gz",
#     ],
# )
# load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies", "rules_proto_toolchains")
# rules_proto_dependencies()
# rules_proto_toolchains()

## ^^ turns out you don't need the above

# Load rules for grpc https://github.com/grpc/grpc/blob/master/src/cpp/README.md#make
http_archive(
 name = "com_github_grpc_grpc",
    urls = [
        "https://github.com/grpc/grpc/archive/44c40ac23023b7b3dd82744372c06817cc203898.tar.gz",
    ],
    strip_prefix = "grpc-44c40ac23023b7b3dd82744372c06817cc203898",
)
load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")
grpc_deps()
load("@com_github_grpc_grpc//bazel:grpc_extra_deps.bzl", "grpc_extra_deps")
grpc_extra_deps()