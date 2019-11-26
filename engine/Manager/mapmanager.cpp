#include "mapmanager.h"

#include <tmxlite/Map.hpp>
#include <tmxlite/Layer.hpp>
#include <tmxlite/TileLayer.hpp>

#include <map>

#include <Graphic/textureloader.h>
#include <Map/MapLoader/tmxmaploader.h>


typedef int gid;

MapManager::MapManager()
{

}

std::shared_ptr<Map> MapManager::load(const std::string &path, std::shared_ptr<TextureLoader> tl){
    TMXMapLoader loader;

    auto it = mLoatedMaps.find(path);
    if(it != mLoatedMaps.end()){
        return (*it).second;
    }else{
        mLoatedMaps;
    }

    return loader.loadMap(path,tl);
}
