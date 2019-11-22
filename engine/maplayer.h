#ifndef MAPLAYER_H
#define MAPLAYER_H

#include "drawable.h"


class MapLayer:Drawable{
    public:
        MapLayer();
        virtual void draw(Renderer* ren, Camera* camera);
};

#endif // MAPLAYER_H
