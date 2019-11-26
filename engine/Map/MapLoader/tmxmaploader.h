#ifndef TMXMAPLOADER_H
#define TMXMAPLOADER_H

#include "maploader.h"

#include <Map/tilelayer.h>
#include <Map/tileset.h>



#include <tmxlite/Map.hpp>
#include <tmxlite/TileLayer.hpp>
#include <tmxlite/Tileset.hpp>
#include <tmxlite/Object.hpp>
#include <tmxlite/Property.hpp>

class TMXMapLoader:public MapLoader{
    public:
        TMXMapLoader();

        // MapLoader interface
        std::shared_ptr<Map> loadMap(const std::string &path, std::shared_ptr<TextureLoader> tl);
        std::unique_ptr<Tileset> loadTileset(const std::vector<tmx::Tileset> &tilesets, std::shared_ptr<TextureLoader> tl);
        std::unique_ptr<TileLayer> loadTileLayer(const tmx::TileLayer &layer, std::shared_ptr<Tileset> &tileset, const Size2d &tileSize, const Size2d& layerSize);
};

#endif // TMXMAPLOADER_H
