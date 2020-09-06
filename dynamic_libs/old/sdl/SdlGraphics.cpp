#include "SdlGraphics.hpp"

SdlGraphics::SdlGraphics() : _SCREEN_WIDTH(100), _SCREEN_HEIGHT(100) {}

SdlGraphics::SdlGraphics(int x, int y) : _SCREEN_WIDTH(x), _SCREEN_HEIGHT(y) {
    SDL_Init(SDL_INIT_EVERYTHING);
    _window = SDL_CreateWindow("Nibbler", 100, 100, _SCREEN_WIDTH, _SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
}

SdlGraphics::~SdlGraphics() {

    std::cout << "SDL destructor called\n";
    //destroy window
    SDL_DestroyWindow(_window);

    //Quit SDL
    SDL_Quit();
}

void        SdlGraphics::draw_frame(int size) {
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);
    
    SDL_SetRenderDrawColor(_renderer, 81, 136, 165, 255);
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = _SCREEN_WIDTH;
    rect.h = 10;
    SDL_RenderFillRect(_renderer, &rect);
    rect.x = _SCREEN_WIDTH - 10;
    rect.y = 0;
    rect.w = 10;
    rect.h = _SCREEN_HEIGHT;
    SDL_RenderFillRect(_renderer, &rect);
    rect.x = 0;
    rect.y = _SCREEN_HEIGHT - 10;
    rect.w = _SCREEN_WIDTH;
    rect.h = 10;
    SDL_RenderFillRect(_renderer, &rect);
    rect.x = 0;
    rect.y = 0;
    rect.w = 10;
    rect.h = _SCREEN_HEIGHT;
    SDL_RenderFillRect(_renderer, &rect);
    
   /*  SDL_Rect rectn = {200, 200, 10, 10};
    SDL_RenderFillRect(_renderer, &rectn); */
    
    //SDL_RenderPresent(_renderer);

    /* SDL_Rect rectn = {200, 200, 10, 10};
    SDL_RenderFillRect(_renderer, &rectn); */
    
    SDL_RenderPresent(_renderer);
    SDL_PumpEvents();
    SDL_SetWindowSize(_window, _SCREEN_WIDTH, _SCREEN_HEIGHT);
}

void        SdlGraphics::draw_snake(int x, int y) {
    /* SDL_SetRenderDrawColor(_renderer, 81, 136, 165, 255); */
   /*  SDL_Rect rect = {x, y, 10, 10};
    SDL_RenderFillRect(_renderer, &rect);
    SDL_RenderPresent(_renderer); */
}

void        SdlGraphics::draw_fruit(int x, int y) {
    //std::cout << "DL says fruit location:  " << x << ":" << y << std::endl;
}

void        SdlGraphics::draw_score(int score) {
    //std::cout << "DL says score: " << score << std::endl;
}

int         SdlGraphics::getInput() {
    SDL_Event   event;
    int         which_key;
    //which_key = SDL_PollEvent(&event);

    if (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN) {
            switch(event.key.keysym.sym) {
                case SDLK_UP:
                    std::cout << "up\n";
                    return 0;
                case SDLK_DOWN:
                    std::cout << "down\n";
                    return 1;
                case SDLK_LEFT:
                    std::cout << "left\n";
                    return 2;
                case SDLK_RIGHT:
                    std::cout << "right\n";
                    return 3;
                case SDLK_F1:
                    std::cout << "f1\n";
                    return 4;
                case SDLK_F2:
                    std::cout << "f2\n";
                    return 5;
                case SDLK_F3:
                    std::cout << "f3\n";
                    return 6;
                case SDLK_ESCAPE:
                    std::cout << "escape\n";
                    return 8;

                //no_change
                default:
                    return 7;
            }
        }
    }
    return 7;
}


void        SdlGraphics::delete_self() {
    delete this;
}

IGraphics     *createGraphics(int x, int y) {
    return new SdlGraphics(x, y);
}