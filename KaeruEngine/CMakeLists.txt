cmake_minimum_required(VERSION 3.13)
project(KaeruEngine VERSION 0.0.1)

# Output directory for DLL
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(ENGINE_LOGGING_HEADERS
    src/Kaeru/logging/LogWorker.h 
    src/Kaeru/logging/LogQueue.h
    src/Kaeru/logging/LogMessage.h
    src/Kaeru/logging/Logger.h
    src/Kaeru/logging/LogDestination.h
)

set(ENGINE_LOGGING_SOURCES
    src/Kaeru/logging/LogWorker.cpp 
    src/Kaeru/logging/LogQueue.cpp
    src/Kaeru/logging/LogMessage.cpp
    src/Kaeru/logging/Logger.cpp
    src/Kaeru/logging/LogDestination.cpp
)

set(ENGINE_SOURCES
    src/Kaeru.h
    src/Kaeru/EntryPoint.h 
    src/Kaeru/Core.h
    src/Kaeru/Application.cpp
    ${ENGINE_LOGGING_HEADERS}
    ${ENGINE_LOGGING_SOURCES} 
)

add_library(kaeruengine SHARED ${ENGINE_SOURCES})

# Export symbol for DLL
target_compile_definitions(kaeruengine PRIVATE ENGINE_EXPORTS)

target_include_directories(kaeruengine PUBLIC ${PROJECT_SOURCE_DIR}/src)
