#ifndef RENDER_H
#define RENDER_H

class Rect;
class Texture;
class Camera;



class Renderer{
    private:
//        Camera* mCamera;
    public:
        Renderer();
//        Renderer(Camera* camera);
        virtual ~Renderer();
        virtual void copy(const Texture& texture, const Rect& srcrect, const Rect& dstrect) = 0;
        virtual void refresh() = 0;
        virtual void clear() = 0;
};

#endif // RENDER_H
