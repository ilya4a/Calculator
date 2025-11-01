file(MAKE_DIRECTORY "${PLUGINS_OUTPUT_DIR}")

add_library(funsin SHARED funsin.cpp)
add_library(funcos SHARED funcos.cpp)

if(WIN32)
    set_target_properties(funsin funcos PROPERTIES
            WINDOWS_EXPORT_ALL_SYMBOLS ON
    )
endif()

if(UNIX AND NOT APPLE)
    set_target_properties(funsin funcos PROPERTIES
            PREFIX ""
            SUFFIX ".so"
    )
endif()