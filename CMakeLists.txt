cmake_minimum_required(VERSION 3.10)

project(Astros_Game_Engine VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCES "src/*.cpp")

set(GLAD_SOURCES "${CMAKE_SOURCE_DIR}/src/glad.c")

add_executable(Astros_Game_Engine ${SOURCES} ${GLAD_SOURCES})

if(UNIX)
    find_package(glfw3 REQUIRED)
    include_directories(/usr/include/glm)
    target_link_libraries(Astros_Game_Engine PRIVATE glfw)
else()
    target_link_libraries(Astros_Game_Engine PRIVATE
        ${CMAKE_SOURCE_DIR}/lib/glfw3.lib
    )
endif()
