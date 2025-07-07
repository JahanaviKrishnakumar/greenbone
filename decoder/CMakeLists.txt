cmake_minimum_required(VERSION 3.10)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GVM_UTIL REQUIRED IMPORTED_TARGET libgvm_util)

project(decoder VERSION 0.1.0 LANGUAGES C)

# Set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Add source files
add_executable(decoder src/main.c)

target_include_directories(decoder PRIVATE inc)
target_link_libraries(decoder PRIVATE 
    PkgConfig::GVM_UTIL)