cmake_minimum_required(VERSION 3.5)

project(snowflake)

############################################################
# Create a library
############################################################

# Generate the shared library from the library sources
add_library(snowflake SHARED 
    src/snowflake.cpp
)

target_include_directories(snowflake
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)

############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(photon_dance_snowflake_tester
    src/main.cpp
)

# link the new snowflake target with the photon_dance_snowflake_tester target
target_link_libraries( photon_dance_snowflake_tester
    PRIVATE 
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
