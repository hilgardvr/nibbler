#include <string>
#include <iostream>

#include <unistd.h>
#include <SDL.h>

#include "../IGraphics.hpp"

class SdlGraphics : public IGraphics {
    public:
        SdlGraphics(int x, int y);
        ~SdlGraphics();
        void        draw_frame(int size);
        void        draw_snake(int x, int y);
        void        draw_fruit(int x, int y);
        void        draw_score(int score);
        void        delete_self();
        int         getInput();
    private:
        SdlGraphics();
        const int _SCREEN_WIDTH;
        const int _SCREEN_HEIGHT;
        SDL_Window  *_window;
        SDL_Renderer *_renderer;
        SDL_Surface *_screenSurface;
};

extern "C" {
    IGraphics *createGraphics(int x, int y);
}