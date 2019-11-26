#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>
#include <memory>

#include <Map/layer.h>
#include <Graphic/drawable.h>

class TextureLoader;
class Tileset;

class Map: public Drawable{
        std::shared_ptr<Tileset> mTileset;
        std::vector<std::shared_ptr<Layer> > mLayers;
    public:
        Map(std::vector<std::shared_ptr<Layer>> layers,std::shared_ptr<Tileset> tileset);
        virtual ~Map();

        void load(const std::string &path,std::shared_ptr<TextureLoader> tl);

        // Drawable interface
        virtual void draw(Renderer &ren, const Camera &camera);
};

#endif // MAP_H
