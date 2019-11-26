#ifndef MAPMANAGER_H
#define MAPMANAGER_H


#include <iostream>
#include <algorithm>
#include <memory>

#include <Map/layer.h>
#include <Map/map.h>

#include <map>

class TextureLoader;

class MapManager{
        std::map<std::string,std::shared_ptr<Map>> mLoatedMaps;
    public:
        MapManager();
        std::shared_ptr<Map> load(const std::string &path,std::shared_ptr<TextureLoader> tl);
};

#endif // MAPMANAGER_H
