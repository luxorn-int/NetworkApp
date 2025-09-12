cmake_minimum_required(VERSION 3.30)

Project(TCP_Client_Server)

SET(SrcDir "${CMAKE_CURRENT_SOURCE_DIR}/Src")
SET(IncludeDir "${CMAKE_CURRENT_SOURCE_DIR}/Include")

message("SrcDir - ${SrcDir}")
message("IncludeDir - ${IncludeDir}")

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)

SET(Target_list
        Client
        Server
        # Ptp
        )

# Set Boost cmake file directory
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(includeBoost)

foreach(Target ${Target_list})

    add_executable(${Target} ${SrcDir}/${Target}.cpp)

    target_include_directories(${Target} PRIVATE ${Boost_INCLUDE_DIRS} ${IncludeDir})

    target_link_libraries(${Target} Boost::system )

endforeach()
