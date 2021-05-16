cmake_minimum_required(VERSION 3.10)

# set the project name
project(prett)

# add the executable
add_executable(${PROJECT_NAME} src/main.cpp src/util.h src/util.cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# gulrak/filesystem
add_subdirectory(lib/fs)
target_link_libraries(${PROJECT_NAME} ghc_filesystem)

# fmtlib/fmt
add_subdirectory(lib/fmt)
target_link_libraries(${PROJECT_NAME} fmt::fmt)
