cmake_minimum_required(VERSION 2.8)

project(RPG_engine)
set(CMAKE_CXX_STANDARD 11)

find_package(TMXLITE REQUIRED)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

file(GLOB_RECURSE
        engine_src
        "*.cpp"
        "*.c"
    )
file(GLOB_RECURSE
        engine_header
        "*.h"
    )


add_library(${PROJECT_NAME} ${engine_src} ${engine_header})

target_link_libraries(${PROJECT_NAME}
    ${TMXLITE_LIBRARIES}
    ${SDL2_LIBRARY}
    ${SDL2_IMAGE_LIBRARIES}
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/)
