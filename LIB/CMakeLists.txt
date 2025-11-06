SET(LIB_LIST
        INTERFACE
        SessionManager
        BASE
        )

foreach(LIB ${LIB_LIST})
    add_subdirectory(${LIB})
endforeach()
