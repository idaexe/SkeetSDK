cmake_minimum_required(VERSION 4.0)
project(SkeetSDK)

set(CMAKE_CXX_STANDARD 23)

# We've built this with Windows-only in mind, so we shouldn't be worried about other compilers.
if (NOT MSVC)
    message(FATAL_ERROR "Unsupported compiler: only MSVC is supported!")
endif()


set(BASE_OUTPUT_DIR "${CMAKE_SOURCE_DIR}/dist")

# Ninja, Make... (single-config generators)
if(NOT CMAKE_CONFIGURATION_TYPES)
    if(NOT CMAKE_BUILD_TYPE)
        set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
    endif()

    string(TOLOWER ${CMAKE_BUILD_TYPE} BUILD_TYPE_LOWER)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BASE_OUTPUT_DIR}/${BUILD_TYPE_LOWER}")
endif()

# Visual Studio (multi-config generators)
if(CMAKE_CONFIGURATION_TYPES)
    foreach(CONFIGURATION ${CMAKE_CONFIGURATION_TYPES})
        string(TOLOWER ${CONFIGURATION} CONFIG_LOWER)
        string(TOUPPER ${CONFIGURATION} CONFIG_UPPER)

        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${CONFIG_UPPER} "${BASE_OUTPUT_DIR}/${CONFIG_LOWER}")
    endforeach()
endif()

add_library(SkeetSDK SHARED
        dllmain.cpp)
