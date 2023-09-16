cmake_minimum_required(VERSION 3.10)

# Define the project name
project(pi-fx)

# Set the C++ standard, e.g., C++11
set(CMAKE_CXX_STANDARD 11)

# Add the executable using main.cpp as the source
add_executable(pi-fx src/main.cpp)

# Link against pthread
find_package(Threads REQUIRED)
target_link_libraries(pi-fx Threads::Threads)
