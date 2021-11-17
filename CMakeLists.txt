cmake_minimum_required(VERSION 3.16)
project(spic-game)

set(CMAKE_CXX_STANDARD 20)

set(PROJECT_LIBS_DIR ${PROJECT_SOURCE_DIR}/libs)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

find_package(RapidJSON CONFIG REQUIRED)

#include_directories(${PROJECT_LIBS_DIR}/spic-api/include)
include_directories(${PROJECT_NAME} ${PROJECT_LIBS_DIR}/spic-engine/includes/spic-api-headers)

if (NOT DEFINED BINARY_RESOURCES_FOLDER)
    set(BINARY_RESOURCES_FOLDER resources)
endif ()

add_custom_target(copy_assets COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/resources ${CMAKE_CURRENT_BINARY_DIR}/${BINARY_RESOURCES_FOLDER})

add_subdirectory(${PROJECT_LIBS_DIR}/spic-engine)

file(GLOB_RECURSE SOURCE src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCE} src/Utils/TileUtil.cpp src/Utils/TileUtil.hpp)
add_dependencies(${PROJECT_NAME} copy_assets)
target_link_libraries(${PROJECT_NAME} PRIVATE spic-engine rapidjson)
