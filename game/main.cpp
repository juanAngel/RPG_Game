#include <iostream>

#include <Graphic/SDL/sdlengine.h>
#include <Graphic/camera.h>
#include <Manager/inputmanager.h>
#include <Manager/mapmanager.h>

#include <unistd.h>


using namespace std;

class Running:public QuitEventListener{
        bool mRunning;
    public:
        Running() {
            mRunning = true;
        }
        virtual ~Running();

        // QuitEventListener interface
        void operator ()(){

            cout << "QuitEvent" << endl;
            mRunning = false;
        }
        operator bool(){
            return mRunning;
        }
};

int main(){
    shared_ptr<Running> running = shared_ptr<Running>(new Running);
    shared_ptr<Engine> engine = unique_ptr<Engine>(new SDLEngine());
    shared_ptr<Camera> c = engine->createCamera("",0,0,640,480);

    auto input = engine->inputManager();

    std::shared_ptr<Renderer> r = c->renderer();

    input->registerQuitEventListener(running);


    auto mapa = engine->mapManager()->load("/home/juan/RPG_Game/res/level1.tmx",c->textureLoader());

    cout << "Hello World!" << endl;
    while (*running){
        input->handle();
        r->clear();

        mapa->draw(*r,*c);
        r->refresh();
        sleep(1);
    }
    //std::getchar();
    return 0;
}

Running::~Running()
{

}
