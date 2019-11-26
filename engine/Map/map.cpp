#include "map.h"


#include <tmxlite/Map.hpp>
#include <tmxlite/Layer.hpp>
#include <tmxlite/TileLayer.hpp>
#include <iostream>
#include <algorithm>
#include <memory>
#include <map>

#include <Graphic/textureloader.h>


typedef int gid;

Map::Map(std::vector<std::shared_ptr<Layer> > layers, std::shared_ptr<Tileset> tileset):mTileset(tileset),mLayers(layers){

}

Map::~Map(){

}

void Map::draw(Renderer &ren, const Camera &camera){
    for (auto& layer : mLayers) {
        layer->draw(ren,camera);
    }
}
