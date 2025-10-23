cmake_minimum_required(VERSION 3.30)

Project(NetworkApp)

SET(SrcDir "${CMAKE_CURRENT_SOURCE_DIR}/Src")

SET(IncludeDir "${CMAKE_CURRENT_SOURCE_DIR}/Include"
               "${CMAKE_CURRENT_SOURCE_DIR}/Include/interface"
               "${CMAKE_CURRENT_SOURCE_DIR}/Include/base"
               "${CMAKE_CURRENT_SOURCE_DIR}/Include/Server")

message("SrcDir - ${SrcDir}")
message("IncludeDir - ${IncludeDir}")

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)

add_compile_definitions(_WIN32_WINNT=0x0A00)
add_compile_definitions(BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS)

SET(LIB_Target_list
        BaseServer
        )

SET(APP_Target_list
        chatServer
        # ftpServer
        # Client
        )

# Set Boost cmake file directory
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(includeBoost)

enable_testing()

foreach(Target ${APP_Target_list})

    add_executable(${Target} ${SrcDir}/APP/${Target}.cpp)

    target_include_directories(${Target} PRIVATE ${Boost_INCLUDE_DIRS} ${IncludeDir})

    target_link_libraries(${Target} Boost::system )

endforeach()

foreach(Target ${LIB_Target_list})

    add_library(${Target} ${SrcDir}/LIB/${Target}.cpp)

    target_include_directories(${Target} PRIVATE ${Boost_INCLUDE_DIRS} ${IncludeDir})

    target_link_libraries(${Target} Boost::system )

endforeach()

add_subdirectory(Tests)
