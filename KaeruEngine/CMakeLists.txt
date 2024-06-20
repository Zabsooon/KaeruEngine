cmake_minimum_required(VERSION 3.13)
project(KaeruEngine VERSION 0.0.1)

# Output directory for DLL
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(ENGINE_SOURCES
    src/test.h # Test
    src/test.cpp
)

add_library(kaeruengine SHARED ${ENGINE_SOURCES})

# Export symbol for DLL
target_compile_definitions(kaeruengine PRIVATE ENGINE_EXPORTS)

target_include_directories(kaeruengine PUBLIC ${PROJECT_SOURCE_DIR}/src)
