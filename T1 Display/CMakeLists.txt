cmake_minimum_required(VERSION 3.20)
project(LearnGame)

set(CMAKE_CXX_STANDARD 20)
SET(MAIN_TARGET ${PROJECT_NAME})
include(${PROJECT_SOURCE_DIR}/cmake/macro.cmake)
include(${PROJECT_SOURCE_DIR}/cmake/LibFindMacros.cmake)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake/modules)
set(CMAKE_DEFAULT_MODULE_LIST /usr/local/share/cmake/Modules)
# Enable debug symbols by default
if (CMAKE_BUILD_TYPE STREQUAL "")
    set(CMAKE_BUILD_TYPE Debug)
endif ()

# include library
include_OpenGL()
include_module(GLEW)
include_module(GLM)
include_module(GLFW)
include_module(ASSIMP)

message("CMAKE_SOURCE_DIR:" ${CMAKE_SOURCE_DIR})
set(HEADER_FILES
        ${HEADER_FILES}
        ${CMAKE_SOURCE_DIR}/glad/glad.h
        ${CMAKE_SOURCE_DIR}/glad/khrplatform.h
        ${CMAKE_SOURCE_DIR}/Shader.hpp
        ${CMAKE_SOURCE_DIR}/stb_image.h
        ${CMAKE_SOURCE_DIR}/Camera.hpp
        ${CMAKE_SOURCE_DIR}/Model.hpp
        ${CMAKE_SOURCE_DIR}/Mesh.hpp
        )
set(SOURCE_FILES
        ${SOURCE_FILES}
        ${CMAKE_SOURCE_DIR}/glad/glad.c
        src/DisplayManager.cpp src/DisplayManager.hpp)

set(CMAKE_VERBOSE_MAKEFILE on)  # make debug flag
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")

message("-- HEADER_FILES: " ${HEADER_FILES})
message("-- SOURCE_FILES: " ${SOURCE_FILES})
message("-- Libraries: " ${LIBRARIES})
message("-- CMAKE_SOURCE_DIR " ${CMAKE_SOURCE_DIR})
message("-- CMAKE_COMMAND " ${CMAKE_COMMAND})

add_executable(LearnGame main.cpp ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})

add_custom_command(TARGET ${MAIN_TARGET}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources $<TARGET_FILE_DIR:${MAIN_TARGET}>/resources)
