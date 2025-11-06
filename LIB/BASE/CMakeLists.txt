SET(BASE_LIST
        Session
        Server
        Client
        )

foreach (BASE ${BASE_LIST})
    add_subdirectory(${BASE})
endforeach ()