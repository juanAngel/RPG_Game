cmake_minimum_required(VERSION 2.8)

project(RPG)
set(CMAKE_CXX_STANDARD 11)


set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

find_package(TMXLITE REQUIRED)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

set(game_src game/main.cpp game/level.cpp game/level.h)

set(engine_src
    engine/engine.cpp engine/engine.h
    engine/drawable.cpp engine/drawable.h
    engine/maplayer.cpp engine/maplayer.h
    engine/renderer.cpp engine/renderer.h
    engine/camera.cpp engine/camera.h
    engine/texture.cpp engine/texture.h
    engine/textureloader.cpp engine/textureloader.h

    engine/SDL/sdlengine.cpp engine/SDL/sdlengine.h
    engine/SDL/sdlrenderer.cpp engine/SDL/sdlrenderer.h
    engine/SDL/sdlcamera.cpp engine/SDL/sdlcamera.h
    engine/SDL/sdltexture.cpp engine/SDL/sdltexture.h
    engine/SDL/sdltextureloader.cpp engine/SDL/sdltextureloader.h
    )



add_executable(${PROJECT_NAME}_game ${game_src})


add_library(${PROJECT_NAME}_engine ${engine_src})

target_link_libraries(${PROJECT_NAME}_engine
    ${TMXLITE_LIBRARIES}
    ${SDL2_LIBRARY}
    ${SDL2_IMAGE_LIBRARIES}
)

target_include_directories(${PROJECT_NAME}_engine PUBLIC ${CMAKE_CURRENT_LIST_DIR}/engine)

target_link_libraries(${PROJECT_NAME}_game ${PROJECT_NAME}_engine)
