cmake_minimum_required(VERSION 3.10.0)
project(BulletHell C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON) 

set(RAYLIB_DIR "C:/dev/raylib-5.5")

include_directories(${RAYLIB_DIR}/include)

link_directories(${RAYLIB_DIR}/lib)

# Get all your source files
file(GLOB_RECURSE SOURCES "src/*.c" "src/*.cpp")

add_executable(BulletHell ${SOURCES})

# Link Raylib + required Windows system libs
target_link_libraries(BulletHell raylib winmm gdi32 opengl32)