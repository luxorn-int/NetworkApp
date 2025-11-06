SET(SrcDir "${CMAKE_CURRENT_SOURCE_DIR}/Src")
SET(IncludeDir "${CMAKE_CURRENT_SOURCE_DIR}/Include")

file(GLOB SrcFiles "${SrcDir}/*.cpp")

add_executable(${PROJECT_NAME} ${SrcFiles})

target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${IncludeDir}
        ${ADDITIONAL_INCLUDE_DIR}
        )

target_link_libraries(${PROJECT_NAME} PUBLIC ${CONTRIB_LIB_DEPENDS} ${DEPENDS_LIST})

color_message(WHITE "APP: ${PROJECT_NAME}\nDependencies:")
color_message(YELLOW "\t${DEPENDS_LIST} / Contrib: ${CONTRIB_LIB_DEPENDS}\n")
