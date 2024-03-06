cmake_minimum_required(VERSION 3.0.0)
project(algo_study VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(algo_study main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
