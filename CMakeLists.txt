cmake_minimum_required(VERSION 3.10)

# set the project name
project(prett)

# add the executable
add_executable(${PROJECT_NAME} src/main.cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

# gulrak/filesystem
add_subdirectory(lib/fs)
target_link_libraries(${PROJECT_NAME} ghc_filesystem)

# fmtlib/fmt
add_subdirectory(lib/fmt)
target_link_libraries(${PROJECT_NAME} fmt::fmt)

add_subdirectory(lib/ccore)
target_link_libraries(${PROJECT_NAME} ccore)
