#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP

#include <dlfcn.h>
#include <unistd.h>
#include <cstdlib>

#include "Player.hpp"
#include "../dynamic_libs/IGraphics.hpp"
#include "eGraphicsOption.hpp"
#include "eInput.hpp"

class GameEngine {
    public:
        GameEngine(int width, int height);
        ~GameEngine();
        GameEngine  &operator=(GameEngine const &rhs);
        GameEngine(GameEngine const &src);

        void            runGame(Player *p1, int x_size, int y_size);
        int             getWidth() const;
        int             getHeight() const;
        void            closeDynamicLib();

    private:
        GameEngine();
        IGraphics       *initGraphics(eGraphicsOption option);
        void            dlerror_wrapper();

        int             _width;
        int             _height;
        IGraphics       *_graphics;
        void            *_dl_handle;
};

#endif
