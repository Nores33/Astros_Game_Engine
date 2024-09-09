cmake_minimum_required(VERSION 3.17)
project(Astros_Game_Engine VERSION 1.0 LANGUAGES CXX C)

# Variables
set(VENDOR_DIR "${CMAKE_SOURCE_DIR}/vendor")
set(SHADER_DIR "${CMAKE_SOURCE_DIR}/shaders")
set(MODELS_DIR "${CMAKE_SOURCE_DIR}/models")
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

# OpenGL Flags
set(OpenGL_GL_PREFERENCE GLVND)

# GLFW and GLM - Installed via vcpkg
set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "C:/vcpkg/installed/x64-windows")
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

# Glad
add_library(glad STATIC ${VENDOR_DIR}/glad/src/glad.c)
target_include_directories(glad PRIVATE ${VENDOR_DIR}/glad/include)

# Project
file(GLOB_RECURSE SOURCES "${SRC_DIR}/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
  PRIVATE
    ${VENDOR_DIR}/glad/include
    ${VENDOR_DIR}/tinyGLTF
    ${INCLUDE_DIR}
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    glfw
    glad
    glm
    ${CMAKE_DL_LIBS} # Needed for glad
)

set_target_properties(${PROJECT_NAME}
  PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${SHADER_DIR} $<TARGET_FILE_DIR:${PROJECT_NAME}>/shaders)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${MODELS_DIR} $<TARGET_FILE_DIR:${PROJECT_NAME}>/models)