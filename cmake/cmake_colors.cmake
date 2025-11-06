string(ASCII 27 Esc)

set(RESET "${Esc}[0m")
set(RED "${Esc}[1;31m")
set(GREEN "${Esc}[1;32m")
set(YELLOW "${Esc}[1;33m")
set(BLUE "${Esc}[1;34m")
set(MAGENTA "${Esc}[1;35m")
set(CYAN "${Esc}[1;36m")
set(WHITE "${Esc}[1;37m")

function(color_message COLOR TEXT)
    message("${${COLOR}}${TEXT}${RESET}")
endfunction()
