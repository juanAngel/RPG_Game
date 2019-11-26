cmake_minimum_required(VERSION 2.8)

project(RPG)
set(CMAKE_CXX_STANDARD 11)


set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

find_package(TMXLITE REQUIRED)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

add_subdirectory(engine)
add_subdirectory(game)
