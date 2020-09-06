#include <string>
#include <iostream>

#include <unistd.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "../IGraphics.hpp"

class SfmlGraphics : public IGraphics {
    public:
        SfmlGraphics(int x, int y);
        ~SfmlGraphics();
        void        draw_frame(int size);
        void        draw_snake(int x, int y);
        void        draw_fruit(int x, int y);
        void        draw_score(int score);
        void        delete_self();
        int         getInput();
    private:
        SfmlGraphics();
        const int _SCREEN_WIDTH;
        const int _SCREEN_HEIGHT;

        sf::RenderWindow _window;
};

extern "C" {
    IGraphics *createGraphics(int x, int y);
}