#include "drawable.h"

Drawable::Drawable()
{

}

Drawable::~Drawable()
{

}

bool Drawable::isVisible(const Camera &camera){
    (void)camera;
    return true;
}
