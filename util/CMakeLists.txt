cmake_minimum_required(VERSION 2.8)
project(util)

set(CMAKE_CXX_STANDARD 11)
include_directories(include)

set(SOURCE_FILES src/msgqueue.cpp src/JPEGDecoder.cpp src/ReceiveSocket.cpp)
add_library(util SHARED ${SOURCE_FILES})
#SET_TARGET_PROPERTIES(util PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_NAME}/../lib)