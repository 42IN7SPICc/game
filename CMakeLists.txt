cmake_minimum_required(VERSION 3.16)
project(spic-game)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
set(PROJECT_LIBS_DIR ${PROJECT_SOURCE_DIR}/libs)

find_package(RapidJSON CONFIG REQUIRED)

include_directories(${PROJECT_LIBS_DIR}/spic-api/include)
link_directories(${PROJECT_LIBS_DIR}/spic-api/lib)

add_custom_target(
        copy_assets
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/resources ${CMAKE_CURRENT_BINARY_DIR}/resources
)

file(GLOB_RECURSE SOURCE src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCE})
add_dependencies(${PROJECT_NAME} copy_assets)
target_link_libraries(${PROJECT_NAME} PRIVATE spic-engine rapidjson)
