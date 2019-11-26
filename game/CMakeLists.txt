cmake_minimum_required(VERSION 2.8)

project(RPG_game)
set(CMAKE_CXX_STANDARD 11)

set(game_src main.cpp level.cpp level.h)


add_executable(${PROJECT_NAME} ${game_src})

target_link_libraries(${PROJECT_NAME} RPG_engine)
