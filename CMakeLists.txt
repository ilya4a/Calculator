cmake_minimum_required(VERSION 3.31)
project(Calculator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (WIN32)
    add_definitions(-D_WIN32)
endif()

set(PLUGINS_OUTPUT_DIR "${CMAKE_BINARY_DIR}/plugins")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PLUGINS_OUTPUT_DIR}")

add_executable(Calculator
        src/main.cpp
        src/lexer/Lexer.cpp
        src/lexer/Token.cpp
        src/parser/Parser.cpp
        src/expr/NumberExpression.cpp
        src/expr/UnaryExpression.cpp
        src/expr/BinaryExpression.cpp
        src/expr/FunctionExpression.cpp
        src/plugin/PluginManager.cpp
        src/tests/tests.cpp
)

target_include_directories(Calculator PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/src
)

if (UNIX)
    find_library(DL_LIBRARY dl)
    target_link_libraries(Calculator ${DL_LIBRARY})
endif()

file(MAKE_DIRECTORY "${PLUGINS_OUTPUT_DIR}")

set(PLUGIN_SRC_DIR ${CMAKE_SOURCE_DIR}/plugins/src)

# Создаём библиотеки
add_library(funsin SHARED ${PLUGIN_SRC_DIR}/funsin.cpp)
add_library(funcos SHARED ${PLUGIN_SRC_DIR}/funcos.cpp)
add_library(funpow SHARED ${PLUGIN_SRC_DIR}/funpow.cpp)
add_library(funln  SHARED ${PLUGIN_SRC_DIR}/funln.cpp)
add_library(fundeg SHARED ${PLUGIN_SRC_DIR}/fundeg.cpp)

target_include_directories(funsin PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(funcos PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(funpow PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(funln  PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(fundeg PRIVATE ${CMAKE_SOURCE_DIR}/include)

if (WIN32)
    set_target_properties(funsin funcos funpow funln fundeg PROPERTIES
            WINDOWS_EXPORT_ALL_SYMBOLS ON
            SUFFIX ".dll"
            RUNTIME_OUTPUT_DIRECTORY "${PLUGINS_OUTPUT_DIR}"
    )
else()
    set_target_properties(funsin funcos funpow funln fundeg PROPERTIES
            PREFIX ""
            SUFFIX ".so"
            LIBRARY_OUTPUT_DIRECTORY "${PLUGINS_OUTPUT_DIR}"
    )
endif()

add_dependencies(Calculator funsin funcos funpow funln fundeg)

if(WIN32)
    add_custom_command(TARGET Calculator POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E make_directory
            "$<TARGET_FILE_DIR:Calculator>/plugins"
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "$<TARGET_FILE:funsin>"
            "$<TARGET_FILE:funcos>"
            "$<TARGET_FILE:funpow>"
            "$<TARGET_FILE:funln>"
            "$<TARGET_FILE:fundeg>"
            "$<TARGET_FILE_DIR:Calculator>/plugins/"
    )
endif()
