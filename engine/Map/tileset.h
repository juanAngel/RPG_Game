#ifndef TILESET_H
#define TILESET_H

#include <memory>
#include <map>
#include <vector>
#include <Map/tile.h>

class Tileset{
        std::vector<std::shared_ptr<Tile> > mTiles;
        std::map<unsigned,std::shared_ptr<Terrain> > mTerrain;
        std::map<unsigned,std::shared_ptr<Animation>> mAnimation;
    public:
        Tileset();
        void addTile(std::shared_ptr<Tile> t,unsigned gid){
            if(mTiles.size()<=gid){
                mTiles.resize(gid+1);
            }
            mTiles[gid] = t;
        }
        const std::vector<std::shared_ptr<Tile> > tiles() const
        {
            return mTiles;
        }
        void addTerrain(std::shared_ptr<Terrain> terrain,unsigned gid);
        std::map<unsigned, std::shared_ptr<Terrain> > terrain() const{
            return mTerrain;
        }
        std::map<unsigned, std::shared_ptr<Animation>> animation() const{
            return mAnimation;
        }
};

#endif // TILESET_H
