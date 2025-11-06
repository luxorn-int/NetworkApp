if(POLICY CMP0167)
    cmake_policy(SET CMP0167 NEW)
endif()

#set(Boost_USE_STATIC_LIBS ON)

set(Boost_ARCHITECTURE "-x64")
set(Boost_COMPILER "-vc143")

set(Boost_DEBUG OFF)

set(BOOST_ROOT "D:/dev/Frameworks/boost_1_88_0")
set(Boost_DIR "${BOOST_ROOT}/stage/lib/cmake/Boost-1.88.0")

find_package(Boost REQUIRED COMPONENTS system)

if(Boost_FOUND)
    message(STATUS "Boost found: ${Boost_VERSION}")
    message(STATUS "Boost include dir: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost libraries: ${Boost_LIBRARIES}")
else()
    message(FATAL_ERROR "Boost not found")
endif()