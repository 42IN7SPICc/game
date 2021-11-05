cmake_minimum_required(VERSION 3.16)
project(spic-game)

set(CMAKE_CXX_STANDARD 20)

set(PROJECT_LIBS_DIR ${PROJECT_SOURCE_DIR}/libs)

find_package(RapidJSON CONFIG REQUIRED)

include_directories(${PROJECT_LIBS_DIR}/spic-api/include)
link_directories(${PROJECT_LIBS_DIR}/spic-api/lib)

file(GLOB_RECURSE SOURCE src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCE})
target_link_libraries(${PROJECT_NAME} PRIVATE spic-engine rapidjson)
