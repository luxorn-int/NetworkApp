SET(SrcDir "${CMAKE_CURRENT_SOURCE_DIR}/Src")
SET(IncludeDir "${CMAKE_CURRENT_SOURCE_DIR}/Include")

file(GLOB SrcFiles "${SrcDir}/*.cpp")

add_library(${PROJECT_NAME} ${SrcFiles})

target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${IncludeDir}
        ${ADDITIONAL_INCLUDE_DIR}
        )

target_link_libraries(${PROJECT_NAME} PUBLIC ${CONTRIB_LIB_DEPENDS} ${DEPENDS_LIST})

color_message(GREEN "Library: ${PROJECT_NAME}\nDependencies:")
color_message(YELLOW "\t${DEPENDS_LIST} / Contrib: ${CONTRIB_LIB_DEPENDS}\n")
