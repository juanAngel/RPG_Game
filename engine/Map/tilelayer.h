#ifndef TILELAYER_H
#define TILELAYER_H

#include <Map/layer.h>
#include <Map/tile.h>
#include <Map/tileset.h>

#include <vector>

typedef struct tileCell{
    unsigned gid;
    std::shared_ptr<Tile> tile;
}tileCell;
class TileLayer:public Layer{
        Size2d mTileSize,mLayerSize;
        std::vector<tileCell> mTiles;
        std::shared_ptr<Tileset> mTileset;
    public:
        TileLayer(const std::vector<tileCell>& tiles, std::shared_ptr<Tileset> &tileset, Size2d tileSize, Size2d layerSize);
        virtual ~TileLayer();
        Rect toTileCoordinate(Rect r);

        // Drawable interface
        virtual void draw(Renderer& ren,const Camera& camera);
};

#endif // MAPLAYER_H
