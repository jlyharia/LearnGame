# Find module
macro(include_module name)
    find_package(${name} REQUIRED)
    if (NOT ${name}_FOUND)
        message(FATAL_ERROR "Package ${name} not found")
    endif (NOT ${name}_FOUND)

    # -D
    add_definitions(${${name}_DEFINITIONS})
    include_directories(${${name}_INCLUDE_DIRS})
    set(LIBRARIES ${LIBRARIES} ${${name}_LIBRARIES})
endmacro()

macro(include_OpenGL)
    IF (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

        find_package(OpenGL REQUIRED)
        if (NOT OpenGL_FOUND)
            message(FATAL_ERROR "Package OpenGL not found")
        endif (NOT OpenGL_FOUND)

        # OpenGL need to use upper case here
        # -D
        add_definitions(${OPENGL_DEFINITIONS})
        include_directories(${OPENGL_INCLUDE_DIRS})
        set(LIBRARIES ${LIBRARIES} ${OPENGL_LIBRARIES})
    else (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
        find_package(OpenGL REQUIRED)
        if (${OPENGL_FOUND})
            add_definitions(${OPENGL_DEFINITIONS})
            include_directories(${OPENGL_INCLUDE_DIR})
            set(LIBRARIES ${LIBRARIES} ${OPENGL_LIBRARIES})
            # set(LIBRARIES ${LIBRARIES} GL GLU X11)
        endif ()
    endif ()
endmacro()

macro(include_Boost)
    find_package(Boost
            COMPONENTS
            filesystem
            log
            log_setup
            REQUIRED)
    if (NOT Boost_FOUND)
        message(FATAL_ERROR "Package Boost not found")
    endif (NOT Boost_FOUND)

    # -D
    add_definitions(${Boost_DEFINITIONS})

    include_directories(${Boost_INCLUDE_DIRS})
    set(LIBRARIES ${LIBRARIES} ${Boost_LIBRARIES})
    # message("**" ${Boost_INCLUDE_DIRS})
    # message("**" ${Boost_LIBRARIES})
endmacro()