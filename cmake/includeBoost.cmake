if(POLICY CMP0167)
    cmake_policy(SET CMP0167 NEW)
endif()

set(Boost_DEBUG OFF)

# SET YOUR BOOST DIR
if(WIN32)
    set(BOOST_ROOT "D:/dev/Frameworks/boost_1_88_0")
    set(Boost_DIR "${BOOST_ROOT}/stage/lib/cmake/Boost-1.88.0")
endif ()

find_package(Boost REQUIRED COMPONENTS filesystem)

if(Boost_FOUND)
    message(STATUS "Boost found: ${Boost_VERSION}")
    message(STATUS "Boost include dir: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost libraries: ${Boost_LIBRARIES}")
else()
    message(FATAL_ERROR "Boost not found")
endif()