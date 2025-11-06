SET(APP_LIST
        Client
        Server)

foreach(APP ${APP_LIST})
    add_subdirectory(${APP})
endforeach()
