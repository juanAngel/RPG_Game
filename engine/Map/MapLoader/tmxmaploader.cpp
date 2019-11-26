#include "tmxmaploader.h"

#include <Graphic/textureloader.h>
#include <Map/map.h>

TMXMapLoader::TMXMapLoader()
{

}

std::shared_ptr<Map> TMXMapLoader::loadMap(const std::string &path, std::shared_ptr<TextureLoader> tl){
    //unsigned tile_width,tile_height;
    tmx::Map tiled_map;
    tiled_map.load(path);

    // We need to know the size of the map (in tiles)
    Size2d layerSize(tiled_map.getTileCount().x,tiled_map.getTileCount().y);

    // We also need to know the dimensions of the tiles.
    Size2d tileSize(tiled_map.getTileSize().x,tiled_map.getTileSize().y);
    //auto tilesize = tiled_map.getTileSize();

    // Load all of the tilesets and store them in a data structure.
    // I chose to store them in a map.
    const std::vector<tmx::Tileset>& map_tilesets = tiled_map.getTilesets();
    std::shared_ptr<Tileset> tileset = loadTileset(map_tilesets,tl);


    auto& map_layers = tiled_map.getLayers();
    std::vector<std::shared_ptr<Layer> > layers;
    for (auto& layer : map_layers){
        switch (layer->getType()) {
            case tmx::Layer::Type::Tile:
                layers.push_back(loadTileLayer(layer->getLayerAs<tmx::TileLayer>(),tileset,tileSize,layerSize));
                break;
            case tmx::Layer::Type::Object:
                break;
            default:;
        }
    }
    std::shared_ptr<Map> map = std::shared_ptr<Map>(new Map(layers,tileset));

    return map;
}

std::unique_ptr<Tileset> TMXMapLoader::loadTileset(const std::vector<tmx::Tileset> &tilesets, std::shared_ptr<TextureLoader> tl){
    std::unique_ptr<Tileset> tileset(new Tileset());
    for (auto& ts : tilesets) {
        unsigned firstGID = ts.getFirstGID();
        auto texture = tl->load(ts.getImagePath());

        const std::vector<tmx::Tileset::Tile>& tiles = ts.getTiles();

        for (auto& it : tiles) {
            Rect rTex(static_cast<int>(it.imagePosition.x),static_cast<int>(it.imagePosition.y),
                      ts.getTileSize().x,ts.getTileSize().y);
            std::shared_ptr<Tile> tile = std::shared_ptr<Tile>(new Tile(firstGID++,rTex,texture));
            if(!it.animation.frames.empty()){
                //TODO: Agregar animaciones a los tiles
            }
            if(!it.terrainIndices.empty()){
                //TODO: Agregar terrenos a los tiles
            }
            tileset->addTile(tile,tile->gid());
        }
    }
    return tileset;
}

std::unique_ptr<TileLayer> TMXMapLoader::loadTileLayer(const tmx::TileLayer& layer, std::shared_ptr<Tileset>& tileset, const Size2d& tileSize, const Size2d& layerSize){

    auto propiedades = layer.getProperties();

    std::vector<tileCell> tiles(layerSize.w()*layerSize.h());
    unsigned i = 0;
    for (const tmx::TileLayer::Tile& it : layer.getTiles()) {
        tiles[i].gid = it.ID;

        i++;
    }
    std::unique_ptr<TileLayer> tileLayer(new TileLayer(tiles,tileset,tileSize,layerSize));


    return tileLayer;
}
