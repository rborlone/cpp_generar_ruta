cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(projectName VERSION 0.1.0 LANGUAGES C CXX)
find_package( fmt REQUIRED )
add_executable(projectName main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} fmt::fmt)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_test(NAME test1 COMMAND ${CMAKE_BUILD_RPATH}/projectName)
