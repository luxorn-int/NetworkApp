project(Protocols)

SET(PROTOCOLS_LIST
        TCP
        UDP)

foreach (PROTOCOL ${PROTOCOLS_LIST})
    add_subdirectory(${PROTOCOL})
endforeach ()