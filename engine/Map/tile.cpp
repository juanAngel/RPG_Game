#include "tile.h"






Tile::Tile():rTex(0,0,0,0){

}

Tile::Tile(unsigned gid, Rect rTex, std::shared_ptr<Texture> tex):rTex(rTex){
    mTex = tex;
    mGid = gid;
}
/*
Tile::Tile(int posX, int posY, Rect rTex, std::shared_ptr<Texture> tex):Tile(rTex,tex){
    mPosX = posX;
    mPosY = posY;
    mTex = tex;
}*/
Tile::~Tile()
{
    
}

void Tile::draw(Renderer& ren, const Camera& camera, int posX, int posY){
    Rect rCamera(posX-camera.posX(),
                 posY-camera.posY(),
                 rTex.w(),
                 rTex.h());

    ren.copy(*mTex,rTex,rCamera);
}

bool Tile::isVisible(const Camera &camera){

}
