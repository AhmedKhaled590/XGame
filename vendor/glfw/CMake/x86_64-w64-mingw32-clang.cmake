<<<<<<< HEAD
# Define the environment for cross-compiling with 64-bit MinGW-w64 Clang
SET(CMAKE_SYSTEM_NAME    Windows) # Target system name
SET(CMAKE_SYSTEM_VERSION 1)
SET(CMAKE_C_COMPILER     "x86_64-w64-mingw32-clang")
SET(CMAKE_CXX_COMPILER   "x86_64-w64-mingw32-clang++")
SET(CMAKE_RC_COMPILER    "x86_64-w64-mingw32-windres")
SET(CMAKE_RANLIB         "x86_64-w64-mingw32-ranlib")

# Configure the behaviour of the find commands
SET(CMAKE_FIND_ROOT_PATH "/usr/x86_64-w64-mingw32")
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
=======
# Define the environment for cross-compiling with 64-bit MinGW-w64 Clang
SET(CMAKE_SYSTEM_NAME    Windows) # Target system name
SET(CMAKE_SYSTEM_VERSION 1)
SET(CMAKE_C_COMPILER     "x86_64-w64-mingw32-clang")
SET(CMAKE_CXX_COMPILER   "x86_64-w64-mingw32-clang++")
SET(CMAKE_RC_COMPILER    "x86_64-w64-mingw32-windres")
SET(CMAKE_RANLIB         "x86_64-w64-mingw32-ranlib")

# Configure the behaviour of the find commands
SET(CMAKE_FIND_ROOT_PATH "/usr/x86_64-w64-mingw32")
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
>>>>>>> 31c2538aad6a7e0f97036ec08c7eedea29b76aaa
