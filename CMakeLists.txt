cmake_minimum_required(VERSION 3.26)
project(prett)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${PROJECT_NAME} src/main.c)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion)
target_compile_features(${PROJECT_NAME} PRIVATE c_std_23)
