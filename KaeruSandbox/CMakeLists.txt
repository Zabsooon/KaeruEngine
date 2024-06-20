cmake_minimum_required(VERSION 3.13)
project(KaeruSandbox VERSION 0.0.1)

set(SANDBOX_SOURCES
    src/main.cpp
)

add_executable(kaerusandbox ${SANDBOX_SOURCES})

target_link_libraries(kaerusandbox PRIVATE kaeruengine)

target_include_directories(kaerusandbox PRIVATE ${ENGINE_SOURCE_DIR}/src)
