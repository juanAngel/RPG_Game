#include "tilelayer.h"

TileLayer::TileLayer(const std::vector<tileCell> &tiles, std::shared_ptr<Tileset> &tileset, Size2d tileSize, Size2d layerSize)
            :mTileSize(tileSize)
            ,mLayerSize(layerSize)
            ,mTiles(tiles)
            ,mTileset(tileset){

}

TileLayer::~TileLayer(){

}

Rect TileLayer::toTileCoordinate(Rect r){
    return r;
}

void TileLayer::draw(Renderer &ren, const Camera &camera){
    int i = 0;
    for (auto& it: mTiles) {
        int x = i%static_cast<int>(mLayerSize.w())*static_cast<int>(mTileSize.w());
        int y = i/static_cast<int>(mLayerSize.w())*static_cast<int>(mTileSize.h());
        if(((x+static_cast<int>(mTileSize.w()))>=camera.posX()) && ((y+static_cast<int>(mTileSize.h()))>=camera.posY()) &&
           (x<(camera.posX()+static_cast<int>(camera.width()))) && (y<(camera.posY()+static_cast<int>(camera.height()))) &&
                true
                ){
            if(it.gid){
                if(!it.tile){
                    it.tile = mTileset->tiles()[it.gid];
                }
                it.tile->draw(ren,camera, x, y);
            }
        }
        i++;
    }
}
