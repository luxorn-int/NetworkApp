SET(INTERFACE_LIST
        INetworkApp
        IProtocol
        ISession
        )

foreach(interface_obj ${INTERFACE_LIST})
    add_library(${interface_obj} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/${interface_obj}.hpp)

    target_include_directories(${interface_obj} PUBLIC INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

    color_message(BLUE "Interface: ${interface_obj}\nDependencies:")
    color_message(YELLOW "\t${LIB_DEPENDS} / Contrib: ${CONTRIB_LIB_DEPENDS}\n")
endforeach()
