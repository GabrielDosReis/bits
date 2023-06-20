cmake_minimum_required(VERSION 3.27)

include(FetchContent)
# Download the boilerplate for the experimental support for C++ Modules
FetchContent_Declare(
    cmake-for-modules
    GIT_REPOSITORY https://github.com/GabrielDosReis/cmake-for-modules
    GIT_TAG main
)

FetchContent_MakeAvailable(cmake-for-modules)

project(bits CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Default to Release build type
if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE "Release")
endif()

list(PREPEND CMAKE_MODULE_PATH "${cmake-for-modules_SOURCE_DIR}")
include(CXXModuleExperimentalSupport)

add_library(gdr-bits)
target_sources(gdr-bits
    PUBLIC 
        FILE_SET CXX_MODULES
        FILES
            src/bits.ixx
)

target_link_libraries(gdr-bits cxx-std-modules)