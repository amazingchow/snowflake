cmake_minimum_required(VERSION 3.5)

project(snowflake)

# Install google benchmark
## https://github.com/google/benchmark#installation
find_package(benchmark 1.5.5 REQUIRED COMPONENTS benchmark benchmark_main)

if(benchmark_FOUND)
    message ("libbenchmark.a and libbenchmark_main.a found")
else()
    message (FATAL_ERROR "cannot find libbenchmark.a and libbenchmark_main.a")
endif()

# Install google protobuf and grpc
## https://github.com/grpc/grpc/blob/master/BUILDING.md
# set(protobuf_DIR /usr/local/lib/cmake/protobuf)
find_package(protobuf 3.14.0.0 REQUIRED COMPONENTS protobuf protoc)

if(protobuf_FOUND)
    message ("libprotobuf and libprotoc found")
else()
    message (FATAL_ERROR "cannot find libprotobuf and libprotoc")
endif()

# set(gRPC_DIR /usr/local/lib/cmake/grpc)
find_package(gRPC 1.35.0 REQUIRED)

if(gRPC_FOUND)
    message ("libgrpc* found")
else()
    message (FATAL_ERROR "cannot find libgrpc*")
endif()

find_package(Threads REQUIRED)

############################################################
# Create a library
############################################################

add_library(snowflake SHARED 
    src/snowflake.cpp
)

target_include_directories(snowflake
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)

###########################################################
# Create the server
###########################################################

add_executable(photon_dance_snowflake_server
    src/server.cpp
)

target_include_directories(photon_dance_snowflake_server
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)

set(snowflake_proto_srcs "${PROJECT_SOURCE_DIR}/include/snowflake/protos/service.grpc.pb.cc")
set(snowflake_proto_hdrs "${PROJECT_SOURCE_DIR}/include/snowflake/protos/service.grpc.pb.h")
set(snowflake_grpc_srcs "${PROJECT_SOURCE_DIR}/include/snowflake/protos/service.pb.cc")
set(snowflake_grpc_hdrs "${PROJECT_SOURCE_DIR}/include/snowflake/protos/service.pb.h")
add_library(snowflake_proto
    ${snowflake_proto_srcs}
    ${snowflake_proto_hdrs}
    ${snowflake_grpc_srcs}
    ${snowflake_grpc_hdrs})
target_link_libraries(photon_dance_snowflake_server
    PRIVATE 
        gRPC::grpc++
        gRPC::grpc++_reflection
        snowflake_proto
        snowflake
)

############################################################
# Create the tester
############################################################

add_executable(photon_dance_snowflake_tester
    src/tester.cpp
)

target_link_libraries(photon_dance_snowflake_tester
    PRIVATE 
        snowflake
)

############################################################
# Create the benchmark_tester
############################################################

add_executable(photon_dance_snowflake_benchmark_tester
    src/benchmark_tester.cpp
)

target_link_libraries( photon_dance_snowflake_benchmark_tester
    PRIVATE 
        benchmark::benchmark
        benchmark::benchmark_main
        snowflake
)

############################################################
# Install
############################################################

# Binaries
# install (TARGETS photon_dance_snowflake_tester
#     DESTINATION bin)

# Library
install (TARGETS snowflake
    LIBRARY DESTINATION lib)
install (TARGETS snowflake_proto
    LIBRARY DESTINATION lib)

# Header files
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ 
    DESTINATION include)

# Config
# install (FILES snowflake.conf
#     DESTINATION etc)
