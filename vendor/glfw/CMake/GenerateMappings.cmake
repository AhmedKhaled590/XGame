<<<<<<< HEAD
# Usage:
# cmake -P GenerateMappings.cmake <path/to/mappings.h.in> <path/to/mappings.h>

set(source_url "https://raw.githubusercontent.com/gabomdq/SDL_GameControllerDB/master/gamecontrollerdb.txt")
set(source_path "${CMAKE_CURRENT_BINARY_DIR}/gamecontrollerdb.txt")
set(template_path "${CMAKE_ARGV3}")
set(target_path "${CMAKE_ARGV4}")

if (NOT EXISTS "${template_path}")
    message(FATAL_ERROR "Failed to find template file ${template_path}")
endif()

file(DOWNLOAD "${source_url}" "${source_path}"
     STATUS download_status
     TLS_VERIFY on)

list(GET download_status 0 status_code)
list(GET download_status 1 status_message)

if (status_code)
    message(FATAL_ERROR "Failed to download ${source_url}: ${status_message}")
endif()

file(STRINGS "${source_path}" lines)
foreach(line ${lines})
    if ("${line}" MATCHES "^[0-9a-fA-F].*$")
        set(GLFW_GAMEPAD_MAPPINGS "${GLFW_GAMEPAD_MAPPINGS}\"${line}\",\n")
    endif()
endforeach()

configure_file("${template_path}" "${target_path}" @ONLY NEWLINE_STYLE UNIX)
file(REMOVE "${source_path}")

=======
# Usage:
# cmake -P GenerateMappings.cmake <path/to/mappings.h.in> <path/to/mappings.h>

set(source_url "https://raw.githubusercontent.com/gabomdq/SDL_GameControllerDB/master/gamecontrollerdb.txt")
set(source_path "${CMAKE_CURRENT_BINARY_DIR}/gamecontrollerdb.txt")
set(template_path "${CMAKE_ARGV3}")
set(target_path "${CMAKE_ARGV4}")

if (NOT EXISTS "${template_path}")
    message(FATAL_ERROR "Failed to find template file ${template_path}")
endif()

file(DOWNLOAD "${source_url}" "${source_path}"
     STATUS download_status
     TLS_VERIFY on)

list(GET download_status 0 status_code)
list(GET download_status 1 status_message)

if (status_code)
    message(FATAL_ERROR "Failed to download ${source_url}: ${status_message}")
endif()

file(STRINGS "${source_path}" lines)
foreach(line ${lines})
    if ("${line}" MATCHES "^[0-9a-fA-F].*$")
        set(GLFW_GAMEPAD_MAPPINGS "${GLFW_GAMEPAD_MAPPINGS}\"${line}\",\n")
    endif()
endforeach()

configure_file("${template_path}" "${target_path}" @ONLY NEWLINE_STYLE UNIX)
file(REMOVE "${source_path}")

>>>>>>> 31c2538aad6a7e0f97036ec08c7eedea29b76aaa
