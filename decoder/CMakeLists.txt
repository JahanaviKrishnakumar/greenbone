cmake_minimum_required(VERSION 3.10)

set(PROJECT "decoder")
project(decoder VERSION 0.1.0 LANGUAGES C CXX)

# Set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
find_package(GTest REQUIRED)

pkg_check_modules(GVM_UTIL REQUIRED IMPORTED_TARGET libgvm_util)

add_executable(${PROJECT}
  ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/decoder.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/utils.c
)

target_include_directories(${PROJECT} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

target_link_libraries(${PROJECT} PRIVATE 
  PkgConfig::GVM_UTIL
)

add_executable(${PROJECT}-test
 ${CMAKE_CURRENT_SOURCE_DIR}/test/test_rot_13_decoder.cpp
 ${CMAKE_CURRENT_SOURCE_DIR}/src/decoder.c
 )

target_include_directories(${PROJECT}-test PRIVATE
 ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

target_link_libraries(${PROJECT}-test PRIVATE 
  PkgConfig::GVM_UTIL
  cjson
  ${GTEST_LIBRARIES}
  ${GTEST_MAIN_LIBRARIES}
  pthread
)

 

