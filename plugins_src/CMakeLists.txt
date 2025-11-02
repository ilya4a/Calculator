file(MAKE_DIRECTORY "${PLUGINS_OUTPUT_DIR}")

add_library(funsin SHARED funsin.cpp)
add_library(funcos SHARED funcos.cpp)

if(WIN32)
    set_target_properties(funsin funcos PROPERTIES
            WINDOWS_EXPORT_ALL_SYMBOLS ON
            SUFFIX ".dll"
            RUNTIME_OUTPUT_DIRECTORY "${PLUGINS_OUTPUT_DIR}"
            # LIBRARY_OUTPUT_DIRECTORY "${PLUGINS_OUTPUT_DIR}"
            # ARCHIVE_OUTPUT_DIRECTORY "${PLUGINS_OUTPUT_DIR}"
            # PDB_OUTPUT_DIRECTORY "${PLUGINS_OUTPUT_DIR}"
    )

    foreach(CONFIG ${CMAKE_CONFIGURATION_TYPES})
        string(TOUPPER ${CONFIG} CONFIG)
        set_target_properties(funsin funcos PROPERTIES
                RUNTIME_OUTPUT_DIRECTORY_${CONFIG} "${PLUGINS_OUTPUT_DIR}"
                # LIBRARY_OUTPUT_DIRECTORY_${CONFIG} "${PLUGINS_OUTPUT_DIR}"
                # ARCHIVE_OUTPUT_DIRECTORY_${CONFIG} "${PLUGINS_OUTPUT_DIR}"
                # PDB_OUTPUT_DIRECTORY_${CONFIG} "${PLUGINS_OUTPUT_DIR}"
        )
    endforeach()
else()
    set_target_properties(funsin funcos PROPERTIES
            PREFIX ""
            SUFFIX ".so"
            LIBRARY_OUTPUT_DIRECTORY "${PLUGINS_OUTPUT_DIR}"
    )
endif()

target_include_directories(funsin PRIVATE ${CMAKE_SOURCE_DIR})
target_include_directories(funcos PRIVATE ${CMAKE_SOURCE_DIR})