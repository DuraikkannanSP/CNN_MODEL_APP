cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directories
include_directories(operators/include utilities/include include)

# Add source files
set(SOURCES
    operators/src/conv.cpp
    operators/src/relu.cpp
    operators/src/max_pooling.cpp
    operators/src/flattern.cpp
    operators/src/dense.cpp
    operators/src/softmax.cpp
    utilities/src/read_data.cpp
)

# Test executable
add_executable(test Test_Operators/test.cpp ${SOURCES})


