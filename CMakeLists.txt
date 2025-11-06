cmake_minimum_required(VERSION 3.25)

Project(NetworkApp)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(cmake_colors)

add_compile_definitions(_WIN32_WINNT=0x0A00)
#add_compile_definitions(BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS)

color_message(BLUE "Download Gtest repo")

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.15.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(includeBoost)

enable_testing()

SET(PROJECT_DIR
        LIB
        Tests
        APP
        )

foreach(P_DIR ${PROJECT_DIR})
    add_subdirectory(${P_DIR})
endforeach()

