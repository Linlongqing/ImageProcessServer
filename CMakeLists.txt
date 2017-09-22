cmake_minimum_required(VERSION 2.8)
project(ImageProcessServer)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(util)
include_directories(util/include)
#link_directories(/usr/local/lib)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

set(FFMPEG_LIBS libswscale.so libavcodec.so libavformat.so)

set(SOURCE_FILES main.cpp)
add_executable(ImageProcessServer ${SOURCE_FILES})
target_link_libraries(ImageProcessServer util ${OpenCV_LIBS} ${FFMPEG_LIBS})
SET_TARGET_PROPERTIES(ImageProcessServer  PROPERTIES RUNTIME_OUTPUT_DIRECTORY  ${PROJECT_SOURCE_DIR}/bin)