#ifndef TILE_H
#define TILE_H

#include <Graphic/drawable.h>
#include <Map/terrain.h>
#include <Map/animation.h>
#include <engine.h>


class Tile{
    private:
        unsigned mGid = 0;
        std::shared_ptr<Texture> mTex;
        std::shared_ptr<Terrain> mTerrain;
        std::shared_ptr<Animation> mAnimation;
        Rect rTex;
        //int mPosX = -1,mPosY = -1;
    public:
        Tile();
        Tile(unsigned gid,Rect rTex,std::shared_ptr<Texture> tex);
        Tile(int posX,int posY,Rect rTex,std::shared_ptr<Texture> tex);
        virtual ~Tile();
        virtual void draw(Renderer &ren, const Camera& camera,int posX,int posY);
        virtual bool isVisible(const Camera& camera);


        /*
        int posX() const{
            return mPosX;
        }
        int posY() const{
            return mPosY;
        }
        void setPosX(int posX)
        {
            mPosX = posX;
        }
        void setPosY(int posY)
        {
            mPosY = posY;
        }*/
        std::shared_ptr<Terrain> terrain() const
        {
            return mTerrain;
        }
        void setTerrain(const std::shared_ptr<Terrain> &terrain)
        {
            mTerrain = terrain;
        }
        std::shared_ptr<Animation> animation() const
        {
            return mAnimation;
        }
        void setAnimation(const std::shared_ptr<Animation> &animation)
        {
            mAnimation = animation;
        }
        unsigned gid() const
        {
            return mGid;
        }
};

#endif // TILE_H
