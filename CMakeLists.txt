cmake_minimum_required(VERSION 3.10)

project(Astros_Game_Engine VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake")

set(CMAKE_PREFIX_PATH "C:/vcpkg/installed/x64-windows")

find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCES "src/*.cpp")

set(GLAD_SOURCES "${CMAKE_SOURCE_DIR}/src/glad.c")

add_executable(Astros_Game_Engine ${SOURCES} ${GLAD_SOURCES})

target_link_libraries(Astros_Game_Engine PRIVATE glfw glm)
