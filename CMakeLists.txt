cmake_minimum_required(VERSION 3.13)
project(Kaeru)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(KaeruEngine)
add_subdirectory(KaeruSandbox)

set(ENGINE_SOURCE_DIR ${CMAKE_SOURCE_DIR}/KaeruEngine)
set(ENGINE_BINARY_DIR ${CMAKE_BINARY_DIR}/KaeruEngine)

include_directories(${ENGINE_SOURCE_DIR}/src)
link_directories(${ENGINE_BINARY_DIR}/lib)

add_dependencies(kaerusandbox kaeruengine)
