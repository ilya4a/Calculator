file(MAKE_DIRECTORY "${PLUGINS_OUTPUT_DIR}")

add_library(funsin SHARED funsin.cpp)
add_library(funcos SHARED funcos.cpp)

if(WIN32)
    set_target_properties(funsin funcos PROPERTIES
            WINDOWS_EXPORT_ALL_SYMBOLS ON
            SUFFIX ".dll"
    )
    target_compile_definitions(funsin PRIVATE PLUGIN_EXPORT=__declspec(dllexport))
    target_compile_definitions(funcos PRIVATE PLUGIN_EXPORT=__declspec(dllexport))
else()
    set_target_properties(funsin funcos PROPERTIES
            PREFIX ""
            SUFFIX ".so"
    )
    target_compile_definitions(funsin PRIVATE PLUGIN_EXPORT=)
    target_compile_definitions(funcos PRIVATE PLUGIN_EXPORT=)
endif()

target_include_directories(funsin PRIVATE ${CMAKE_SOURCE_DIR})
target_include_directories(funcos PRIVATE ${CMAKE_SOURCE_DIR})