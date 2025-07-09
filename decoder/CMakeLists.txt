cmake_minimum_required(VERSION 3.10)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GVM_UTIL REQUIRED IMPORTED_TARGET libgvm_util)
set(PROJECT "decoder")
project(decoder VERSION 0.1.0 LANGUAGES C CXX)

# Set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)


add_executable(${PROJECT}
  ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/decoder.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/utils.c
)

target_include_directories(${PROJECT} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/inc
 )
 target_link_libraries(${PROJECT} PRIVATE 
    PkgConfig::GVM_UTIL)

