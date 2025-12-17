cmake_minimum_required(VERSION 3.18.4)

SET(PATTERNS_LIST
        Singleton
        )

color_message(BLUE "------------ CONFIGURE PATTERNS ------------")

# Перебор библиотек
foreach(Pattern ${PATTERNS_LIST})

    add_library(${Pattern} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/${Pattern})

    target_include_directories(${Pattern} INTERFACE
            ${CMAKE_CURRENT_SOURCE_DIR}/${Pattern}
            )
    color_message(BLUE "Pattern: ${Pattern}")

endforeach(Pattern)
