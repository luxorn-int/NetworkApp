SET(LIB_LIST
        INTERFACE
        ConnectionAcceptor
        SessionManager
        BASE
	Patterns
        )

foreach(LIB ${LIB_LIST})
    add_subdirectory(${LIB})
endforeach()
