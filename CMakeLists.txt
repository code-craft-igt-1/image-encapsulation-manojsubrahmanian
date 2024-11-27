cmake_minimum_required(VERSION 3.10)

# Set the project name
project(ImageBrightener)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Automatically add all .cpp and .h files in the root directory
file(GLOB SOURCES "*.cpp" "*.h")

# Add the executable
add_executable(brightener ${SOURCES})