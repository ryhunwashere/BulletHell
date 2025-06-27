cmake_minimum_required(VERSION 3.10)
project(BulletHell C CXX)

# Language standards
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Raylib paths
set(RAYLIB_DIR "C:/dev/raylib-5.5")
set(RAYLIB_INCLUDE_DIR "${RAYLIB_DIR}/include")
set(RAYLIB_LIB_DIR "${RAYLIB_DIR}/lib")

# Gather source files
file(GLOB_RECURSE SOURCES
    "${CMAKE_SOURCE_DIR}/src/*.c"
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
)

# Create executable
add_executable(BulletHell ${SOURCES})

# Include headers
target_include_directories(BulletHell PRIVATE
    "${RAYLIB_INCLUDE_DIR}"
    "${CMAKE_SOURCE_DIR}/include"
)

# Link Raylib and Windows libraries
target_link_directories(BulletHell PRIVATE "${RAYLIB_LIB_DIR}")
target_link_libraries(BulletHell
    raylib
    winmm
    gdi32
    opengl32
)
