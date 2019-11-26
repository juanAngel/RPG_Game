#ifndef SDLTEXTURELOADER_H
#define SDLTEXTURELOADER_H

#include <Graphic/textureloader.h>

class SDLRenderer;

class SDLTextureLoader: public TextureLoader{
        std::shared_ptr<SDLRenderer> mRenderer;
    public:
        SDLTextureLoader(std::shared_ptr<SDLRenderer> renderer);
        virtual std::shared_ptr<Texture> load(const std::string& path);
};

#endif // SDLTEXTURELOADER_H
