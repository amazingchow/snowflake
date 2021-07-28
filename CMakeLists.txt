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

# Header files
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ 
    DESTINATION include)

# Config
# install (FILES snowflake.conf
#     DESTINATION etc)
