#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#include <Graphic/texture.h>
#include <Graphic/renderer.h>
#include <iostream>

#include <map>
#include <memory>


class TextureLoader{
    protected:
        std::map<std::string, std::shared_ptr<Texture> > textures;
    public:
        TextureLoader();
        virtual ~TextureLoader();
        virtual std::shared_ptr<Texture> load(const std::string& path) = 0;
};

#endif // TEXTURELOADER_H
