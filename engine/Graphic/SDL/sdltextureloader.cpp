#include "sdltextureloader.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <Graphic/SDL/sdlrenderer.h>
#include <Graphic/SDL/sdltexture.h>

SDLTextureLoader::SDLTextureLoader(std::shared_ptr<SDLRenderer> renderer):mRenderer(renderer){
}

std::shared_ptr<Texture> SDLTextureLoader::load(const std::string &path){
    auto already_loaded = textures.find(path);
    if (already_loaded != textures.end()) {
        return already_loaded->second;
    }

    auto surf = IMG_Load(path.c_str());
    if (!surf) {
        std::cerr << "ERROR: failed to load " << path << ": "
                << IMG_GetError() << "\n";
        return nullptr;
    }

    auto tex = SDL_CreateTextureFromSurface(mRenderer->renderer(), surf);
    if (!tex) {
        std::cerr << "ERROR: failed to create texture: "
                 << SDL_GetError() << "\n";
    }
    auto t = std::shared_ptr<Texture>(new SDLTexture(tex));

    textures.insert(std::pair<std::string, std::shared_ptr<Texture> >(path, t));

    return t;

}
