#ifndef MAPLOADER_H
#define MAPLOADER_H

#include <memory>


class TextureLoader;
class Map;

class MapLoader{
    public:
        MapLoader();
        virtual ~MapLoader();
        virtual std::shared_ptr<Map> loadMap(const std::string &path,std::shared_ptr<TextureLoader> tl) = 0;
};

#endif // MAPLOADER_H
