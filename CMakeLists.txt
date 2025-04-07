cmake_minimum_required(VERSION 3.31)

project(gdr-bits-utility CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(GNUInstallDirs)

add_library(gdr-bits-utility)
target_compile_features(gdr-bits-utility PUBLIC cxx_std_23)
target_sources(gdr-bits-utility
    PUBLIC
        FILE_SET CXX_MODULES
            BASE_DIRS src
            FILES src/bits.ixx
)


# Everyone else targets this library as `GDR:BitsUtility`.
add_library(GDR.Bits::Utility ALIAS gdr-bits-utility)

install(TARGETS gdr-bits-utility
    EXPORT GDR.Bits.Utility
    FILE_SET CXX_MODULES
        DESTINATION modules/gdr
)

install(EXPORT GDR.Bits.Utility
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/GDR.Bits.Utility
    NAMESPACE GDR.Bits::
    FILE targets.cmake
    CXX_MODULES_DIRECTORY .
)
