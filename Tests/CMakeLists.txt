include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.0
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

file(GLOB TEST_SOURCES 
    "*.cpp"
    "unit/*.cpp" 
    "integration/*.cpp"
    "mocks/src/*.cpp"
)

add_executable(network_tests
    ${TEST_SOURCES}
)

target_link_libraries(network_tests
    gtest_main
    gmock_main
    BaseServer
    # BaseClient
)

target_include_directories(network_tests PRIVATE
    ${PROJECT_SOURCE_DIR}/Include
    ${Boost_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/mocks/include
    ${CMAKE_CURRENT_SOURCE_DIR}
)

include(GoogleTest)

gtest_discover_tests(network_tests)