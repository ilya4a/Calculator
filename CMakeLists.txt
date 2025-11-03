cmake_minimum_required(VERSION 3.31)
project(Calculator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(WIN32)
    add_definitions(-D_WIN32)
    set(PLUGIN_EXT "dll")
else()
    set(PLUGIN_EXT "so")
endif()

set(PLUGINS_OUTPUT_DIR "${CMAKE_SOURCE_DIR}/plugins")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PLUGINS_OUTPUT_DIR}")

foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} "${CMAKE_SOURCE_DIR}")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} "${PLUGINS_OUTPUT_DIR}")
endforeach()

add_executable(Calculator
        main.cpp
        src/Lexer.cpp
        src/Lexer.h
        src/TokenType.h
        src/Token.cpp
        src/Token.h
        src/Parser.cpp
        src/Parser.h
        src/expr/Expression.h
        src/expr/NumberExpression.cpp
        src/expr/NumberExpression.h
        src/expr/UnaryExpression.cpp
        src/expr/UnaryExpression.h
        src/expr/BinaryExpression.cpp
        src/expr/BinaryExpression.h
        src/simple_calculator_tests.cpp
        src/simple_calculator_tests.h
        src/PluginManager.cpp
        src/PluginManager.h
        plugin_interface.h
        src/expr/FunctionExpression.cpp
        src/expr/FunctionExpression.h
)

if(UNIX)
    find_library(DL_LIBRARY dl)
    target_link_libraries(Calculator ${DL_LIBRARY})
endif()

add_subdirectory(plugins_src)
add_dependencies(Calculator funsin funcos funpow funln)