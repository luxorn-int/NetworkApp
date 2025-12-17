SET(BASE_LIST
        Protocols
        Session
        Server
        Client
        )

foreach (BASE ${BASE_LIST})
    add_subdirectory(${BASE})
endforeach ()